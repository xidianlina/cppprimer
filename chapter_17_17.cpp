#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);
	string test_str = "receipt freind theif receive";
	for (sregex_iterator it(test_str.begin(), test_str.end(), r), end; it != end; ++it)
		cout << it->str() << endl;
	for (sregex_iterator it(test_str.begin(), test_str.end(), r), end; it != end; ++it)
	{
		auto pos = it->prefix().length();
		pos = pos > 40 ? pos - 40 : 0;
		cout << it->prefix().str().substr(pos)
			<< "\n\t\t>>>" << it->str() << " <<<\n"
			<< it->suffix().str().substr(0, 40)
			<< endl;
	}

	return 0;
}