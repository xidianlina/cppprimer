#include <iostream>
#include <string>

std::istream& isout(std::istream &is);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

	isout(cin);

	return 0;
}

std::istream& isout(std::istream &is)
{
	std::string str;

	while (is >> str)
		std::cout << str << " ";
	std::cout << std::endl;
	is.clear();

	return is;
}