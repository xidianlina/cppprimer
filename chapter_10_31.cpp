#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
	using namespace std;

	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> vi;
	while (in_iter != eof)
		vi.push_back(*in_iter++);
	sort(vi.begin(), vi.end());
	unique_copy(vi.begin(), vi.end(), out_iter);
	cout << endl;

	return 0;
}