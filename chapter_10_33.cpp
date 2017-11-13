#include <iostream>
#include <fstream>
#include <iterator>

void in_out(std::string, std::string, std::string);

int main()
{
	std::string infile = "num.txt";
	std::string oddfile = "odd.txt";
	std::string evenfile = "even.txt";
	in_out(infile, oddfile, evenfile);

	return 0;
}

void in_out(std::string in, std::string odd, std::string even)
{
	std::ifstream infile(in);
	std::ofstream oddfile(odd);
	std::ofstream evenfile(even);

	std::istream_iterator<int> in_iter(infile), eof;
	std::ostream_iterator<int> odd_iter(oddfile, " ");
	std::ostream_iterator<int> even_iter(evenfile, "\n");

	while (in_iter != eof)
	{
		if (*in_iter % 2)
			odd_iter = *in_iter;
		else
			even_iter = *in_iter;
		++in_iter;
	}
}