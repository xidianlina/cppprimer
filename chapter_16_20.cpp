#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename T>
void Print(const T &t)
{
	auto  it = begin(t);
	while (it != end(t))
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	int arr[] = { 9,1,7,4 };
	vector<string> vs = { "cpp","is","my","love" };
	vector<int> li{ 0,4,2,7,6,8,3,1 };
	Print(arr);
	Print(vs);
	Print(li);

	return 0;
}