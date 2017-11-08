#include <iostream>
#include <vector>

int main()
{
	using namespace std;

	int arr[] = { 0,1,2,3,4,5 };
	vector<int> vec(begin(arr), end(arr));
	
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}