#include <iostream>

using namespace std;

class SmallInt
{
public:
	SmallInt(int i = 0) :val(i)
	{
		if (i < 0 || i>255)
			throw std::out_of_range("Bad SmallInt value");
	}
	operator int()const { return val; }
private:
	std::size_t val;
};

int main()
{
	SmallInt si;
	si = 4;
	cout << si << endl;
	cout << si + 3 << endl;

	return 0;
}