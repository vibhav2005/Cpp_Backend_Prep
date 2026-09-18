#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <future>
#include <vector>
#include <type_traits>
#include <utility>
#include <chrono>

using namespace std;

class TaskQueue {
private:
    queue<function<void()>> tasks;
    mutex queue_mutex;
    condition_variable queue_condition;
    bool stop = false;

public:
    void add_task(function<void()> task) {
        {
            lock_guard<mutex> lock(queue_mutex);
            if (stop) return;
            tasks.push(move(task));
        }
        queue_condition.notify_one();
    }

    bool get_task(function<void()>& task) {
        unique_lock<mutex> lock(queue_mutex);
        queue_condition.wait(lock, [this] {
            return stop || !tasks.empty();
        });

        if (tasks.empty()) return false;

        task = move(tasks.front());
        tasks.pop();
        return true;
    }

    void shutdown() {
        {
            lock_guard<mutex> lock(queue_mutex);
            stop = true;
        }
        queue_condition.notify_all();
    }
};

class ThreadPool {
private:
    TaskQueue task_queue;
    vector<thread> workers;

    void worker_loop() {
        while (true) {
            function<void()> task;
            if (!task_queue.get_task(task)) {
                break;
            }
            task();
        }
    }

public:
    explicit ThreadPool(size_t num_threads = max<size_t>(1, thread::hardware_concurrency())) {
        for (size_t i = 0; i < num_threads; ++i) {
            workers.emplace_back(&ThreadPool::worker_loop, this);
        }
    }

    template <typename F, typename... Args>
    auto submit(F&& f, Args&&... args) -> future<invoke_result_t<F, Args...>> {
        using ReturnType = invoke_result_t<F, Args...>;

        auto task = make_shared<packaged_task<ReturnType()>>(
            bind(forward<F>(f), forward<Args>(args)...)
        );

        future<ReturnType> result = task->get_future();
        task_queue.add_task([task]() {
            (*task)();
        });

        return result;
    }

    ~ThreadPool() {
        task_queue.shutdown();
        for (auto& worker : workers) {
            if (worker.joinable()) {
                worker.join();
            }
        }
    }
};

int main() {
    ThreadPool pool(3);

    auto future1 = pool.submit([](int a, int b) {
        this_thread::sleep_for(chrono::milliseconds(200));
        return a + b;
    }, 10, 20);

    auto future2 = pool.submit([](int x) {
        this_thread::sleep_for(chrono::milliseconds(100));
        return x * x;
    }, 7);

    cout << "Result 1: " << future1.get() << endl;
    cout << "Result 2: " << future2.get() << endl;

    return 0;
}
