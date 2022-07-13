#pragma once
#include<iostream>
using namespace std;
class student;
class courses;
class registration
{
	float gpa;
	int attendance;
	float marks;
	char grade;
	student* s;
	courses* c;
	
public:
	registration(student* stu, courses* cour);

	registration(float gpa, int attendance, float marks, char grade);

	void assign_gpa(float x);

	void assign_marks(float x);

	void assign_grade(char x);

	void assign_attendance(int x);

	void print_grade();

	void add_marks(float x);

	void mark_attendance();
	
	void print_attendance();

	courses* get_course();
	
	void marks_view();

	float get_gpa();

	int get_attendance();

	float get_marks();

	char get_grade();

	void print_registration();
	
	~registration();

};
