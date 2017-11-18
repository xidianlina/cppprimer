#include <iostream>
#include <string>
#include <fstream>

class BoundTest
{
private:
	std::size_t lower;
	std::size_t upper;
public:
	BoundTest(std::size_t l=0,std::size_t u=0):lower(l),upper(u){}
	bool operator()(const std::string &s)
	{
		return lower <= s.length() && s.length() <= upper;
	}
};

int main()
{
	std::ifstream fin("test.txt");

	std::size_t nine = 0, ten = 0;
	BoundTest test9(1, 9);
	BoundTest test10(1, 10);

	std::string word;
	while (fin >> word)
	{
		if (test9(word))
			++nine;
		if (!test10(word))
			++ten;
	}

	std::cout << nine << ", " << ten << std::endl;

	return 0;
}