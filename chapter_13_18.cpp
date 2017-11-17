#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
	Employee();
	Employee(string& s);
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;
	int num() { return number; }
private:
	string employee;
	int number;
	static int sta_number;
};

int Employee::sta_number = 0;

Employee::Employee()
{
	number = sta_number++;
}

Employee::Employee(string& s)
{
	employee = s;
	number = sta_number++;
}

void show(Employee &e)
{
	cout << e.num() << endl;
}

int main()
{
	Employee a, b, c;
	show(a);
	show(b);
	show(c);

	return 0;
}