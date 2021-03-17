#include <iostream>
#include "Singleton.h"
using namespace std;
int main()
{
/*	Singleton *s=Singleton::get_instance();
	Singleton* s1 = Singleton::get_instance();
	Singleton* s2 = Singleton::get_instance();*/
	Singleton& s1 = Singleton::get_instance();
	Singleton& s2 = Singleton::get_instance();
	Singleton& s3 = Singleton::get_instance();
	return 0;
}