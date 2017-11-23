#include <iostream>
#include <typeinfo>
#include <vector>

int main()
{
	using namespace std;

	int arr[41];
	double d = 6.45;
	vector<int> vec;
	int *p = arr;

	cout << typeid(42).name() << ", "
		<< typeid(arr).name() << ", "
		<< typeid(d).name() << ", "
		<< typeid(vec).name() << ", "
		<< typeid(p).name() << ", "
		<< typeid(*p).name() << endl;

	return 0;
}