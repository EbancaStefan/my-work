//#include <iostream>
//#include <thread>
//#include <string>
//#include <vector>
//using namespace std;

//void threadFunction(string msg, int threadIndex)
//{
//    std::thread::id tid = std::this_thread::get_id();
//    _sleep(100);
//    cout << "Thread "<<tid<<" says: " << msg<<" It has index: "<<threadIndex<<endl;
//}

//int main()
//{
//    std::vector<thread> threads;

//    for(int i = 0; i < 10; i++){
//        thread t(threadFunction, "Hello", i);
//        threads.push_back(std::move(t));
//    }

//    std::thread::id mainTid = std::this_thread::get_id();
//    cout<<"Main thread "<<mainTid<<" says: hello!"<<endl;

//    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
//    for(int i = 0; i < 10; i++){
//       threads[i].join();
//    }
//    return 0;
//}
