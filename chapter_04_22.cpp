#include <iostream>  
#include <string>  
#include <vector>  

int main()
{
	using namespace std;

	int grade;
	cout << "Please Input the grade :";
	cin >> grade;
	string finalgrade;
	finalgrade = (grade > 90) ? "high" : (grade > 70) ? "pass" : (grade > 60) ? "Low pass" : "fail";//�����������Ƕ��  
	cout << finalgrade << endl;

	return 0;
}