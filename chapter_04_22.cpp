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
	finalgrade = (grade > 90) ? "high" : (grade > 70) ? "pass" : (grade > 60) ? "Low pass" : "fail";//条件运算符的嵌套  
	cout << finalgrade << endl;

	return 0;
}