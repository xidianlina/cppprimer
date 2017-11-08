#include <iostream>

int main()
{
	using std::cout;
	using std::endl;

	const char ca[] = { 'h','e','l','l','o' };
	const char *cp = ca;
	while (*cp)
	{
		cout << *cp << endl;
		++cp;
	}

	return 0;
}