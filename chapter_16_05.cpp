#include <iostream>

using namespace std;

template <typename T>
void my_print(const T& arr)
{
	for (auto item : arr)
		cout << item << " ";
	cout << endl;
}

int main()
{
	int arr[4] = { 0,4,3,1 };
	my_print(arr);

	return 0;
}