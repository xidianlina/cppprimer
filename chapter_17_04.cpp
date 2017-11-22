#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <tuple>
#include <numeric>

using namespace std;

class Sales_data
{
	std::string bookNo;
	unsigned units_sold;
	double revenue;
	double avg_price()const { return units_sold ? revenue / units_sold : 0; }
public:
	Sales_data(const std::string &s = std::string(), unsigned n = 0, double p = 0) :bookNo(s), units_sold(n), revenue(p) {}
	Sales_data(std::istream &is);
	std::string isbn()const { return bookNo; }
	Sales_data &operator+=(const Sales_data &s);
	friend std::ostream &operator<<(std::ostream &os, const Sales_data &s);
	friend std::istream &operator>>(std::istream &is, Sales_data &s);
	friend bool operator==(const Sales_data &ls, const Sales_data &rs);
	friend Sales_data operator+(const Sales_data &ls, const Sales_data &rs);
	friend std::ostream &print(std::ostream &os, const Sales_data &s);
	friend std::istream &read(std::istream &is, Sales_data &s);
};
bool operator!=(const Sales_data &ls, const Sales_data &rs);
Sales_data add(const Sales_data &ls, const Sales_data &rs);
bool compareIsbn(const Sales_data &s1, const Sales_data &s2);

Sales_data::Sales_data(std::istream &is)
{
	is >> *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &s)
{
	units_sold += s.units_sold;
	revenue += s.revenue;
	return *this;
}

bool compareIsbn(const Sales_data &s1, const Sales_data &s2)
{
	return s1.isbn < s2.isbn;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &s)
{
	os << s.isbn() << " " << s.units_sold << " " << s.revenue << " " << s.avg_price();
	return os;
}

std::istream &operator>>(std::istream &is, Sales_data &s)
{
	double price;
	is >> s.bookNo >> s.units_sold >> price;
	if (is)
		s.revenue = s.units_sold*price;
	else
		s = Sales_data();
	return is;
}

bool operator==(const Sales_data &ls, const Sales_data &rs)
{
	return ls.bookNo == rs.bookNo&&ls.units_sold == rs.units_sold&&ls.revenue == rs.revenue;
}
bool operator!=(const Sales_data &ls, const Sales_data &rs)
{
	return !(ls == rs);
}

Sales_data operator+(const Sales_data &ls, const Sales_data &rs)
{
	Sales_data temp = ls;
	temp += rs;
	return temp;
}

Sales_data add(const Sales_data &ls, const Sales_data &rs)
{
	Sales_data temp = ls;
	temp += rs;
	return temp;
}

std::ostream &print(std::ostream &os, const Sales_data &s)
{
	os << s.isbn() << " " << s.units_sold << " " << s.revenue << " " << s.avg_price();
	return os;
}

std::istream &read(std::istream &is, Sales_data &s)
{
	double price;
	is >> s.bookNo >> s.units_sold >> price;
	s.revenue = s.units_sold*price;
	return is;
}

typedef tuple<vector<Sales_data>::size_type,
	vector<Sales_data>::const_iterator,
	vector<Sales_data>::const_iterator> matches;

vector<matches> findBook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
			ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
	}
	return ret;
}

void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files)
{
	string s;
	while (in >> s)
	{
		auto trans = findBook(files, s);
		if (trans.empty())
		{
			cout << s << " not found in any stores" << endl;
			continue;
		}
		for (const auto &store : trans)
			os << "store " << get<0>(store) << " sales: "
			<< accumulate(get<1>(store), get<2>(store), Sales_data(s)) << endl;
	}
}