#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

class Person
{
private:
	std::string name;
	std::string address;
	Person();
	Person(std::string client_name, std::string client_address);
public:
	void show_info();
	const std::string& getname()const;
	const std::string& getaddress()const;
};

std::istream& read(std::istream& is, Person &person);
std::ostream& print(std::ostream& os, const Person &person);

Person::Person()
{
	name = '\0';
	address = '\0';
}

Person::Person(std::string client_name,std::string client_address):name(client_name),address(client_address){}

void Person::show_info()
{
	std::cout << name << "'s" << " address is " << address << std::endl;
}

const std::string& Person::getname()const
{
	return name;
}

const std::string& Person::getaddress()const
{
	return address;
}

std::istream& read(std::istream& is, Person& person)
{
	is >> person.name >> person.address;
	
	return is;
}

std::ostream& print(std::ostream& os, const Person& person)
{
	os << person.name << "'s address is " << person.address << endl;

	return os;
}
#endif