//#include <iostream>
//using namespace std;

//#define MOVE_SEMANTICS 0
//class Resource
//{
//public:
//    Resource() { std::cout << "Resource acquired\n"; }
//    ~Resource() { std::cout << "Resource destroyed\n"; }
//};
//// RAII - resoarce allocations is initialization
//class SmartPointer
//{
//    Resource* m_ptr;
//public:
//    SmartPointer(Resource* ptr = nullptr)
//        :m_ptr(ptr)
//    {}

//    ~SmartPointer()
//    {   delete m_ptr; }

//    // Copy constructor
//    // Do deep copy of a.m_ptr to m_ptr
//    SmartPointer(const SmartPointer& a) //copy constructor (must have a const referece to an object of the same type)
//    {
//        m_ptr = new Resource; //calling the constructor of resource
//        *m_ptr = *a.m_ptr;
//    }

//    // Copy assignment
//    // Do deep copy of a.m_ptr to m_ptr
//    SmartPointer& operator=(const SmartPointer& a)
//    {
//        // Self-assignment detection
//        if (&a == this)
//            return *this;

//        // Release any resource we're currently holding
//        delete m_ptr;

//        // Copy the resource
//        m_ptr = new Resource;
//        *m_ptr = *a.m_ptr;

//        return *this;
//    }


//    Resource& operator*() const { return *m_ptr; }
//    Resource* operator->() const { return m_ptr; }
//    bool isNull() const { return m_ptr == nullptr; }

////not for exam I think
//#if MOVE_SEMANTICS == 1
//    // Move constructor
//    // Transfer ownership of a.m_ptr to m_ptr
//    SmartPointer(SmartPointer&& a)
//        : m_ptr(a.m_ptr)//stealing the resource of object a
//    {
//        a.m_ptr = nullptr; // why?
//        // When “a” goes out of scope, a’s destructor will be called, and a.m_ptr will be deleted. If at that point, a.m_ptr is still pointing to the same object as m_ptr, then m_ptr will be left as a dangling pointer.
//        // When the object containing m_ptr eventually gets used (or destroyed), we’ll get undefined behavior.
//    }


//    // Move assignment
//    // Transfer ownership of a.m_ptr to m_ptr
//    SmartPointer& operator=(SmartPointer&& a)
//    {
//        // Self-assignment detection
//        if (&a == this)
//            return *this;

//        // Release any resource we're holding
//        delete m_ptr;

//        // Transfer ownership of a.m_ptr to m_ptr
//        m_ptr = a.m_ptr;
//        a.m_ptr = nullptr; // why?

//        return *this;
//    }
//#endif

//};


//SmartPointer getResource()
//{
//    SmartPointer res(new Resource);//invoked the constructor of the resource
//    return res; //here is the copy constructor called (here 2nd resource acquired)
//}

//int main()
//{
//    SmartPointer mainres;
//    mainres = getResource();

//    return 0;
//}
