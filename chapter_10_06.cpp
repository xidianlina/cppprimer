#include<iostream>  
#include<vector>  
#include<algorithm>  

using namespace std;

int main()
{
	int a[10] = { 0,1,2,5,4,5,4,5,4,5 };
	vector<int> vec(a, a + 10);
	cout << "�޸�ǰ��";
	for (int i = 0; i < 10; ++i)
		cout << vec[i] << " ";
	cout << endl;
	fill_n(vec.begin(), vec.size(), 0);  
	cout << "�޸ĺ�";
	for (int i = 0; i < 10; ++i)
		cout << vec[i] << " ";
	cout << endl;

	return 0;
}