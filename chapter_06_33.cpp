#include <iostream>
#include <vector>

void print_vector(int, std::vector<int>, int);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::vector;

	vector<int> vec{ 0,1,2,3,4,5 };
	int val = 0;
	print_vector(val, vec, vec.size());

	return 0;
}

void print_vector(int val, std::vector<int> vec, int size)
{
	if (val == size)
		return;
	else
	{
		std::cout << vec[val] << std::endl;
		val++;
		print_vector(val, vec, size);
	}
}