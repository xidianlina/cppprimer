#include <iostream>
#include <string>
#include <vector>

class GetInput
{
public:
	GetInput(std::istream &in=std::cin):is(in){}
	std::string operator()()const
	{
		std::cout << "enter a line string: ";
		std::string str;
		std::getline(is, str);
		return is ? str : std::string();
	}
private:
	std::istream& is;
};

int main()
{
	GetInput input;
	std::vector<std::string> vec;
	for (std::string tmp; !(tmp = input()).empty();)
		vec.push_back(tmp);
	for (const auto &str : vec)
		std::cout << str << std::endl;

	return 0;
}