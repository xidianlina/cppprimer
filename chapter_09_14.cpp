#include <iostream>
#include <vector>
#include <list>
#include <string>

int main()
{
	using namespace std;

	vector<string> vec;
	list<char*> li{ "I","like","java","and","cpp" };
	vec.assign(li.begin(),li.end());

	for (auto ele : vec)
		cout << ele << " ";
	cout << endl;

	return 0;
}