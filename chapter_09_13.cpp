#include<iostream>  
#include<vector>  
#include<list>  

int main()
{
	using namespace std;

	list<int> list1(7, 8);
	vector<int> vec2(5, 2);

	vector<double> vec1(list1.begin(), list1.end());
	vector<double> vec3(vec2.begin(), vec2.end());

	vector<double>::iterator it1 = vec1.begin();
	vector<double>::iterator it2 = vec3.begin();
	for (it1; it1 != vec1.end(); it1++)
	{
		cout << *it1 << " ";
	}
	cout << endl;
	for (it2; it2 != vec3.end(); it2++)
	{
		cout << *it2 << " ";
	}
	cout << endl;

	return 0;
}