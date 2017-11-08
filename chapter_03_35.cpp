#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	int arr[] = { 0,1,2,3,4,5 };

	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << endl;
	
	int *p = arr;
	int *e = &arr[6];
	while (p < e)
	{
		*p = 0;
		++p;
	}
	p = arr;
	e = &arr[6];
	while (p < e)
	{
		cout << *p << " ";
		++p;
	}
	cout << endl;

	return 0;
}