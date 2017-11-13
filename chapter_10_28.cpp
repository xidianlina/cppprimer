#include<iostream>    
#include<vector>    
#include<algorithm>   
#include<iterator>  
using namespace std;

int main(int argc, char**argv)
{
	int a[10] = { 1,2,3,4,5,6,7,8,9 };
	vector<int> vec1(a, a + 9);
	vector<int> vec2;
	vector<int> vec3;
	vector<int> vec4;

	copy(vec1.cbegin(), vec1.cend(), back_inserter(vec2));
	copy(vec1.cbegin(), vec1.cend(), front_inserter(vec3));//不支持push_front?,vector这个容器不支持  
	copy(vec1.cbegin(), vec1.cend(), inserter(vec4, vec4.begin()));

	cout << "vec2字符为：";
	for (int i = 0; i<vec2.size(); ++i)
		cout << vec2[i] << " ";

	cout << endl << "vec3字符为：";
	for (int i = 0; i<vec3.size(); ++i)
		cout << vec3[i] << " ";

	cout << endl << "vec4字符为：";
	for (int i = 0; i<vec4.size(); ++i)
		cout << vec4[i] << " ";

	return 0;
}