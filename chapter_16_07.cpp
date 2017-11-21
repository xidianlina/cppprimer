#include <iostream>

using namespace std;

template <typename T,unsigned N>
constexpr unsigned size_of_array(const T(&arr)[N])
{
	return N;
}

int main()
{
	int arr[3] = { 0,3,1 };
	cout << "The size of array is " << size_of_array(arr) << endl;

	return 0;
}