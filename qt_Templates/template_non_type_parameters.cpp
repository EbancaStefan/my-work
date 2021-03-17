//#include <iostream>

//template <class T, int size> // size is the non-type parameter
//class StaticArray
//{
//private:
//    // The non-type parameter controls the size of the array
//    T m_array[size];

//public:
//    T* getArray(){return m_array;}

//    T& operator[](int index)
//    {
//        return m_array[index];
//    }
//};


//int main(){

//    const int sz = 10;
//    // declare an integer array with room for sz integer
//    StaticArray<int, 10> intArray;

//    for (int idx=0; idx < sz; ++idx)
//        intArray[idx] = idx;

//    for (int idx=sz - 1; idx >= 0; --idx)
//        std::cout << intArray[idx] << " ";
//    std::cout << '\n';

//    // declare a double buffer with room for 4 doubles
//    StaticArray<double, 4> doubleArray;

//    for (int idx=0; idx < 4; ++idx)
//        doubleArray[idx] = idx + 0.5;

//    for (int idx=0; idx < 4; ++idx)
//        std::cout << doubleArray[idx] << ' ';
//    std::cout << '\n';
//    return 0;
//}
