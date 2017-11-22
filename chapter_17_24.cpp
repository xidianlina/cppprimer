#include <iostream>
#include <string>
#include <regex>

using namespace std;
using namespace std::regex_constants;

bool valid(const smatch &m)
{
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched&&m[4].str() == m[6].str();
}

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	string fmt = "$2.$5.$7 ";
	string number = "76211(908) 555-1800111 442 43333232";
	cout << regex_replace(number, r, fmt, format_no_copy) << endl;

	while (getline(cin, s))
	{
		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
			if (valid(*it))
				cout << "valid: " << it->str() << endl;
			else
				cout << "not valid: " << it->str() << endl;
	}
}