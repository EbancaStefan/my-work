#pragma once
class Singleton
{
public:
	//static Singleton* get_instance();
	static Singleton& get_instance();
private:
	Singleton();
	static Singleton* m_instance;
};

