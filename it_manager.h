#pragma once

#include"employee.h"
class it_manager:public employee
{
	


public:
	it_manager() {};
	it_manager(const char name[], int age, int id, const char password[], int employee_no) :employee(name, age,id,password, employee_no){}

	void change_password()
	{
		person::change_password();
	}
	void change_userid()
	{
		person::change_loginid();
	}
	
	~it_manager()
	{

	}


};