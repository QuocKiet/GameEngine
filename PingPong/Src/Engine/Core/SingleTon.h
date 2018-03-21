#pragma once
#include <stdio.h>
template <typename T>

class Singleton
{
public:

	static T& Instance()
	{
		if (Singleton::_instance == 0)
		{
			Singleton::_instance = new T;;
		}
		return *(Singleton::_instance);
	}

protected:
	virtual ~Singleton()
	{
		if (Singleton::_instance != 0)
		{
			delete Singleton::_instance;
		}
		Singleton::_instance = 0;

	}
	explicit Singleton()
	{

	}

private:
	static T* _instance;
	//static T* CreateInstance();
};

template<typename T>
T* Singleton<T>::_instance = 0;






