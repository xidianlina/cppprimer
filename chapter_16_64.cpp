#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
int show_times(const std::vector<T> &vec, const T val)
{
	int showtimes = 0;
	for (size_t i = 0; i < vec.size(); ++i)
	{
		if (vec[i] == val)
		{
			++showtimes;
		}
	}
	return showtimes;
}

template<>int show_times(const std::vector<const char *> &vec, const char *val)
{
	int showtimes = 0;
	for (size_t i = 0; i < vec.size(); ++i)
	{
		if (strcmp(vec[i], val))
		{
			++showtimes;
		}
	}
	return showtimes;
}

int main()
{
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

	vector<const char*> vec4;
	vec4.push_back("1230");
	vec4.push_back("123");
	char *d = "1230";
	cout << d << "出现次数为：" << show_times<const char *>(vec4, "1230") << endl;

	return 0;
}