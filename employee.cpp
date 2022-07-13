#include"employee.h"
employee::employee()
{
	employee_no = 0;
}
int employee::get_employee()
{
	return employee_no;
}

void employee::print_employee()
{
	person::print();
	cout << "Employee ID:  " << employee_no << endl;
}

employee::~employee()
{

}
