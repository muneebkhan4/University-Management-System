#pragma once
#include<iostream>
using namespace std;
#include"person.h"
class employee :public person
{
	int employee_no;


public:
	employee();

	employee(const char name[], int age, int id, const char password[], int employee_no) :person(name, age, id, password)
	{
		this->employee_no=employee_no;
	}
	
	int get_employee();
	
	void print_employee();
	
	~employee();
	
};