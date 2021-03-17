//// Rvalues.cpp : This file contains the 'main' function. Program execution begins and ends there.
////

//#include <iostream>
//#include <thread>
//#include <vector>
//#include <mutex>
//using namespace std;
////shared by all the threads
//int g_value;

//std::mutex g_i_mutex;  // protects g_value
//void incrementCorrectly() {
//    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
//    //  lock_guard is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex for the duration of a scoped block
//    const std::lock_guard<std::mutex> lock(g_i_mutex);
//    g_value = 2 * g_value;

//    std::cout << std::this_thread::get_id() << ": " << g_value << '\n';

//    // g_i_mutex is automatically released when lock
//    // goes out of scope
//}

//void increment() {
//    std::this_thread::sleep_for(std::chrono::milliseconds(rand()%100));
//    g_value = 2*g_value ;
//    //std::cout << std::this_thread::get_id() << ": " << g_value << '\n';
//}

//int main()
//{
//    g_value = 1;
//    int numThreads = 10;
//    std::vector<thread> threads;
//    for (int i = 0; i < numThreads; i++) {
//        thread th(incrementCorrectly);
//        threads.push_back(std::move(th));
//    }

//    for (int i = 0; i < numThreads; i++) {
//        threads[i].join();
//    }

//    std::cout << "The value of g_value is now: "<<g_value;
//}

