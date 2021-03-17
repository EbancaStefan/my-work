//#include <assert.h>
//#include <iostream>
//using namespace std;


//template <class T>
//class Array
//{
//private:
//    int m_length;
//    T *m_data;

//public:
//    Array()
//    {
//        m_length = 0;
//        m_data = nullptr;
//    }

//    Array(int length)
//    {
//        m_data = new T[length];
//        m_length = length;
//    }

//    ~Array()
//    {
//        delete[] m_data;
//    }

//    void Erase()
//    {
//        delete[] m_data;
//        // always set to nullptr after memory free!!!
//        m_data = nullptr;
//        m_length = 0;
//    }


//    T& operator[](int index)
//    {
//        assert(index >= 0 && index < m_length);
//        return m_data[index];
//    }

//    int getLength(); // templated getLength() function defined below
//};

//// notice: Array<T>:: instead of Array:: as we normaly write
//template <typename T>
//int Array<T>::getLength() { return m_length; } // member functions defined outside the class need their own template declaration

//int main(){
//    Array<int> intArray(12);
//    Array<double> doubleArray(12);

//    for (int idx = 0; idx < intArray.getLength(); ++idx)
//    {
//        intArray[idx] = idx;
//        doubleArray[idx] = idx*2 + idx/10.0;
//    }

//    for (int count = intArray.getLength()-1; count >= 0; --count)
//        std::cout << intArray[count] << "\t" << doubleArray[count] << '\n';

//    return 0;
//}
