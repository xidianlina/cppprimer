#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	string a[10] = { "love","love8","love","love","love","h","diuw","diuwudhg257","love","d" };
	vector<string> vec1(a, a + 10);    
	vector<string> vec2;
	unique_copy(vec1.cbegin(), vec1.cend(), back_inserter(vec2));
	cout << "字符串中的不重复字符为:";
	for (int i = 0; i < vec2.size(); ++i)
		cout << vec2[i] << " ";
	cout << endl;

	return 0;
}