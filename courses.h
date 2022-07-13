#pragma once

class TA;
#include"registration.h"
class courses
{
	int course_code;
	char* name;
	int credit_hour;
	TA* ta;
	registration** r= new registration*[50];
	int curr_reg;
public:
	
	courses(){}
	courses(int course_code, const char name[], int credit_hours);
	
	void set_currreg(int x);
	
	void assign_ta(TA* t);
	
	void print_course();
	
	void add_reg(registration* reg);
	
	void un_reg(registration* reg);
	
	void view_attendance();
		
	void course_mark_attendance();
	
	int get_coursecode();
	
	char* get_course_name();
	
	int get_credit_hour();
	
	int get_curr_reg();
	
	~courses();
	

};
