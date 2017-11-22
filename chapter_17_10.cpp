#include <iostream>
#include <bitset>

int main()
{
	using namespace std;

	bitset<32> bs;
	bs.set(1, 1);
	bs.set(2, 1);
	bs.set(3, 1);
	bs.set(5, 1);
	bs.set(8, 1);
	bs.set(13, 1);
	bs.set(21, 1);
	for (size_t i = 0; i < bs.size(); ++i)
		cout << bs[i] << " ";
	cout << endl;

	bitset<32> bt;
	for (size_t i = 0; i < bt.size(); ++i)
		cout << bt[i] << " ";
	cout << endl;

	return 0;
}