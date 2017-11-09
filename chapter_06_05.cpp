#include <iostream>

int myAbs(int);

int main()
{
	using namespace std;

	cout << "Enter a number: ";
	int num;
	cin >> num;
	cout << "The absolution of " << num << " is " << myAbs(num) << endl;

	return 0;
}

int myAbs(int num)
{
	return num > 0 ? num : -num;
}