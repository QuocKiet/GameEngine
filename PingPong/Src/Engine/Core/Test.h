#pragma once
#include "SingleTon.h"

class Test : public Singleton<Test>
{
public:
	Test();
	~Test();
	void Get()
	{
		printf("SingleTon\n");
	}
};

