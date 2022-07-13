#pragma once
#include"department.h"
class university
{
	char* name;
	department** d;
	int count;
public:
	university(const char name[]);
	
	template <class a>
	void grow(a**& x, int& num);
	
	void add_department();
	
	department* get_department(int x);
	
	void print_uniname();
	

	~university();
	
};
