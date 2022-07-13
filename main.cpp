#include<iostream>
#include<fstream>
#include <stdio.h> 
#include <stdlib.h> 
#include<time.h>
#include<ctime>
using namespace std;
#include"university.h"
#include"System.h"

///   Date for open and close of registration of course for student and is control by line 382
///   Date for open and close of with unregister a course is controled by line  429
///   Date for open and close of with draw a course is controled by line  462
///  I have set it to month 6 and day 30. So all functionaity is open. You can change it to check its working.

template <class a>
void grow(a**& x, int& num)
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
void shrink(a**& x, int index, int& num)
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

void student_data_print(student *stu)
{
	system("cls");
	stu->print_student();
	cout << "Sr.   Course Code   Course Name    Credit Hours" << endl;
	stu->print_registered_courses();
	cout << endl<<"i)    Enter '1' to register any course." << endl;
	cout <<"ii)   Enter '2' to unregister any course." << endl;
	cout <<"iii)  Enter '3' to withdraw any course." << endl;
	cout <<"iv)   Enter '4' to view marks sheet of any course." << endl;
	cout <<"v)    Enter '5' to view attendance of any course." << endl;
	cout <<"vi)   Enter '6' to change password." << endl;
	cout <<"vii)  Enter '0' to quit." << endl;
}
void teacher_data_print(teacher* tea)
{
	system("cls");
	tea->print_teacher();
	cout << endl << "i)   Enter '1' to manage attendance of any course." << endl;
	cout << "ii)  Enter '2' to view attendance of all students." << endl;
	cout << "iii) Enter '3' to manage evaluation." << endl;
	cout << "iv)  Enter '4' to view evaluation report of all students." << endl;
	cout << "v)   Enter '5' to assign grades to students." << endl;
	cout << "vi)  Enter '6' to change password." << endl;
	cout << "vii) Enter '0' to quit." << endl;
}
void itmanager_data_print(it_manager* it)
{
	system("cls");
	it->print_employee();
	cout << endl << "i)   Enter '1' to create account of faculty member." << endl;
	cout << "ii)  Enter '2' to delete account of faculty member." << endl;
	cout << "iii) Enter '3' to create account of student." << endl;
	cout << "iv)  Enter '4' to delete account of student." << endl;
	cout << "v)   Enter '5' to maintain accounts" << endl;
	cout << "vi)  Enter '6' to change password." << endl;
	cout << "vii) Enter '0' to quit." << endl;
}
void hod_data_print(teacher* hod)
{
	system("cls");
	hod->print_teacher();
	cout << endl << "i)   Enter '1' to assign course to teacher." << endl;
	cout << "ii)  Enter '2' to register a course for a student." << endl;
	cout << "iii) Enter '3' to unregister a course for a student." << endl;
	cout << "iv)  Enter '4' to view grades of any course." << endl;
	cout << "v)   Enter '5' to manage attendance of students." << endl;
	cout << "vi)  Enter '6' to view attendance of students." << endl;
	cout << "vii) Enter '7' to manage evaluation of students." << endl;
	cout << "viii)Enter '8' to assign grade to students." << endl;
	cout << "ix)  Enter '9' to change password." << endl;
	cout << "x)   Enter '0' to quit." << endl;
}
void student_file_write(student**stu,int total_stu)
{
	ofstream fout;
	fout.open("student.txt");
	fout << total_stu;
	fout << endl;
	for (int i = 0; i < total_stu; i++)
	{
		fout << stu[i]->get_login_id();
		fout << "/";
		fout << stu[i]->getstudent_password();
		fout << "/";
		fout << stu[i]->get_name_pointer();
		fout << "/";
		fout << stu[i]->get_age();
		fout << "/";
		fout << stu[i]->get_roll_no();
		fout << "/";
		fout << stu[i]->get_curr_registration();
		fout << endl;
		for (int j = 0; j < stu[i]->get_curr_registration(); j++)
		{
			fout<<stu[i]->get_registration_list()[j]->get_course()->get_coursecode();
			fout << endl;
		}
		for (int j = 0; j < stu[i]->get_curr_registration(); j++)
		{
			fout << stu[i]->get_registration_list()[j]->get_gpa();
			fout << "/";
			fout << stu[i]->get_registration_list()[j]->get_attendance();
			fout << "/";
			fout << stu[i]->get_registration_list()[j]->get_marks();
			fout << "/";
			fout << stu[i]->get_registration_list()[j]->get_grade();
			fout << "/";
			fout << endl;
		}
	}
}
void teacher_file_write(teacher** tea, int total_tea)
{
	ofstream fout;
	fout.open("teachers.txt");
	fout << total_tea;
	fout << endl;
	for (int i = 0; i < total_tea; i++)
	{
		fout << tea[i]->get_login_id();
		fout << "/";
		fout << tea[i]->getteacher_password();
		fout << "/";
		fout << tea[i]->get_name_pointer();
		fout << "/";
		fout << tea[i]->get_age();
		fout << "/";
		fout << tea[i]->get_employeeno();
		fout << "/";
		fout << tea[i]->get_curr_courses_ofteacher();
		fout << endl;
		for (int j = 0; j < tea[i]->get_curr_courses_ofteacher(); j++)
		{
			fout<<tea[i]->get_courses_ofteacher()[j]->get_coursecode();
			fout << endl;
		}
	}
}
void department_file_write(department* dep)
{
	ofstream fout;
	fout.open("department.txt");
	fout << dep->get_department_name();
	fout << "/" << endl;
	fout << dep->get_department_total_courses();
	fout << endl;
	courses** temp=dep->get_department_courses();
	for (int i = 0; i < dep->get_department_total_courses(); i++)
	{
		fout << temp[i]->get_coursecode();
		fout << "/";
		fout << temp[i]->get_course_name();
		fout << "/";
		fout << temp[i]->get_credit_hour();
		fout << "/";
		fout << temp[i]->get_curr_reg();
		fout << "/";
		fout << endl;
	}
	fout << dep->get_itmanager_id();
	fout << "/";
	fout << dep->get_itmanager_password();
	fout << "/";
	fout << dep->get_itmanager_name();
	fout << "/";
	fout << dep->get_itmanager_age();
	fout << "/";
	fout << dep->get_itmanager_employee_id();
}


int main()
{

	
	time_t t = time(NULL);
	int year= t / 31557600 + 1970 ;
	int month= t % 31557600 / 2629800 + 1;
	int day=(( (t % 31557600) % 2629800)-8400) / 86402+2 ;
	cout <<"Date:   "<< day << "/" << month << "/" << year << endl;
	

	university fast("Fast");
	fast.add_department();


	//teachers data read.....

	int total_teachers=0;
	int teacher_id;
	char teacher_name[50];
	char teacher_password[50];
	int teacher_age;
	int teacher_employee_no;
	int teacher_total_courses;
	ifstream fin;
	fin.open("teachers.txt");
	fin >> total_teachers;
	teacher** teachers = new teacher*[total_teachers];
	courses** teacher_course=0;
	for (int i = 0; i < total_teachers; i++)
	{
		fin >> teacher_id;
		fin.ignore();
		fin.getline(teacher_password, 50, '/');
		fin.getline(teacher_name, 50, '/');
		fin >> teacher_age;
		fin.ignore();
		fin >> teacher_employee_no;
		teachers[i] = new teacher(teacher_name, teacher_age, teacher_id, teacher_password, teacher_employee_no);
		fin.ignore();
		fin >> teacher_total_courses;
		int temp_for_teacher;
		teacher_course = new courses * [teacher_total_courses];
		for (int j = 0; j < teacher_total_courses; j++)
		{
			fin >> temp_for_teacher;
			
			for (int k = 0; k < fast.get_department(1)->get_department_total_courses(); k++)
			{
				if (temp_for_teacher == fast.get_department(1)->get_department_courses()[k]->get_coursecode())
				{
					teacher_course[j] = fast.get_department(1)->get_department_courses()[k];
				}
			}
		}
		teachers[i]->set_courses_array(teacher_course, teacher_total_courses);
	}
	fin.close();
	

	//students data read......

	int total_students=0;
	int student_id;
	char student_name[50];
	char student_password[50];
	int student_age;
	int student_roll_no;
	int student_total_courses;
	fin.open("student.txt");
	fin >> total_students;
	student** students = new student*[total_students];
	for (int i = 0; i < total_students; i++)
	{
		fin >> student_id;
		fin.ignore();
		fin.getline(student_password, 50, '/');
		fin.getline(student_name, 50, '/');
		fin >> student_age;
		fin.ignore();
		fin >> student_roll_no;
		students[i]= new student(student_name, student_age, student_id, student_password, student_roll_no);
		fin.ignore();
		fin >> student_total_courses;
		float gpa;
		int attendance;
		float marks;
		char grade;
		int student_temp;
		registration** reg = new registration * [student_total_courses];
		for (int j = 0; j < student_total_courses; j++)
		{
			fin >> student_temp;
			for (int k = 0; k < fast.get_department(1)->get_department_total_courses(); k++)
			{
				if (student_temp == fast.get_department(1)->get_department_courses()[k]->get_coursecode())
				{
					reg[j] = new registration(students[i], fast.get_department(1)->get_department_courses()[k]);
				}
			}
		}
		students[i]->registration_list(reg,student_total_courses);
		for (int l = 0; l < student_total_courses; l++)
		{
			fin >> gpa;
			reg[l]->assign_gpa(gpa);
			fin.ignore();
			fin >> attendance;
			reg[l]->assign_attendance(attendance);
			fin.ignore();
			fin >> marks;
			reg[l]->assign_marks(marks);
			fin.ignore();
			fin >> grade;
			reg[l]->assign_grade(grade);
			fin.ignore();
		}
	}

	fin.close();
	
	fast.get_department(1)->add_student_array(students, total_students);
	fast.get_department(1)->add_teacher_array(teachers, total_teachers);


	int abc=0,xyz;
	char password[20];
	mysystem::print_info();
	while (abc != 5)
	{
		cin >> abc;
		if (abc == 1)
		{
			int flag = 1;
			int flag1 = 1;
			system("cls");
			while (flag1 == 1)
			{
				
				cout << "Enter user ID: ";
				cin >> xyz;
				for (int i = 0; i < total_students; i++)
				{
					if (students[total_students - 1]->get_login_id() != xyz && i == total_students - 1 && flag1 == 1)
					{
						system("cls");
						cout << "Invalid User ID." << endl;
					}
					if (students[i]->get_login_id() == xyz)
					{
						flag1 = 0;
						while (flag == 1)
						{
							cout << endl << "Enter Password: ";
							cin >> password;
							if (strcmp(password, students[i]->getstudent_password()) == 0)
							{
								flag = 0;
								int q = 0;
								int flag2 = 1;
								int q1;
								student_data_print(students[i]);
								while (flag2 == 1)
								{
									cin >> q1;
									try
									{
										if (q1 == 1)
										{
											student_data_print(students[i]);

											if (month == 6 && day < 30)
											{
												try
												{
													if (students[i]->get_curr_registration() < 5)
													{
														cout << "Enter the course code of the course you want to register." << endl;
														cin >> q;

														fast.get_department(1)->register_courseforstudent(q, students[i]->get_id());
														student_file_write(students, total_students);
														department_file_write(fast.get_department(1));
														cout << "Enter '1' to continue or Enter '0' to exit." << endl;
														cin >> flag2;
														try
														{
															if (flag2 == 1)
															{
																student_data_print(students[i]);
															}
															else if (flag2 == 0)
															{
																abc = 5;
															}
															else
																throw "xyz";
														}
														catch (...)
														{
															cout << "Invalid Number." << endl;
														}
													}
													else
														throw 0;
												}
												catch (int)
												{
													cout << "Registration is full." << endl;
												}
											}
											else
											{
												cout << "Can not do this operation date has passed." << endl;
											}
										}
										else if (q1 == 2)
										{
											if (month == 6 && day < 30)
											{
												student_data_print(students[i]);
												cout << "Enter the serial number of the course you want to unregister." << endl;
												cin >> q;
												courses* lkjh = students[i]->get_course(q);
												fast.get_department(1)->unregister_courseforstudent(lkjh->get_coursecode(), students[i]->get_id());
												student_file_write(students, total_students);
												department_file_write(fast.get_department(1));
												cout << "Enter '1' to continue or Enter '0' to exit." << endl;
												cin >> flag2;
												try
												{
													if (flag2 == 1)
													{
														student_data_print(students[i]);
													}
													else if (flag2 == 0)
													{
														abc = 5;
													}
													else
													throw "xyz";
												}
												catch (...)
												{
													cout << "Invalid Number." << endl;
												}
											}
											else
												cout << "Can not do this operation. Date has passed." << endl;
										}
										else if (q1 == 3)
										{
											if (month == 6 && day < 30)
											{
												student_data_print(students[i]);
												cout << "Enter the serial number of the course you want to withdraw." << endl;
												cin >> q;
												courses* lkjh = students[i]->get_course(q);
												students[i]->drop_course(lkjh);
												student_file_write(students, total_students);
												cout << "Enter '1' to continue or Enter '0' to exit." << endl;
												cin >> flag2;
												try
												{
													if (flag2 == 1)
													{
														student_data_print(students[i]);
													}
													else if (flag2 == 0)
													{
														abc = 5;
													}
													else
													throw "xyz";
												}
												catch (...)
												{
													cout << "Invalid Number." << endl;
												}
											}
											else
												cout << "Can not do this operation. Date has passed." << endl;
										}
										else if (q1 == 4)
										{
											student_data_print(students[i]);
											cout << "Enter the serial number of the course you want to view marks sheet." << endl;
											cin >> q;
											courses* lkjh = students[i]->get_course(q);
											student_data_print(students[i]);
											students[i]->view_marks(lkjh);
											cout << "Enter '1' to continue or Enter '0' to exit." << endl;
											cin >> flag2;
											try
											{
												if (flag2 == 1)
												{
													student_data_print(students[i]);
												}
												else if (flag2 == 0)
												{
													abc = 5;
												}
												else
												throw "xyz";
											}
											catch (...)
											{
												cout << "Invalid Number." << endl;
											}
										}
										else if (q1 == 5)
										{
											student_data_print(students[i]);
											cout << "Enter the serial number of the course you want to view attendance sheet." << endl;
											cin >> q;
											courses* lkjh = students[i]->get_course(q);
											student_data_print(students[i]);
											students[i]->view_attendance(lkjh);
											cout << "Enter '1' to continue or Enter '0' to exit." << endl;
											cin >> flag2;
											try
											{
												if (flag2 == 1)
												{
													student_data_print(students[i]);
												}
												else if (flag2 == 0)
												{
													abc = 5;
												}
												else
												throw "xyz";
											}
											catch (...)
											{
												cout << "Invalid Number." << endl;
											}
										}
										else if (q1 == 6)
										{
											students[i]->change_student_password();
											student_file_write(students, total_students);
											cout << "Enter '1' to continue or Enter '0' to exit." << endl;
											cin >> flag2;
											try
											{
												if (flag2 == 1)
												{
													student_data_print(students[i]);
												}
												else if (flag2 == 0)
												{
													abc = 5;
												}
												else
												throw "xyz";
											}
											catch (...)
											{
												cout << "Invalid Number." << endl;
											}
										}
										else if (q1 == 0)
										{
											flag2 = 0;
											abc = 5;
										}
										else
										throw "xyz";
									}
									catch (...)
									{
										cout << "Invalid Selection" << endl;
									}
								}
							}
							else
							{
								system("cls");
								cout << "Wrong Password." << endl;
								cout << "Enter user ID: " << students[i]->get_login_id();
							}
						}
					}
				}
			}
		}
		else if (abc == 2)
		{
			int flag = 1;
			int flag1 = 1;
			system("cls");
			while (flag1 == 1)
			{
				cout << "Enter user ID: ";
				cin >> xyz;
				for (int i = 0; i < total_teachers; i++)
				{
					if (teachers[total_teachers - 1]->get_login_id() != xyz && flag1 == 1 && i==total_teachers-1)
					{
						system("cls");
						cout << "Invalid User ID." << endl;
					}
					else if(teachers[i]->get_login_id() == xyz)
					{
						flag1 = 0;
						while (flag == 1)
						{
							cout << endl << "Enter Password: ";
							cin >> password;
							if (strcmp(password, teachers[i]->getteacher_password()) == 0)
							{
								flag = 0;
								int q = 0;
								int flag2 = 1;
								int q1;
								teacher_data_print(teachers[i]);
								while (flag2 == 1)
								{
									cin >> q1;
									try
									{
										if (q1 == 1)
										{
											teacher_data_print(teachers[i]);
											cout << "Enter serial number of the course you want to manage attendance." << endl;
											cin >> q;
											if (q <= teachers[i]->get_curr_courses_ofteacher())
											{
												courses* temp_course = teachers[i]->get_course(q);
												int temp_course_code = temp_course->get_coursecode();
												fast.get_department(1)->mark_attendance(temp_course_code);
												student_file_write(students, total_students);
												cout << "Enter '1' to continue or Enter '0' to exit." << endl;
												cin >> flag2;
												try
												{
													if (flag2 == 1)
													{
														teacher_data_print(teachers[i]);
													}
													else if (flag2 == 0)
													{
														abc = 5;
													}
													else
														throw "xyz";
												}
												catch (...)
												{
													cout << "Invalid Number." << endl;
												}
											}
											else
												cout << "Invalid Selection." << endl;
										}
										else if (q1 == 2)
										{
											teacher_data_print(teachers[i]);
											cout << "Enter serial number of the course you want to view attendance." << endl;
											cin >> q;
											if (q <= teachers[i]->get_curr_courses_ofteacher())
											{
												courses* temp_course = teachers[i]->get_course(q);
												fast.get_department(1)->view_attendanceofallstudents(temp_course);
												cout << "Enter '1' to continue or Enter '0' to exit." << endl;
												cin >> flag2;
												try
												{
													if (flag2 == 1)
													{
														teacher_data_print(teachers[i]);
													}
													else if (flag2 == 0)
													{
														abc = 5;
													}
													else
														throw "xyz";
												}
												catch (...)
												{
													cout << "Invalid Number." << endl;
												}
											}
											else
												cout << "Invalid Selection." << endl;
										}

										else if (q1 == 3)
										{
											teacher_data_print(teachers[i]);
											int options;
											cout << "Enter serial number of the course you want to manage evaluation." << endl;
											cin >> q;
											if (q <= teachers[i]->get_curr_courses_ofteacher())
											{
												courses* temp_course = teachers[i]->get_course(q);
												cout << endl << "Enter '1' to assign marks and enter '2' to assign GPA." << endl;
												cin >> options;
												try
												{
													if (options == 1)
													{
														fast.get_department(1)->assign_marks(temp_course);
														student_file_write(students, total_students);
														cout << "Enter '1' to continue or Enter '0' to exit." << endl;
														cin >> flag2;
														try
														{
															if (flag2 == 1)
															{
																teacher_data_print(teachers[i]);
															}
															else if (flag2 == 0)
															{
																abc = 5;
															}
															else
																throw "xyz";
														}
														catch (...)
														{
															cout << "Invalid Number." << endl;
														}
													}
													else if (options == 2)
													{
														fast.get_department(1)->assign_gpa(temp_course);
														student_file_write(students, total_students);
														cout << "Enter '1' to continue or Enter '0' to exit." << endl;
														cin >> flag2;
														try
														{
															if (flag2 == 1)
															{
																teacher_data_print(teachers[i]);
															}
															else if (flag2 == 0)
															{
																abc = 5;
															}
															else
																throw "xyz";
														}
														catch (...)
														{
															cout << "Invalid Number." << endl;
														}
													}
													else
														throw 0;
												}
												catch (int)
												{
													cout << "Invalid Selection." << endl;
												}
											}
											else
												cout << "Invalid Selection." << endl;
										}
										else if (q1 == 4)
										{
											teacher_data_print(teachers[i]);
											cout << "Enter serial number of the course you want to view evaluation report." << endl;
											cin >> q;
											if (q <= teachers[i]->get_curr_courses_ofteacher())
											{
												courses* temp_course = teachers[i]->get_course(q);
												fast.get_department(1)->view_evaluationReport(temp_course);
												cout << "Enter '1' to continue or Enter '0' to exit." << endl;
												cin >> flag2;
												try
												{
													if (flag2 == 1)
													{
														teacher_data_print(teachers[i]);
													}
													else if (flag2 == 0)
													{
														abc = 5;
													}
													else
														throw "xyz";
												}
												catch (...)
												{
													cout << "Invalid Number." << endl;
												}
											}
											else
												cout << "Invalid Selection." << endl;
										}
										else if (q1 == 5)
										{
											teacher_data_print(teachers[i]);
											cout << "Enter serial number of the course you want to assign grade." << endl;
											cin >> q;
											if (q <= teachers[i]->get_curr_courses_ofteacher())
											{
												courses* temp_course = teachers[i]->get_course(q);
												fast.get_department(1)->assign_grade(temp_course);
												student_file_write(students, total_students);
												cout << "Enter '1' to continue or Enter '0' to exit." << endl;
												cin >> flag2;
												try
												{
													if (flag2 == 1)
													{
														teacher_data_print(teachers[i]);
													}
													else if (flag2 == 0)
													{
														abc = 5;
													}
													else
														throw "xyz";
												}
												catch (...)
												{
													cout << "Invalid Number." << endl;
												}
											}
											else
												cout << "Invalid Selection." << endl;
										}
										else if (q1 == 6)
										{
											teachers[i]->change_teacher_password();
											teacher_file_write(teachers, total_teachers);
											cout << "Enter '1' to continue or Enter '0' to exit." << endl;
											cin >> flag2;
											try
											{
												if (flag2 == 1)
												{
													teacher_data_print(teachers[i]);
												}
												else if (flag2 == 0)
												{
													abc = 5;
												}
												else
												throw "xyz";
											}
											catch (...)
											{
												cout << "Invalid Number." << endl;
											}
										}
										else if (q1 == 0)
										{
											flag2 = 0;
											abc = 5;
										}
										else
											throw "xyz";
									}
									catch (...)
									{
										cout << "Invalid Selection." << endl;
									}
								}
							}
							else
							{
								system("cls");
								cout << "Wrong Password." << endl;
								cout << "Enter user ID: " << students[i]->get_login_id();
							}
						}
					}
				}
			}
		}
		else if (abc == 3)
		{
		    int flag = 1;
			int flag1 = 1;
		    system("cls");
			while (flag1 == 1)
			{
				cout << "Enter user ID: ";
				cin >> xyz;
				if (fast.get_department(1)->get_hod()->get_id() == xyz)
				{
					flag1 = 0;
					while (flag == 1)
					{
						cout << endl << "Enter Password: ";
						cin >> password;
						if (strcmp(password, fast.get_department(1)->get_hod()->get_password()) == 0)
						{
							flag = 0;
							int q = 0;
							int flag2 = 1;
							int q1;
							system("cls");
							hod_data_print(fast.get_department(1)->get_hod());
							while (flag2 == 1)
							{
								cin >> q1;
								try
								{
									if (q1 == 1)
									{
										int temp_id, temp_coursecode;
										cout << "Enter ID of the teacher you want to assign course:  ";
										cin >> temp_id;
										cout << "Enter course code of the course you want to assign:  ";
										cin >> temp_coursecode;
										fast.get_department(1)->assign_coursetoteacher(temp_id, temp_coursecode);
										teacher_file_write(teachers, total_teachers);
										cout << "Enter '1' to continue or Enter '0' to exit." << endl;
										cin >> flag2;
										try
										{
											if (flag2 == 1)
											{
												hod_data_print(fast.get_department(1)->get_hod());
											}
											else if (flag2 == 0)
											{
												abc = 5;
											}
											else
											throw "xyz";
										}
										catch (...)
										{
											cout << "Invalid Number." << endl;
										}
									}
									else if (q1 == 2)
									{
										int temp_id, temp_coursecode;
										cout << "Enter ID of the student you want to assign course:  ";
										cin >> temp_id;
										cout << "Enter course code of the course you want to assign:  ";
										cin >> temp_coursecode;
										fast.get_department(1)->register_courseforstudent(temp_coursecode, temp_id);
										student_file_write(students, total_students);
										cout << "Enter '1' to continue or Enter '0' to exit." << endl;
										cin >> flag2;
										try
										{
											if (flag2 == 1)
											{
												hod_data_print(fast.get_department(1)->get_hod());
											}
											else if (flag2 == 0)
											{
												abc = 5;
											}
											else
											throw "xyz";
										}
										catch (...)
										{
											cout << "Invalid Number." << endl;
										}
									}
									else if (q1 == 3)
									{
										int temp_id, temp_coursecode;
										cout << "Enter ID of the student you want to unregister course:  ";
										cin >> temp_id;
										cout << "Enter course code of the course you want to unregister:  ";
										cin >> temp_coursecode;
										fast.get_department(1)->unregister_courseforstudent(temp_coursecode, temp_id);
										student_file_write(students, total_students);
										cout << "Enter '1' to continue or Enter '0' to exit." << endl;
										cin >> flag2;
										try
										{
											if (flag2 == 1)
											{
												hod_data_print(fast.get_department(1)->get_hod());
											}
											else if (flag2 == 0)
											{
												abc = 5;
											}
											else
											throw "xyz";
										}
										catch (...)
										{
											cout << "Invalid Number." << endl;
										}
									}
									else if (q1 == 4)
									{
										int temp_code;
										cout << "Enter course code:  ";
										cin >> temp_code;
										fast.get_department(1)->view_grades(temp_code);
										cout << "Enter '1' to continue or Enter '0' to exit." << endl;
										cin >> flag2;
										try
										{
											if (flag2 == 1)
											{
												hod_data_print(fast.get_department(1)->get_hod());
											}
											else if (flag2 == 0)
											{
												abc = 5;
											}
											else
											throw "xyz";
										}
										catch (...)
										{
											cout << "Invalid Number." << endl;
										}
									}
									else if (q1 == 5)
									{
										hod_data_print(fast.get_department(1)->get_hod());
										cout << "Enter serial number of the course you want to manage attendance." << endl;
										cin >> q;
										if (q <= fast.get_department(1)->get_hod()->get_curr_courses_ofteacher())
										{
											courses* temp_course = fast.get_department(1)->get_hod()->get_course(q);
											int temp_course_code = temp_course->get_coursecode();
											fast.get_department(1)->mark_attendance(temp_course_code);
											student_file_write(students, total_students);
											cout << "Enter '1' to continue or Enter '0' to exit." << endl;
											cin >> flag2;
											try
											{
												if (flag2 == 1)
												{
													hod_data_print(fast.get_department(1)->get_hod());
												}
												else if (flag2 == 0)
												{
													abc = 5;
												}
												else
													throw "xyz";
											}
											catch (...)
											{
												cout << "Invalid Number." << endl;
											}
										}
										else
											cout << "Invalid Selection." << endl;
									}
									else if (q1 == 6)
									{
										hod_data_print(fast.get_department(1)->get_hod());
										cout << "Enter serial number of the course you want to view attendance." << endl;
										cin >> q;
										if (q <= fast.get_department(1)->get_hod()->get_curr_courses_ofteacher())
										{
											courses* temp_course = fast.get_department(1)->get_hod()->get_course(q);
											fast.get_department(1)->view_attendanceofallstudents(temp_course);
											cout << "Enter '1' to continue or Enter '0' to exit." << endl;
											cin >> flag2;
											try
											{
												if (flag2 == 1)
												{
													hod_data_print(fast.get_department(1)->get_hod());
												}
												else if (flag2 == 0)
												{
													abc = 5;
												}
												else
													throw "xyz";
											}
											catch (...)
											{
												cout << "Invalid Number." << endl;
											}
										}
										else
											cout << "Invalid selection." << endl;
									}
									else if (q1 == 7)
									{
										hod_data_print(fast.get_department(1)->get_hod());
										int options;
										cout << "Enter serial number of the course you want to manage evaluation." << endl;
										cin >> q;
										if (q <= fast.get_department(1)->get_hod()->get_curr_courses_ofteacher())
										{
											courses* temp_course = fast.get_department(1)->get_hod()->get_course(q);
											cout << endl << "Enter '1' to assign marks and enter '2' to assign GPA." << endl;
											cin >> options;
											try
											{
												if (options == 1)
												{
													fast.get_department(1)->assign_marks(temp_course);
													student_file_write(students, total_students);
													cout << "Enter '1' to continue or Enter '0' to exit." << endl;
													cin >> flag2;
													try
													{
														if (flag2 == 1)
														{
															hod_data_print(fast.get_department(1)->get_hod());
														}
														else if (flag2 == 0)
														{
															abc = 5;
														}
														else
															throw "xyz";
													}
													catch (...)
													{
														cout << "Invalid Number." << endl;
													}
												}
												else if (options == 2)
												{
													fast.get_department(1)->assign_gpa(temp_course);
													student_file_write(students, total_students);
													cout << "Enter '1' to continue or Enter '0' to exit." << endl;
													cin >> flag2;
													try
													{
														if (flag2 == 1)
														{
															hod_data_print(fast.get_department(1)->get_hod());
														}
														else if (flag2 == 0)
														{
															abc = 5;
														}
														else
															throw "xyz";
													}
													catch (...)
													{
														cout << "Invalid Number." << endl;
													}
												}
												else
													throw "xyz";
											}
											catch (...)
											{
												cout << "Invalid selection." << endl;
											}
										}
										else
											cout << "Invalid Selection." << endl;
									}
									else if (q1 == 8)
									{
										hod_data_print(fast.get_department(1)->get_hod());
										cout << "Enter serial number of the course you want to assign grade." << endl;
										cin >> q;
										if (q <= fast.get_department(1)->get_hod()->get_curr_courses_ofteacher())
										{
											courses* temp_course = fast.get_department(1)->get_hod()->get_course(q);
											fast.get_department(1)->assign_grade(temp_course);
											student_file_write(students, total_students);
											cout << "Enter '1' to continue or Enter '0' to exit." << endl;
											cin >> flag2;
											try
											{
												if (flag2 == 1)
												{
													hod_data_print(fast.get_department(1)->get_hod());
												}
												else if (flag2 == 0)
												{
													abc = 5;
												}
												else
													throw "xyz";
											}
											catch (...)
											{
												cout << "Invalid Number." << endl;
											}
										}
										else
											cout << "Invalid Selection." << endl;
									}
									else if (q1 == 9)
									{
										fast.get_department(1)->get_hod()->change_password();
										cout << "Enter '1' to continue or Enter '0' to exit." << endl;
										cin >> flag2;
										try
										{
											if (flag2 == 1)
											{
												hod_data_print(fast.get_department(1)->get_hod());
											}
											else if (flag2 == 0)
											{
												abc = 5;
											}
											else
											throw "xyz";
										}
										catch (...)
										{
											cout << "Invalid Number." << endl;
										}
									}
									else if (q1 == 0)
									{
										flag2 = 0;
										abc = 5;
									}
									else
										throw "xyz";
								}
								catch (...)
								{
									cout << "Invalid Selection." << endl;
								}
							}
						}
					}
				}
				else
				{
				  system("cls");
				  cout << "Invalid User ID." << endl;
                }
			}
		}
		else if (abc == 4)
		{

			int flag = 1;
			int flag1 = 1;
			system("cls");
			while (flag1 == 1)
			{
				cout << "Enter user ID: ";
				cin >> xyz;
				if (fast.get_department(1)->get_itmanager_id() == xyz)
				{
					flag1 = 0;
					while (flag == 1)
					{
						cout << endl << "Enter Password: ";
						cin >> password;
						if (strcmp(password, fast.get_department(1)->get_itmanager_password()) == 0)
						{
							flag = 0;
							int q = 0;
							int flag2 = 1;
							int q1;
							system("cls");
							itmanager_data_print(fast.get_department(1)->get_it_manager());
							while (flag2 == 1)
							{
								cin >> q1;
								try
								{
									if (q1 == 1)
									{
										char temp_name[50];
										char temp_password[50];
										int temp_employee_no;
										int temp_age;
										int temp_id;
										cout << "Enter Name:  ";
										cin >> temp_name;
										cout << "Enter age:  ";
										cin >> temp_age;
										cout << "Enter Employee Number:  ";
										cin >> temp_employee_no;
										cout << "Enter ID:  ";
										cin >> temp_id;
										cout << "Enter Password:  ";
										cin >> temp_password;
										grow(teachers, total_teachers);
										teachers[total_teachers - 1] = new teacher(temp_name, temp_age, temp_id, temp_password, temp_employee_no);
										fast.get_department(1)->add_teacher(teachers[total_teachers - 1]);
										teacher_file_write(teachers, total_teachers);
										cout << "Enter '1' to continue or Enter '0' to exit." << endl;
										cin >> flag2;
										try
										{
											if (flag2 == 1)
											{
												itmanager_data_print(fast.get_department(1)->get_it_manager());
											}
											else if (flag2 == 0)
											{
												abc = 5;
											}
											else
											throw "xyz";
										}
										catch (...)
										{
											cout << "Invalid Number." << endl;
										}
									}
									else if (q1 == 2)
									{
										int temp_id;
										int flag3 = 1;
										cout << "Enter 'ID' of the faculty member you want to delete." << endl;
										cin >> temp_id;
										for (int i = 0; i < total_teachers; i++)
										{
											if (teachers[i]->get_id() == temp_id)
											{
												shrink(teachers, i, total_teachers);
												flag3 = 0;
											}
										}
										if (flag3 == 0)
										{
											fast.get_department(1)->remove_teacher(temp_id);
										}
										else
										{
											cout << "Invalid Teacher ID." << endl;
										}
										teacher_file_write(teachers, total_teachers);
										cout << "Enter '1' to continue or Enter '0' to exit." << endl;
										cin >> flag2;
										try
										{
											if (flag2 == 1)
											{
												itmanager_data_print(fast.get_department(1)->get_it_manager());
											}
											else if (flag2 == 0)
											{
												abc = 5;
											}
											else
											throw "xyz";
										}
										catch (...)
										{
											cout << "Invalid Number." << endl;
										}
									}
									else if (q1 == 3)
									{
										char temp_name[50];
										char temp_password[50];
										int temp_roll_no;
										int temp_age;
										int temp_id;
										cout << "Enter Name:  ";
										cin >> temp_name;
										cout << "Enter age:  ";
										cin >> temp_age;
										cout << "Enter Roll Number:  ";
										cin >> temp_roll_no;
										cout << "Enter ID:  ";
										cin >> temp_id;
										cout << "Enter Password:  ";
										cin >> temp_password;
										grow(students, total_students);
										students[total_students - 1] = new student(temp_name, temp_age, temp_id, temp_password, temp_roll_no);

										fast.get_department(1)->add_student(students[total_students - 1]);
										student_file_write(students, total_students);
										cout << "Enter '1' to continue or Enter '0' to exit." << endl;
										cin >> flag2;
										try
										{
											if (flag2 == 1)
											{
												itmanager_data_print(fast.get_department(1)->get_it_manager());
											}
											else if (flag2 == 0)
											{
												abc = 5;
											}
											else
											throw "xyz";
										}
										catch (...)
										{
											cout << "Invalid Number." << endl;
										}
									}
									else if (q1 == 4)
									{

										int temp_id;
										int flag3 = 1;
										cout << "Enter 'ID' of the student you want to delete." << endl;
										cin >> temp_id;
										for (int i = 0; i < total_students; i++)
										{
											if (temp_id == students[i]->get_id())
											{
												shrink(students, i, total_students);
												flag3 = 0;
											}
										}
										if (flag3 == 0)
										{
											fast.get_department(1)->remove_student(temp_id);
										}
										else
										{
											cout << "Invalid Student ID." << endl;
										}
										student_file_write(students, total_students);
										cout << "Enter '1' to continue or Enter '0' to exit." << endl;
										cin >> flag2;
										try
										{
											if (flag2 == 1)
											{
												itmanager_data_print(fast.get_department(1)->get_it_manager());
											}
											else if (flag2 == 0)
											{
												abc = 5;
											}
											else
											throw "xyz";
										}
										catch (...)
										{
											cout << "Invalid Number." << endl;
										}
									}
									else if (q1 == 5)
									{
										int temp;
										int temp2;
										cout << "i)  Enter '1' to manage account of student." << endl;
										cout << "ii) Enter '2' to manage account of teacher." << endl;
										cin >> temp;
										if (temp == 1)
										{
											int temp_id;
											cout << "Enter ID of student." << endl;
											cin >> temp_id;
											cout << "i)  Enter '1' to change user ID of student." << endl;
											cout << "ii) Enter '2' to change password of student." << endl;
											cin >> temp2;
											try
											{
												if (temp2 == 1)
												{
													fast.get_department(1)->change_studentid(temp_id);
													student_file_write(students, total_students);
												}
												else if (temp2 == 2)
												{
													fast.get_department(1)->change_studentpassword(temp_id);
													student_file_write(students, total_students);
												}
												else
												throw 0;
											}
											catch (int)
											{
												cout << "Invalid selection." << endl;
											}
										}
										if (temp == 2)
										{
											int temp_id;
											cout << "Enter ID of teacher." << endl;
											cin >> temp_id;
											cout << "i)  Enter '1' to change user ID of teacher." << endl;
											cout << "ii) Enter '2' to change password of teacher." << endl;
											cin >> temp2;
											try
											{
												if (temp2 == 1)
												{
													fast.get_department(1)->change_teacherid(temp_id);
													teacher_file_write(teachers, total_teachers);
												}
												else if (temp2 == 2)
												{
													fast.get_department(1)->change_teacherpassword(temp_id);
													teacher_file_write(teachers, total_teachers);
												}
												else
												throw 0;
											}
											catch (int)
											{
												cout << "Invalid Selection." << endl;
											}
										}

										cout << "Enter '1' to continue or Enter '0' to exit." << endl;
										cin >> flag2;
										try
										{
											if (flag2 == 1)
											{
												itmanager_data_print(fast.get_department(1)->get_it_manager());
											}
											else if (flag2 == 0)
											{
												abc = 5;
											}
											else
											throw "xyz";
										}
										catch (...)
										{
											cout << "Invalid Number." << endl;
										}
									}
									else if (q1 == 6)
									{
										fast.get_department(1)->get_it_manager()->change_password();

										cout << "Enter '1' to continue or Enter '0' to exit." << endl;
										cin >> flag2;
										try
										{
											if (flag2 == 1)
											{
												itmanager_data_print(fast.get_department(1)->get_it_manager());
											}
											else if (flag2 == 0)
											{
												abc = 5;
											}
											else
											throw "xyz";
										}
										catch (...)
										{
											cout << "Invalid Number." << endl;
										}
									}
									else if (q1 == 0)
									{
										flag2 = 0;
										abc = 5;
									}
									else
										throw "xyz";
								}
								catch (...)
								{
									cout << "Invalid Selection." << endl;
								}
							}
						}
						else
						{
						   system("cls");
						   cout << "wrong Password.";
                        }
					}
				}
				else
				{
				    system("cls");
					cout << "Invalid User ID." << endl;
                }
			}
		}
		else if (abc == 5)
		{
			return 0;
		}
		else
		{
		    system("cls");
		    mysystem::print_info();
			cout << "Enter a valid number" << endl;
		}
	}
	system("pause");
	return 0;
}