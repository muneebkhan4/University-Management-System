#include"registration.h"
registration::registration(student* stu, courses* cour)
{
	gpa = 0;
	attendance = 0;
	marks = 0;
	grade = 0;
	s = stu;
	c = cour;
}
registration::registration(float gpa, int attendance, float marks, char grade)
{
	this->gpa = gpa;
	this->attendance = attendance;
	this->marks = marks;
	this->grade = grade;

}
void registration::assign_gpa(float x)
{
	gpa = x;
}
void registration::assign_marks(float x)
{
	marks = x;
}
void registration::assign_grade(char x)
{
	grade = x;
}
void registration::assign_attendance(int x)
{
	attendance = x;
}
void registration::print_grade()
{
	cout << "Grade: " << grade << endl;
}
void registration::add_marks(float x)
{
	marks += x;
}
void registration::mark_attendance()
{
	attendance++;
}

void registration::print_attendance()
{
	cout << attendance << endl;
}
courses* registration::get_course()
{
	return this->c;
}

void registration::marks_view()
{
	cout << "Marks:   " << marks << endl;
}
float registration::get_gpa()
{
	return gpa;
}
int registration::get_attendance()
{
	return attendance;
}
float registration::get_marks()
{
	return marks;
}
char registration::get_grade()
{
	return grade;
}
void registration::print_registration()
{
	cout << "           GPA: " << gpa << endl;
	cout << "           Marks: " << marks << endl;
	cout << "           Grade: " << grade << endl;
}
registration::~registration()
{
	c = 0;
	s = 0;
}