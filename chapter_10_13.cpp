#include<iostream>  
#include<string>  
#include<vector>  
#include<algorithm>  

using namespace std;

bool compareSize(const string &s);

int main(int argc, char**argv)
{
	string a[10] = { "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vec1(a, a + 10);
	vector<string>::iterator it1 = vec1.begin();
	vector<string>::iterator it2 = partition(vec1.begin(), vec1.end(), compareSize);
	cout << "排序后的vector中大于5的元素:";
	for (it1; it1 != it2; ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;

	return 0;
}

bool compareSize(const string &s)
{
	if (s.size() > 5)
		return true;
	else
		return false;
}