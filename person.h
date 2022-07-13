#pragma once
#include<iostream>
using namespace std;
class person
{
	char* name;
	int age;
	int login_id;
	char* password;
public:
	person();

	person(const char name[], int age, int id, const char password[]);
	
	void print();
	
	void print_name();
	
	void change_loginid();
	
	void change_password();
	
	int get_id();
	
	int get_age();
	
	char* get_password();
	
	char* get_name_pointer();
	
	virtual ~person();
	
};