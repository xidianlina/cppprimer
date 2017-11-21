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
	cout << "��һ��Ԫ���ǣ�" << *begin(arr) << endl;
	cout << "���һ��Ԫ���ǣ�" << *(end(arr) - 1) << endl;

	return 0;
}