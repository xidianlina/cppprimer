#include <iostream>
#include <algorithm>
#include <vector>

class IsEqual
{
private:
	int value;
public:
	IsEqual(int val):value(val){}
	bool operator()(int elem) { return elem == value; }
};

int main()
{
	std::vector<int> vi = { 3,2,1,4,3,7,8,6 };
	std::replace_if(vi.begin(), vi.end(), IsEqual(3), 5);
	for (int i : vi)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}