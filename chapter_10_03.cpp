#include <iostream>
#include <vector>
#include <numeric>

int main()
{
	using namespace std;

	vector<int> vi{ 2,3,0,1,9,5,7,4,7 };
	int sum = accumulate(vi.cbegin(), vi.cend(), 0);
	cout << "The sum is " << sum << endl;

	return 0;
}