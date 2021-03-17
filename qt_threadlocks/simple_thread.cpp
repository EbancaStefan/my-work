//#include <iostream>
//#include <thread>
//#include <string>
//using namespace std;

//void task1(string msg)
//{
//    std::thread::id tid = std::this_thread::get_id();
//    _sleep(2000);
//    cout << "Thread "<<tid<<" says: " << msg<<endl;

//}

//int main()
//{
//    // Constructs the new thread and runs it. Does not block execution.
//    //task1("hello");
//    thread t1(task1, "Hello");

//    std::thread::id mainTid = std::this_thread::get_id(); // get the thread is
//    cout<<"Main thread "<<mainTid<<" says: hello!"<<endl;

//    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
//    t1.join();
//    return 0;
//}
