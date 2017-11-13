#include<iostream>  
#include<string>  
#include<vector>  
#include<algorithm>  
using namespace std;

int main(int argc, char**argv)
{
	string a[10] = { "diuwudh","udh","dewiudh","wudh","diutrwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vec1(a, a + 10);//利用数组初始化vector  
	cout << "长度大于6的字符串有" << count_if(vec1.begin(), vec1.end(), [](string &s) {return s.size() > 6; }) << "个" << endl;

	return 0;
}