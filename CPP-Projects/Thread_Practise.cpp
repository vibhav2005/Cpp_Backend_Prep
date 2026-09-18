//task 1-> create 2 thread and print msg
/*#include <thread> 
#include <iostream>
#include <string>
using namespace std;
void task_1(){

    for(int i  = 0 ; i < 5 ; i++){
    cout<<"task 1 ongoing "<<endl;
    }
}
void task_2(){
    for(int i = 0 ; i < 2 ; i++){
    cout<<"task 2 ongoing "<<endl;
    }
}
int main(){

    thread t1(task_1);
    thread t2(task_2);

    t1.join();
    t2.join();

    return 0;
}*/

//task-2 Give daata to thread
/*
#include <thread> 
#include <iostream>
#include<vector>
using namespace std;
void func(vector<int>& n){
    int sum = 0;
    for(int i = 0 ; i < n.size();i++){
        sum +=n[i];
    }
    cout<< sum<<"\n";
}

int main(){
    vector<int> a = { 10 , 20 , 30 , 40};
    thread t1(func, ref(a));
    t1.join();
    return 0;
}*/

//task - 3 return a value from thread
/*
#include <thread> 
#include <iostream>
#include<vector>
#include <future>
using namespace std;
void func(vector<int>& n , promise<int>& p){
    int sum = 0;
    for(int i = 0 ; i < n.size();i++){
        sum +=n[i];
    }
    p.set_value(sum);
}

int main(){
    vector<int> a = { 10 , 20 , 30 , 40};

    promise<int> promise;
    future<int> future = promise.get_future();

    thread t1(func, ref(a) , ref(promise));
    int out = future.get();
    cout<<out<<"\n";
    t1.join();
    return 0;
}*/


//task - 4-5 race condition and synchronisation tested both lock_guard and unique_lock 2 task done 
/*#include <thread> 
#include <iostream>
#include <vector>
#include <mutex>

using namespace std;
static int counter = 0 ;
mutex func_mutex;
void func(int j){
    
    unique_lock<mutex> lock(func_mutex , defer_lock);
    lock.lock();
    for(int i = 0 ; i< 10;i++){
      
        counter++;
      
        cout<<"counter curr val by "<<j<<" thread :"<<counter<<endl;
    }
    lock.unlock();
    
}

int main(){
    thread t1(func , 1);
    thread t2(func , 2);


    t1.join();
    t2.join();

    
    return 0;
}
*/