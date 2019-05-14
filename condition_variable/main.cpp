#include <iostream>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <vector>

using namespace std;

mutex mtx;
bool flag = false;
condition_variable conv;

void thread_function(int i) {
    // 等待命令
//    cout << "I'm " << i << " thread pass" << endl;
//    while(!flag);
    unique_lock<mutex> lock1(mtx);
    cout << "I'm " << i << " thread pass" << endl;
    conv.wait(lock1);
    cout << "I'm " << i << " thread!!" << endl;
}
void go() {
    unique_lock<mutex> lock1(mtx);
    cout << "go!!!"<<endl;
    flag = true;
//    mtx.unlock();
    conv.notify_all();
    usleep(10000);
}

void thread_func() {
    int i=0;
    while(1) {
        cout << i++ <<endl;
        try {
            sleep(0.01);
        } catch (exception e) {
            break;
        }

    }
    cout << "end" << endl;
    return;;
}

int main() {
//    thread threads[10];
//    for (int i = 0; i < 10; ++i) {
//        threads[i] = std::thread(thread_function, i);
//    }
//    usleep(1000);
//    go();
//    for (int j = 0; j < 10; ++j) {
//        threads[j].join();
//    }
//    return 0;

    thread thr(thread_func);

    usleep(1000);

    thr.join();

    return 0;
}