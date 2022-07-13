#include"teacher.h"
int teacher::total_teacher = 0;
template <class a>
void teacher::grow(a**& x, int& num)
{
	if (num == 0)
	{
		num++;
		x = new a * [num];
	}
	else if (num > 0)
	{
		a** temp;
		num++;
		temp = new a * [num];
		for (int i = 0; i < num - 1; i++)
		{
			temp[i] = x[i];
		}
		delete[]x;
		x = temp;
	}
}
int teacher::get_employeeno()
{
	return get_employee();
}
void teacher::change_password()
{
	person::change_password();
}
void teacher::change_userid()
{
	person::change_loginid();
}
void teacher::set_courses_array(courses** c, int num)
{
	total_courses = num;
	course = new courses * [num];
	for (int i = 0; i < num; i++)
	{
		course[i] = c[i];
	}
}
void teacher::assign_course(courses* c)
{
	grow(course, total_courses);
	course[total_courses - 1] = c;
	cout << "Course assigned successfully." << endl;
}
void teacher::print_teacher()
{
	employee::print_employee();
	cout << "Sr.   Course Code   Course Name    Credit Hours" << endl;
	for (int i = 0; i < total_courses; i++)
	{
		cout << i + 1 << ")     ";
		course[i]->print_course();
	}
	cout << endl;
}
int teacher::get_login_id()
{
	return person::get_id();
}
char* teacher::getteacher_password()
{
	return person::get_password();
}
void teacher::print_courses()
{
	for (int i = 0; i < total_courses; i++)
	{
		course[i]->print_course();
	}
}
void teacher::change_teacher_password()
{
	person::change_password();
}
courses** teacher::get_courses_ofteacher()
{
	return course;
}
int teacher::get_curr_courses_ofteacher()
{
	return total_courses;
}
courses* teacher::get_course(int x)
{
	return course[x - 1];
}
teacher:: ~teacher()
{
	if (total_courses > 0)
	{
		delete[]course;
	}
}