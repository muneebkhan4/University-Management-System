#pragma once
#include<iostream>
using namespace std;
#include"employee.h"
#include"courses.h"

class teacher :virtual public employee
{
	courses** course;
	int total_courses;
	static int total_teacher;

public:
	
	teacher()
	{
		course = 0;
		total_courses = 0;
	}
	teacher(const char name[], int age, int id, const char password[], int employee_no) :employee(name, age, id, password, employee_no)
	{
		course = 0;
		total_courses = 0;
	}

	template <class a>
	void grow(a**& x, int& num);
	
	int get_employeeno();

	void change_password();

	void change_userid();
	
	void set_courses_array(courses** c, int num);
	
	void assign_course(courses* c);
	
	void print_teacher();
	
	int get_login_id();

	char* getteacher_password();

	void print_courses();

	void change_teacher_password();

	courses** get_courses_ofteacher();

	int get_curr_courses_ofteacher();

	courses* get_course(int x);
	
	~teacher();
	

};
