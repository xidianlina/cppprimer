#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	using namespace std;

	vector<int> vi{ 2,3,5,1,0,5,9,4,8,5,7 };
	int val = 5;

	int result = count(vi.cbegin(), vi.cend(), val);
	if (result)
		cout << "The val " << val << " occurs " << result << endl;
	else
		cout << "The val not occur!" << endl;

	return 0;
}