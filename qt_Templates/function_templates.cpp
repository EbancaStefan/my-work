#include <iostream>
#include <string>
using std::cout;


class Coin{
public:
    Coin(int v = 0, std::string mat="", float w = 0):m_value{v}, m_material{mat}, m_weight{w}{}

    bool operator<(const Coin& other){
        return m_value < other.m_value;
    }
    friend bool operator>(const Coin &c1, const Coin &c2);

    void print(){std::cout<<"Coin of value "<<m_value<<" made of "<<m_material<<" with weight "<<m_weight<<std::endl;}
private:
    int m_value;
    std::string m_material;
    float m_weight;
};

bool operator>(const Coin &c1, const Coin &c2){
    return c1.m_value > c2.m_value;
}


template<typename T>
T minVal(T v1, T v2){
    if(v1 < v2)
        return v1;
    return v2;
}

template<class T>
T maxVal(T v1, T v2){
    if(v1 > v2)
        return v1;
    return v2;
}

template <class T>
T averageT(T *array, int length)
{
    T sum(0);
    for (int count{ 0 }; count < length; ++count)
        sum += array[count];

    sum /= length;
    return sum;
}

template <class T, typename U>
U average(T *array, int length)
{
    U sum(0);
    for (int count{ 0 }; count < length; ++count)
        sum += array[count];

    sum /= length;
    return sum;
}

int main(){
    float f1 = 10, f2 = 0.5;
    int i1 = 3, i2 = 4;
    Coin c1{10, "steel-nickel", 30};
    Coin c2{50, "copper-nickel", 60};

    float maxF1F2 = maxVal<float>(f1, f2);
    float minF1F2 = minVal<float>(f1, f2);


    int maxI1I2 = maxVal<int>(i1, i2);
    int minI1I2 = minVal<int>(i1, i2);


    Coin maxC1C2 = maxVal(c1, c2);
    Coin minC1C2 = minVal(c1, c2);

    cout<<"i1 = "<<i1<<"; i2 = "<<i2<<std::endl;
    cout<<"\t"<<"Maximum value is "<<maxI1I2<<std::endl;
    cout<<"\t"<<"Minimum value is "<<minI1I2<<std::endl;


    cout<<"f1 = "<<f1<<"; f2 = "<<f2<<std::endl;
    cout<<"\t"<<"Maximum value is "<<maxF1F2<<std::endl;
    cout<<"\t"<<"Minimum value is "<<minF1F2<<std::endl;


    c1.print();
    c2.print();
    cout<<"\t"<<"Maximum value is ";
    maxC1C2.print();
    cout<<"\t"<<"Minimum value is ";
    minC1C2.print();

    getchar();
    int array1[]{ 4, 3, 2, 1, 4 };
    std::cout << "array 1: averageT "<<averageT(array1, 5) << '\n';

    getchar();

    double array2[]{ 3.12, 3.45, 9.23, 6.34 };
    std::cout << "array 1: average "<<average<int, double>(array1, 5) << '\n';
    std::cout << "array 2: average: "<<average<double, double>(array2, 4) << '\n';


    return 0;
}
