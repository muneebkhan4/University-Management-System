#pragma once

#include"student.h"
#include"teacher.h"
class TA :virtual public student, virtual public teacher
{
	courses* cour;


public:
	TA() {}
	TA(const char name[], int age, int id, const char password[], int employee_no, int roll_no, courses* c) :student(name, age, id, password, roll_no), teacher(name, age, id, password, employee_no), person(name, age, id, password)
	{
		cour = c;
	}

	void change_password()
	{
		person::change_password();
	}
	void change_userid()
	{
		person::change_loginid();
	}
	~TA()
	{
		cour = 0;
	}
};