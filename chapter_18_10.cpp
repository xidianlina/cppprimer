#include <iostream>
#include <string>
#include <exception>

class out_of_stock :public std::runtime_error
{
public:
	explicit out_of_stock(const std::string &s):std::runtime_error(s){}
};

class isbn_mismatch :public std::logic_error
{
public:
	explicit isbn_mismatch(const std::string &s):std::logic_error(s){}
	isbn_mismatch(const std::string &s,const std::string &lhs,const std::string &rhs)
		:std::logic_error(s),left(lhs),right(rhs){}
	const std::string left, right;
};
class Sales_item {
	friend std::istream& operator>>(std::istream&, Sales_item&);
	friend std::ostream& operator<<(std::ostream&, const Sales_item&);
	friend bool operator==(const Sales_item&, const Sales_item&);
public:
	Sales_item() : units_sold(0), revenue(0.0) { }
	Sales_item(const std::string &book) : bookNo(book), units_sold(0), revenue(0.0) { }
	Sales_item(std::istream &is) { is >> *this; }
public:
	Sales_item& operator+=(const Sales_item&);
	std::string isbn() const { return bookNo; }
	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

inline bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

Sales_item operator+(const Sales_item&, const Sales_item&);

inline bool operator==(const Sales_item &lhs, const Sales_item &rhs)
{
	return lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue &&
		lhs.isbn() == rhs.isbn();
}

inline bool operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
	return !(lhs == rhs);
}

Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
	if (isbn() != rhs.isbn())
		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret += rhs;
	return ret;
}

std::istream& operator>>(std::istream& in, Sales_item& s)
{
	double price;
	in >> s.bookNo >> s.units_sold >> price;

	if (in)
		s.revenue = s.units_sold * price;
	else
		s = Sales_item();
	return in;
}

std::ostream& operator<<(std::ostream& out, const Sales_item& s)
{
	out << s.isbn() << " " << s.units_sold << " "
		<< s.revenue << " " << s.avg_price();
	return out;
}

double Sales_item::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

int main()
{
	using namespace std;

	Sales_item item1, item2, sum;
	while (cin >> item1 >> item2)
	{
		try
		{
			sum = item1 + item2;
		}
		catch (const isbn_mismatch &e)
		{
			cerr << e.what() << ": left isbn(" << e.left
				<< ") right isbn(" << e.right << ")" << endl;
		}
	}
	cout << sum << endl;

	return 0;
}