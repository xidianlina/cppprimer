#include <iostream>
#include <vector>

using namespace std;

template <typename T> void Have(T &t)
{
	for (size_t i = 0; i < t.size(); ++i)
		cout << t[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> vi{ 9,4,3,1,0 };
	Have(vi);

	return 0;
}