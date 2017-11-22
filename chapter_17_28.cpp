#include <random>
#include <iostream>
#include <vector>

using namespace std;

vector<unsigned> good_randVec()
{
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0, 9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; ++i)
		ret.push_back(u(e));
	return ret;
}

int main()
{
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 9);
	for (size_t i = 0; i < 10; ++i)
		cout << e() << " ";
	cout << endl;
	for (size_t i = 0; i < 10; ++i)
		cout << u(e) << " ";
	cout << endl;
	cout << "min: " << e.min() << " max: " << e.max() << endl;

	vector<unsigned> ret = good_randVec();
	for (auto ele : ret)
		cout << ele << " ";
	cout << endl;
	ret = good_randVec();
	for (auto ele : ret)
		cout << ele << " ";
	cout << endl;

	return 0;
}