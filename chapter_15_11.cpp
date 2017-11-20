#include <iostream>
#include <string>

using namespace std;

class Quote
{
	friend double print_total(ostream &, const Quote&, size_t);
public:
	Quote() = default;
	Quote(const string &book, double sales_price)
		:BookNo(book), price(sales_price) {};
	string isbn() const { return BookNo; };
	virtual double net_price(size_t n) const
	{
		return n*price;
	}
	virtual void debug()
	{
		cout << "This is Quote Class" << endl;
		cout << "ISBN: " << BookNo << endl;
		cout << "Price: " << price << endl;
	}

private:
	string BookNo;
protected:
	double price;
};

double print_total(ostream &os, const Quote&item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << endl;
	os << "sold: " << n << " total price: " << ret << endl;
	return ret;
}

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(string& book, double p, size_t n, double disc)
		:Quote(book, p), min_qty(n), discount(disc) {};

	double net_price(size_t cnt) const override
	{
		if (cnt >= min_qty)
		{
			return cnt*(1 - discount)*price;
		}
		else
		{
			return cnt*price;
		}
	}
	void debug()
	{
		cout << "This is bulk_quote Class" << endl;
		cout << "DISCOUNT: " << discount << endl;
		cout << "Min_qty: " << min_qty << endl;
		cout << "Price: " << price << endl;
	}
private:
	double discount;
	size_t min_qty;
};

class Number_quote : public Quote
{
public:
	Number_quote() = default;
	Number_quote(string& book, double p, size_t n, double disc)
		:Quote(book, p), number1(n), discount1(disc) {};

	double net_price(size_t cnt) const override
	{
		if (cnt >= number1)
		{
			return number1*(1 - discount1)*price + (cnt - number1)*price;
		}
		else
		{
			return cnt*(1 - discount1)*price;
		}
	}
	void debug()
	{
		cout << "This is number_quote Class" << endl;
		cout << "DISCOUNT: " << discount1 << endl;
		cout << "Max_qty: " << number1 << endl;
		cout << "Price: " << price << endl;
	}
private:
	double discount1;
	size_t number1;
};

int main()
{
	Quote b1("Áú×åI", 128);
	Bulk_quote b2(string("Áú×åII"), 128.0, 10, 0.7);
	Number_quote b3(string("Áú×åIII"), 128.0, 10, 0.7);
	print_total(cout, b1, 10);
	print_total(cout, b2, 10);
	cout << endl;
	b1.debug();
	b2.debug();
	b3.debug();

	return 0;
}