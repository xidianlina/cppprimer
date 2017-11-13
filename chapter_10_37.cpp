#include<iostream>      
#include<vector>   
#include<list>  
#include<algorithm>    

using namespace std;
 

int main()
{
	int a[10] = { 1,0,3,0,4,5,8,9,6,5 };
	vector<int> vec1(a, a + 10);
	list<int> list1;
	//反向迭代器++是递减的运算符，向后移动，--是递增的运算符，向前移动  
	copy(vec1.rbegin() + 3, vec1.rend() - 2, back_inserter(list1));

	for (auto it1 = list1.begin(); it1 != list1.end(); ++it1)
		cout << *it1 << " ";
	cout << endl;

	return 0;
}