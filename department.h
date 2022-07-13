#pragma once
#include<iostream>
using namespace std;
#include"courses.h"
#include"teacher.h"
#include"it_manager.h"
#include"student.h"
class department
{
	char name[50];
	courses** c;
	int curr_courses;
	teacher** teachers;
	int curr_teacher;
	teacher* hod;
	it_manager* it;
	student** students;
	int curr_student;
public:
	department();

	void add_teacher_array(teacher** tea, int total_tea);

	void add_student_array(student** stu, int total);

	template <class a>
	void grow(a**& x, int& num);

	template <class a>
	void shrink(a**& x, int index, int& num);

	teacher* get_hod();

	void add_student(student* s);

	void remove_student(int student_id);

	void add_teacher(teacher* tea);

	void remove_teacher(int teacher_id);

	teacher** get_teacher_array();

	void assign_coursetoteacher(int employee_id, int coursecode);

	void register_courseforstudent(int course_code, int student_id);

	void unregister_courseforstudent(int course_code, int student_id);

	void mark_attendance(int course_code);

	void view_attendanceofallstudents(courses* c);

	void assign_marks(courses* course);

	void assign_gpa(courses* course);

	void view_evaluationReport(courses* c);

	void assign_grade(courses* c);

	void view_grades(int course_code);

	void change_studentid(int student_id);

	void change_studentpassword(int student_id);

	void change_teacherid(int teacher_id);

	void change_teacherpassword(int teacher_id);

	char* get_department_name();

	int get_department_total_courses();

	courses** get_department_courses();

	int get_itmanager_id();

	char* get_itmanager_password();

	char* get_itmanager_name();

	int get_itmanager_age();

	int get_itmanager_employee_id();

	it_manager* get_it_manager();

	~department();

};