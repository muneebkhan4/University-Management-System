#include"university.h"
university::university(const char name[])
{
	this->name = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name); i++)
	{
		this->name[i] = name[i];
	}
	this->name[strlen(name)] = '\0';
	d = 0;
	count = 0;
}
template <class a>
void university::grow(a**& x, int& num)
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
void university::add_department()
{
	grow(d, count);
	d[count - 1] = new department();
}
department* university::get_department(int x)
{
	if (x <= count && x > 0)
		return d[x - 1];
	else
		return 0;
}

void university::print_uniname()
{
	cout << name;
}

university::~university()
{
	if (name != 0)
	{
		delete[] name;
		name = 0;
	}
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
		{
			delete d[i];
		}
		delete[]d;
	}
}