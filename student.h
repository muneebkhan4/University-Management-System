#pragma once
#include<iostream>
using namespace std;
#include"person.h"
#include"registration.h"
class student :virtual public person
{
	int roll_no;
	registration** r=new registration*[5];
	int curr_reg;
	
public:
	student()
	{
		roll_no = 0;
		r = 0;
		curr_reg=0;
	}
	student(const char name[], int age, int id, const char password[], int roll):person(name, age, id, password)
	{
		roll_no = roll;
		curr_reg = 0;
	}
	void registration_list(registration **reg,int num)
	{
		curr_reg = num;
		for (int i = 0; i < num; i++)
		{
			r[i] = reg[i];
		}
	}
	int get_curr_registration()
	{
		return curr_reg;
	}
	int get_roll_no()
	{
		return roll_no;
	}
	registration** get_registration_list()
	{
		return r;
	}

	void change_student_password()
	{
		person::change_password();
	}
	void change_userid()
	{
		person::change_loginid();
	}
	void register_course(courses* c)
	{
		if (curr_reg < 5)
		{
			r[curr_reg] = new registration(this, c);
			c->add_reg(r[curr_reg]);
			cout << "Course registered successfully." << endl;
			curr_reg++;
		}
		else
			cout << "No more course can be registered." << endl;
	}
	courses* get_course(int serial_no)
	{
		return r[serial_no - 1]->get_course();
	}

	void unregister_course(courses*c)
	{
		int flag = 1;
		for (int i = 0; i < curr_reg; i++)
		{
			if (r[i]->get_course()->get_coursecode() == c->get_coursecode())
			{
				c->un_reg(r[i]);
				cout << "Course unregistered successfully." << endl;
				for (int j = i; j < curr_reg-1; j++)
				{
					r[j] = r[j + 1];
				}
				r[curr_reg - 1] = 0;
				curr_reg--;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			cout << "This course is already not registered for this student." << endl;
		}
	}
	void drop_course(courses* c)
	{
		int flag = 1;
		for (int i = 0; i < curr_reg; i++)
		{
			if (r[i]->get_course()->get_coursecode() == c->get_coursecode())
			{
				r[i]->assign_grade('W');
				cout << "Course withdraw and 'W' grade has been assigned successfully." << endl;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			cout << "This course is already not registered for this student." << endl;
		}
	}


	void print_registered_courses()
	{
		for (int i = 0; i < curr_reg; i++)
		{
			cout << i + 1 << ")     ";
			r[i]->get_course()->print_course();
		}
	}


	void print_student()
	{
		person::print();
		cout << "Roll NO. :  " << roll_no << endl;
	}
	void view_attendance(courses* c)
	{
		for (int i = 0; i < curr_reg; i++)
		{
			if (r[i]->get_course()->get_coursecode() == c->get_coursecode())
			{
				r[i]->print_attendance();
			}
		}
	}
	void assign_gpa(int course_code,float gpa)
	{
		for (int i = 0; i < curr_reg; i++)
		{
			if (r[i]->get_course()->get_coursecode() == course_code)
			{
				r[i]->assign_gpa(gpa);
			}
		}
	}
	bool search_course_code(int course_code)
	{
		for (int i = 0; i < curr_reg; i++)
		{
			if (r[i]->get_course()->get_coursecode() == course_code)
			{
				return 1;
			}
		}
		return 0;
	}

	void mark_attendance(int course_code)
	{
		for (int i = 0; i < curr_reg; i++)
		{
			if (r[i]->get_course()->get_coursecode() == course_code)
			{
				r[i]->mark_attendance();
			}
		}
	}
	void get_name()
	{
		person::print_name();
	}
	void assign_marks(int course_code, float marks)
	{
		for (int i = 0; i < curr_reg; i++)
		{
			if (r[i]->get_course()->get_coursecode() == course_code)
			{
				r[i]->add_marks(marks);
			}
		}
	}
	void view_evaluationreport(int course_code)
	{

		for (int i = 0; i < curr_reg; i++)
		{
			if (r[i]->get_course()->get_coursecode() == course_code)
			{
				r[i]->print_registration();
			}
		}
	}

	void view_marks(courses* c)
	{
		for (int i = 0; i < curr_reg; i++)
		{
			if (r[i]->get_course()->get_coursecode() == c->get_coursecode())
			{
				r[i]->print_registration();
			}
		}
	}
	void assign_grade(int course_code,char a)
	{
		for (int i = 0; i < curr_reg; i++)
		{
			if (r[i]->get_course()->get_coursecode() == course_code)
			{
				r[i]->assign_grade(a);
			}
		}
	}
	void get_grade(int course_code)
	{
		for (int i = 0; i < curr_reg; i++)
		{
			if (r[i]->get_course()->get_coursecode() == course_code)
			{
				r[i]->print_grade();
			}
		}
	}

	int get_login_id()
	{
		return person::get_id();
	}
	char* getstudent_password()
	{
		return person::get_password();
	}
	~student()
	{
		if (curr_reg > 0)
		{
			for (int i = 0; i < curr_reg; i++)
			{
				delete r[i];
			}
			delete[]r;
		}
	}


};