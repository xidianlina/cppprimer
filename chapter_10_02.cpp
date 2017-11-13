#include <iostream>
#include <string>
#include <list>

int main()
{
	using namespace std;

	list<string> li{ "test","java","cpp","java","cpp","python","c","java" };
	string val = "java";

	int result = count(li.cbegin(), li.cend(), val);
	if (result)
		cout << "The val " << val << " occurs " << result << endl;
	else
		cout << "The val " << val << " not occur!!" << endl;

	return 0;
}