#include <iostream>
#include <vector>

using namespace std;

template <typename T, unsigned N> 
T *begin(const T (&arr)[N])
{
	return arr;
}

template <typename T,unsigned N>
T *end(const T(&arr)[N])
{
	return arr + N;
}

int main()
{
	int arr[5] = { 0,4,3,2,1 };
	cout << "第一个元素是：" << *begin(arr) << endl;
	cout << "最后一个元素是：" << *(end(arr) - 1) << endl;

	return 0;
}