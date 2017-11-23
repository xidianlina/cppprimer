#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>

using namespace std;

int have_empty_string(vector<string> &vs)
{
	return count_if(vs.cbegin(), vs.cend(), mem_fn(&std::string::empty));
}

int main()
{
	vector<string> vs{ "","test","","hi","hello" };
	cout << have_empty_string(vs) << endl;
	cout << count_if(vs.cbegin(), vs.cend(), bind(&std::string::empty, std::placeholders::_1)) << endl;
	function<bool (const string&)> fcn = &std::string::empty;
	cout << count_if(vs.cbegin(), vs.cend(), fcn) << endl;
	return 0;
}