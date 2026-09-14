/*Thread-Safe Task Queue
Your objective

Build a program with:

2–3 producer threads
2–3 worker threads
One shared task queue
Producers add tasks
Workers wait for tasks and execute them
Safe access to the queue
Graceful shutdown*/

#include <thread>
#include <mutex>
#include <iostream>
#include <queue>
#include <condition_variable>
#include <vector>
#include <chrono>


using namespace std;

class TaskQueue {
    private:
        std::queue<int> task_queue;
        std::mutex queue_mutex;
        std::condition_variable queue_condition;
        bool stop = false;
    public:
        void add_task(int task);
        bool get_task(int& task);
        void shutdown();
};


void TaskQueue:: add_task(int task){
    {
        lock_guard<mutex> lock(queue_mutex);
        if (stop) {
            return;
        }
        task_queue.push(task);
        std::cout << "Producer Added task: " << task << "\n";
    }
    queue_condition.notify_one();
};

bool TaskQueue:: get_task(int& task){
        std::unique_lock<std::mutex> lock(queue_mutex);

        queue_condition.wait(lock, [this] {
            return stop || !task_queue.empty();
        });

        if (task_queue.empty()) {
            return false;
        }

        int current_task = task_queue.front();
        task_queue.pop();
        task = current_task;
        return true;
 };

void TaskQueue:: shutdown(){
    {
    lock_guard<mutex> lock(queue_mutex);
    stop = true;
    }
    queue_condition.notify_all();

};


//main threading application functions start here 
mutex id_mutex;
int next_task_id = 1;

int get_next_id(){
    lock_guard<mutex> lock(id_mutex);
    return next_task_id++ ;
}

void Producer(TaskQueue& queue , int task_count_per_producer){
    for(int i = 0 ; i < task_count_per_producer ; i ++){
        int task_id = get_next_id();
        queue.add_task(task_id);
        this_thread:: sleep_for(chrono::milliseconds(200));
    }
}
void Worker(TaskQueue& queue){
    while(true){
        int task ;
        bool ok = queue.get_task(task);
        if(!ok){
            break;
        }
        cout<<"Worker processed task :"<<task<<"\n";
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

int main(){

    TaskQueue queue_1;
    vector<thread> producers;
    vector<thread> workers;
    for(int i = 0 ; i < 3 ; i ++){
        producers.emplace_back(Producer , ref(queue_1) , 3);
    }
    for(int i = 0 ; i < 3 ; i++){
        workers.emplace_back(Worker , ref(queue_1));
    }


    for(auto& p : producers){
        p.join();
    }

    queue_1.shutdown();
    for(auto& w : workers){
        w.join();
    }


    
    return 0;
}