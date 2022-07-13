#include"courses.h"

courses::courses(int course_code, const char name[], int credit_hours)
{
	this->course_code = course_code;
	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name); i++)
	{
		this->name[i] = name[i];
	}
	this->name[strlen(name)] = '\0';
	credit_hour = credit_hours;
	curr_reg = 0;
}

void courses::set_currreg(int x)
{
	curr_reg = x;
}
void courses::assign_ta(TA* t)
{
	ta = t;
}

void courses::print_course()
{
	cout << course_code << "           " << name << "             " << credit_hour << endl;
}
void courses::add_reg(registration* reg)
{
	if (curr_reg < 50)
	{
		r[curr_reg] = reg;
		curr_reg++;
	}
	else
		cout << "Registration is Full." << endl;
}
void courses::un_reg(registration* reg)
{
	cout << curr_reg << endl << endl;
	for (int i = 0; i < curr_reg; i++)
	{
		if (reg == r[i])
		{
			cout << "Course unregistered successfully." << endl;
			for (int j = i; j < curr_reg - 1; i++)
			{
				r[j] = r[j + 1];
			}
			r[curr_reg - 1] = 0;
			curr_reg--;
		}
	}
}
void courses::view_attendance()
{
	for (int i = 0; i < curr_reg; i++)
	{
		r[i]->print_attendance();
	}
}

void courses::course_mark_attendance()
{
	for (int i = 0; i < curr_reg; i++)
	{
		r[i]->mark_attendance();
	}
}

int courses::get_coursecode()
{
	return course_code;
}
char* courses::get_course_name()
{
	return name;
}
int courses::get_credit_hour()
{
	return credit_hour;
}
int courses::get_curr_reg()
{
	return curr_reg;
}
courses::~courses()
{
	if (name != 0)
	{
		delete[]name;
	}
	if (curr_reg > 0)
	{
		delete[]r;
	}
	ta = 0;
}