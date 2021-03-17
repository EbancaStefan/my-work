//#include <iostream>

//#include <iostream>
//using namespace std;

//// class template: "base" template
//template <class T>
//class DummyContainer {
//    T m_element;
//public:
//    DummyContainer (T arg) {m_element=arg;}
//    T increase () {return ++m_element;}

//    T element() const {return m_element;}
//};

//// class template specialization:
//template <>
//class DummyContainer <char> {
//    char m_element;
//public:
//    DummyContainer (char arg) {m_element=arg;}
//    char increase ()
//    {
//        if ((m_element >='a')&&(m_element<='z'))
//            m_element+='A'-'a';
//        return m_element;
//    }
//    char element() const {return m_element;}
//};

//int main () {
//    DummyContainer<int> intV (7);
//    DummyContainer<char> charV ('a');
//    cout <<intV.element();
//    cout<<"->increased int="<<intV.increase() << endl;
//    cout << charV.element();
//    cout<< "->increased char="<<charV.increase() << endl;
//    return 0;
//}

