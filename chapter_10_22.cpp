#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool func(const string &s)
{
	return s.size() <= 6;
}

int main()
{
	string a[10] = { "diuwudh","udh","dewiudh","wudh","diutrwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vec1(a, a + 10);   
	cout << "����С�ڵ���6���ַ�����" << count_if(vec1.begin(), vec1.end(), func) << "��" << endl;

	return 0;
}