#include "Singleton.h"
#include <iostream>
Singleton* Singleton::m_instance = nullptr;
/*Singleton* Singleton::get_instance()
{
	if (m_instance == nullptr)
		m_instance = new Singleton;
	return m_instance;
	
}*/
Singleton& Singleton::get_instance()
{
	static Singleton s;
	static int i = 0;
	i++;
	std::cout << i << std::endl;
	return s;
}
Singleton::Singleton()
{
	std::cout << "cstr";
}