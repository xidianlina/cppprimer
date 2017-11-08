#include <iostream>
#include <vector>
#include <string>

int main()
{
	using namespace std;

	const vector<string> scores = { "F","D","C","B","A","A++" };
	cout << "Please enter your grade: ";
	int grade;
	cin >> grade;
	string lettergrade;
	if (grade < 60)
		lettergrade = scores[0];
	else
	{
		lettergrade = scores[(grade - 50) / 10];
		if (grade != 100)
			if (grade % 10 > 7)
				lettergrade += '+';
			else
				lettergrade += '-';
	}
	cout << "Your level is " << lettergrade << endl;

	return 0;
}