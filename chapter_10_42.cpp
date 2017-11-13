#include<iostream>    
#include<string>     
#include<list>  
#include<algorithm>    
 
using namespace std;

int main()
{
	string a[10] = { "sdc","sddc","sdec","sfdc","sdec","sdc","sdc","fsdc","sadc","fsdc" };
	list<string> list1(a, a + 10);
	list1.sort();
	list1.unique();
	for (auto it1 = list1.begin(); it1 != list1.end(); ++it1)
		cout << *it1 << " ";
		cout << endl;

	return 0;
}