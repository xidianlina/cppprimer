#include <iostream>
#include <string>

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
	std::cout << input() << std::endl;

	return 0;
}