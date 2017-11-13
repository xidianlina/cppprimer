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
	copy(vec1.cbegin(), vec1.cend(), front_inserter(vec3));//��֧��push_front?,vector���������֧��  
	copy(vec1.cbegin(), vec1.cend(), inserter(vec4, vec4.begin()));

	cout << "vec2�ַ�Ϊ��";
	for (int i = 0; i<vec2.size(); ++i)
		cout << vec2[i] << " ";

	cout << endl << "vec3�ַ�Ϊ��";
	for (int i = 0; i<vec3.size(); ++i)
		cout << vec3[i] << " ";

	cout << endl << "vec4�ַ�Ϊ��";
	for (int i = 0; i<vec4.size(); ++i)
		cout << vec4[i] << " ";

	return 0;
}