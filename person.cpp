#include"person.h"
person::person() 
{
	name = 0;
	age = 0;
	login_id = 0;
	password = 0;
}

person::person(const char name[], int age, int id, const char password[])
{
	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name); i++)
	{
		this->name[i] = name[i];
	}

	this->name[strlen(name)] = '\0';
	this->age = age;
	login_id = id;
	this->password = new char[strlen(password) + 1];
	for (int i = 0; i < strlen(password); i++)
	{
		this->password[i] = password[i];
	}

	this->password[strlen(password)] = '\0';
}
void person::print()
{
	cout << "Name: " << name << endl;
	cout << "Age:  " << age << endl;
}
void person::print_name()
{
	cout << name << "   ";
}
void person::change_loginid()
{
	cout << "Enter new ID." << endl;
	cin >> login_id;
	cout << "New ID updated successfully:  " << login_id << endl;
}
void person::change_password()
{
	char a[30];
	cout << "Enter new password." << endl;
	cin >> a;
	delete password;
	password = new char[strlen(a) + 1];
	for (int i = 0; i < strlen(a); i++)
	{
		password[i] = a[i];
	}
	password[strlen(a)] = '\0';
	cout << "Password updated successfully:  " << password << endl;
}
int person::get_id()
{
	return login_id;
}
int person::get_age()
{
	return age;
}
char* person::get_password()
{
	return password;
}
char* person::get_name_pointer()
{
	return name;
}

person:: ~person()
{
	if (name != 0)
	{
		delete[]name;
		name = 0;
	}
	if (password != 0)
	{
		delete[]password;
		password = 0;
	}
	age = 0;
}