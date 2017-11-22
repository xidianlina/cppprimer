#include <iostream>
#include <random>
#include <ctime>

using namespace std;

unsigned int random_unsigned_int(int min, int max, unsigned int seed = time(0))
{
	default_random_engine e;
	uniform_int_distribution<unsigned int> u(min, max);
	return u(e);
}

int main()
{
	cout << random_unsigned_int(0, 100) << endl;

	return 0;
}