#include <iostream>
#include <string>
#include <unordered_set>

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
	friend std::hash<Sales_data>;
	friend std::ostream &operator<<(std::ostream &os, const Sales_data &s);
	friend std::istream &operator>>(std::istream &is, Sales_data &s);
	friend bool operator==(const Sales_data &ls, const Sales_data &rs);
	friend Sales_data operator+(const Sales_data &ls, const Sales_data &rs);
	friend std::ostream &print(std::ostream &os, const Sales_data &s);
	friend std::istream &read(std::istream &is, Sales_data &s);
};
bool operator!=(const Sales_data &ls, const Sales_data &rs);
Sales_data add(const Sales_data &ls, const Sales_data &rs);

namespace std
{
	template<> struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data &s)const {
			return hash<string>()(s.bookNo) 
				^ hash<unsigned>()(s.units_sold) 
				^ hash<double>()(s.revenue);
		}
	};
}

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

int main()
{
	std::unordered_multiset<Sales_data> mset;
	Sales_data sd("Bible", 10, 0.98);

	mset.emplace(sd);
	mset.emplace("C++ Primer", 5, 9.99);

	for (const auto &item : mset)
		std::cout << "the hash code of " << item.isbn()
		<< ":\n0x" << std::hex << std::hash<Sales_data>()(item)
		<< "\n";
	
	return 0;
}