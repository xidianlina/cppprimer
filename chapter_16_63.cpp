#include <iostream>
#include <vector>
#include <string>

template <typename T,typename V>
int show_times(const T &vec, const V &val)
{
	int times = 0;
	for (size_t i = 0; i < vec.size(); ++i)
		if (vec[i] == val)
			++times;

	return times;
}

int main()
{
	using namespace std;

	vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	int a = 1;
	cout << a << "出现次数为：" << show_times(vec1, a) << endl;

	vector<double> vec2;
	vec2.push_back(1.2);
	vec2.push_back(2.4);
	double b = 1.2;
	cout << b << "出现次数为：" << show_times(vec2, b) << endl;

	vector<string> vec3;
	vec3.push_back(string("123"));
	vec3.push_back(string("23"));
	string c = "123";
	cout << c << "出现次数为：" << show_times(vec3, c) << endl;

	return 0;
}