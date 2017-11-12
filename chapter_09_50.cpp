#include <iostream>
#include <vector>
#include <string>

int main()
{
	using namespace std;

	vector<string> str(5, "10");
	int sumi = 0;
	double sumd = 0.0;
	for (int i = 0; i < str.size(); ++i)
	{
		sumi += stoi(str[i]);
		sumd += stod(str[i]);
		cout << stod(str[i]) << " ";
	}

	cout << endl << "int和为:" << sumi << endl;
	cout << "double和为:" << sumd << endl;

	return 0;
}