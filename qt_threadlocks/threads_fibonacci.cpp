//#include <iostream>
//#include <thread>
//#include <future>         // std::async, std::future
//using namespace std;

//#include <chrono>
//using namespace std::chrono;

//long fib(long n) {
//    if (n < 2)
//        return n;
//    else
//        return fib(n - 1) + fib(n - 2);
//}


//int main(){

//    long num = 30;
//    auto start = high_resolution_clock::now();
////    long fibValue1 = fib(num);
////     cout<<"Fib value is: "<<fibValue1<<endl;

//    auto end = high_resolution_clock::now();

//    int number;
//    cout<<"Hey user! Give me a number "<<endl;
//    //cin>>number;

//    // instead of a thread we can use std::async to get the result from the thread
//    // std::async (fn, args...);
//    //    Calls fn (with args as arguments) at some point, returning without waiting for the execution of fn to complete.
//    //    The value returned by fn can be accessed through the future object returned (by calling its member future::get).
//    std::future<long> future = std::async (fib, num);
//    long fibValue = future.get();
//    cout<<"Fib value is: "<<fibValue<<endl;

//    auto duration = duration_cast<milliseconds>(end - start);
//    cout<<"Execution time for computing the "<<num<<"th element in the Fibonacci term is: "<<duration.count()<<" milliseconds"<<endl;
//    return 0;
//}
