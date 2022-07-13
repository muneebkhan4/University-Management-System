#include"department.h"
#include"fstream"
department::department()
{
	char department_name[50];
	int department_total_courses;
	it_manager* department_itmanager;
	int department_itmanager_id;
	char department_itmanager_name[50];
	char department_itmanager_password[50];
	int department_itmanager_age;
	int department_itmanager_employee_no;
	int department_course_code;
	char department_course_name[50];
	int department_credit_hours;
	int department_course_currreg;
	ifstream fin;
	fin.open("department.txt");
	fin.getline(name, 50, '/');
	fin >> curr_courses;
	c = new courses * [curr_courses];
	for (int i = 0; i < curr_courses; i++)
	{
		fin >> department_course_code;
		fin.ignore();
		fin.getline(department_course_name, 50, '/');
		fin >> department_credit_hours;
		fin.ignore();
		fin >> department_course_currreg;
		fin.ignore();
		c[i] = new courses(department_course_code, department_course_name, department_credit_hours);
		c[i]->set_currreg(department_course_currreg);
	}
	fin >> department_itmanager_id;
	fin.ignore();
	fin.getline(department_itmanager_password, 50, '/');
	fin.getline(department_itmanager_name, 50, '/');
	fin >> department_itmanager_age;
	fin.ignore();
	fin >> department_itmanager_employee_no;
	it = new it_manager(department_itmanager_name, department_itmanager_age, department_itmanager_id, department_itmanager_password, department_itmanager_employee_no);
	fin.close();
	teachers = 0;
	curr_teacher = 0;
	students = 0;
	curr_student = 0;
}
void department::add_teacher_array(teacher** tea, int total_tea)
{
	curr_teacher = total_tea;
	teachers = new teacher * [curr_teacher];
	for (int i = 0; i < curr_teacher; i++)
	{
		teachers[i] = tea[i];
	}
	hod = teachers[0];
}
void department::add_student_array(student** stu, int total)
{
	curr_student = total;
	students = new student * [curr_student];
	for (int i = 0; i < curr_student; i++)
	{
		students[i] = stu[i];
	}
}

template <class a>
void department::grow(a**& x, int& num)
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

template <class a>
void department::shrink(a**& x, int index, int& num)
{
	if (num > 0)
	{
		a** temp;
		int l = 0;
		num--;
		temp = new a * [num];
		for (int i = 0; i < num + 1; i++)
		{
			if (i != index)
			{
				temp[l] = x[i];
				l++;
			}
		}
		delete[]x;
		x = temp;
	}
}
teacher* department::get_hod()
{
	return hod;
}

void department::add_student(student* s)
{
	grow(students, curr_student);
	students[curr_student - 1] = s;
	cout << "A new student added successfully" << endl << endl << endl;
	students[curr_student - 1]->print_student();
}
void department::remove_student(int student_id)
{
	for (int i = 0; i < curr_student; i++)
	{
		if (student_id == students[i]->get_id())
		{
			shrink(students, i, curr_student);
			cout << "Student removed sussessfully." << endl;
		}
	}
}
void department::add_teacher(teacher* tea)
{
	grow(teachers, curr_teacher);
	teachers[curr_teacher - 1] = tea;
	cout << "A new Teacher added successfully" << endl << endl << endl;
	teachers[curr_teacher - 1]->print_teacher();

}
void department::remove_teacher(int teacher_id)
{
	for (int i = 0; i < curr_teacher; i++)
	{
		if (teacher_id == teachers[i]->get_id())
		{
			shrink(teachers, i, curr_teacher);
			cout << "Faculty member removed successfully." << endl;
		}
	}
}
teacher** department::get_teacher_array()
{
	return teachers;
}
void department::assign_coursetoteacher(int employee_id, int coursecode)
{
	int flag = 1;
	for (int i = 0; i < curr_teacher; i++)
	{
		if (employee_id == teachers[i]->get_id())
		{
			for (int j = 0; j < curr_courses; j++)
			{
				if (coursecode == c[j]->get_coursecode())
				{
					teachers[i]->print_courses();

					teachers[i]->assign_course(c[j]);

					teachers[i]->print_courses();
				}
			}
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "Invalid Employee ID or Course Code." << endl;
	}
}

void department::register_courseforstudent(int course_code, int student_id)
{
	int flag = 1;
	for (int i = 0; i < curr_student; i++)
	{
		if (student_id == students[i]->get_id())
		{
			for (int j = 0; j < curr_courses; j++)
			{
				if (course_code == c[j]->get_coursecode())
				{
					students[i]->register_course(c[j]);

				}
			}
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "Invalid Student ID or course code." << endl;
	}
}
void department::unregister_courseforstudent(int course_code, int student_id)
{
	int flag = 1;
	for (int i = 0; i < curr_student; i++)
	{
		if (student_id == students[i]->get_id())
		{
			for (int j = 0; j < curr_courses; j++)
			{
				if (course_code == c[j]->get_coursecode())
				{
					students[i]->print_registered_courses();
					students[i]->unregister_course(c[j]);
					students[i]->print_registered_courses();

				}
			}
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "Invalid Student ID or course code." << endl;
	}
}
void department::mark_attendance(int course_code)
{
	char x;
	cout << "Enter 'p' to mark Present Or any other character to mark absent." << endl;
	cout << "Student Name" << endl;
	for (int i = 0; i < curr_student; i++)
	{
		if (students[i]->search_course_code(course_code))
		{
			students[i]->print_name();
			cin >> x;
			cout << endl;
			if (x == 'p')
			{
				students[i]->mark_attendance(course_code);
			}
		}
	}
}
void department::view_attendanceofallstudents(courses* c)
{
	cout << "Student name     Attendance" << endl;
	for (int i = 0; i < curr_student; i++)
	{
		if (students[i]->search_course_code(c->get_coursecode()))
		{
			students[i]->print_name();
			cout << "          ";
			students[i]->view_attendance(c);
		}
	}
}
void department::assign_marks(courses* course)
{
	cout << "Student Name" << endl;
	for (int i = 0; i < curr_student; i++)
	{
		if (students[i]->search_course_code(course->get_coursecode()))
		{
			students[i]->print_name();
			cout << "    ";
			float marks;
			cin >> marks;
			students[i]->assign_marks(course->get_coursecode(), marks);
			cout << endl;
		}
	}
}
void department::assign_gpa(courses* course)
{
	cout << "Student Name" << endl;
	for (int i = 0; i < curr_student; i++)
	{
		if (students[i]->search_course_code(course->get_coursecode()))
		{
			students[i]->print_name();
			cout << "    ";
			float gpa;
			cin >> gpa;
			students[i]->assign_gpa(course->get_coursecode(), gpa);
			cout << endl;
		}
	}
}
void department::view_evaluationReport(courses* c)
{
	cout << "Student Name" << endl;
	for (int i = 0; i < curr_student; i++)
	{
		if (students[i]->search_course_code(c->get_coursecode()))
		{
			students[i]->print_name();
			cout << ":";
			students[i]->view_evaluationreport(c->get_coursecode());
			cout << endl;
		}
	}
}
void department::assign_grade(courses* c)
{
	cout << "Student Name" << endl;
	for (int i = 0; i < curr_student; i++)
	{
		if (students[i]->search_course_code(c->get_coursecode()))
		{
			students[i]->print_name();
			cout << "   ";
			char grade;
			cin >> grade;
			students[i]->assign_grade(c->get_coursecode(), grade);
		}
	}
}
void department::view_grades(int course_code)
{
	int flag = 1;
	for (int i = 0; i < curr_courses; i++)
	{
		if (course_code == c[i]->get_coursecode())
		{
			cout << "Student Name" << endl;
			for (int i = 0; i < curr_student; i++)
			{
				if (students[i]->search_course_code(course_code))
				{
					students[i]->print_name();
					cout << "        ";
					students[i]->get_grade(course_code);
					cout << endl;
				}
			}
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "Invalid course code." << endl;
	}
}
void department::change_studentid(int student_id)
{
	for (int i = 0; i < curr_student; i++)
	{
		if (students[i]->get_id() == student_id)
		{
			students[i]->change_userid();
		}
	}
}
void department::change_studentpassword(int student_id)
{
	for (int i = 0; i < curr_student; i++)
	{
		if (students[i]->get_id() == student_id)
		{
			students[i]->change_password();
		}
	}
}
void department::change_teacherid(int teacher_id)
{
	for (int i = 0; i < curr_teacher; i++)
	{
		if (teachers[i]->get_id() == teacher_id)
		{
			teachers[i]->change_userid();
		}
	}
}
void department::change_teacherpassword(int teacher_id)
{
	for (int i = 0; i < curr_teacher; i++)
	{
		if (teachers[i]->get_id() == teacher_id)
		{
			teachers[i]->change_password();
		}
	}
}
char* department::get_department_name()
{
	return name;
}
int department::get_department_total_courses()
{
	return curr_courses;
}
courses** department::get_department_courses()
{
	return c;
}
int department::get_itmanager_id()
{
	return it->get_id();
}
char* department::get_itmanager_password()
{
	return it->get_password();
}
char* department::get_itmanager_name()
{
	return it->get_name_pointer();
}
int department::get_itmanager_age()
{
	return it->get_age();
}
int department::get_itmanager_employee_id()
{
	return it->get_employee();
}
it_manager* department::get_it_manager()
{
	return it;
}
department::~department()
{
	if (curr_teacher > 0)
	{
		for (int i = 0; i < curr_teacher; i++)
		{
			delete teachers[i];
		}
		delete[]teachers;
	}
	if (curr_student > 0)
	{
		for (int i = 0; i < curr_student; i++)
		{
			delete students[i];
		}
		delete[]students;
	}
	if (curr_courses > 0)
	{
		for (int i = 0; i < curr_courses; i++)
		{
			delete c[i];
		}
		delete[]c;
	}
	hod = 0;
	it = 0;
}