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

class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book,double price,std::size_t qty,double disc)
		:Quote(book,price),quantity(qty),discount(disc){}
	double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(string& book, double p, size_t n, double disc)
		:Disc_quote(book, price, qty, disc) {};

	double net_price(size_t cnt) const override
	{
		if (cnt >= qty)
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
		cout << "Min_qty: " << qty << endl;
		cout << "Price: " << price << endl;
	}
private:
	double discount;
	size_t qty;
};

class Number_quote : public Disc_quote
{
public:
	Number_quote() = default;
	Number_quote(string& book, double p, size_t n, double disc)
		:Disc_quote(book, p,n,disc) {};

	double net_price(size_t cnt) const override
	{
		if (cnt >= number)
		{
			return number*(1 - discount)*price + (cnt - number)*price;
		}
		else
		{
			return cnt*(1 - discount)*price;
		}
	}
	void debug()
	{
		cout << "This is number_quote Class" << endl;
		cout << "DISCOUNT: " << discount << endl;
		cout << "Max_qty: " << number << endl;
		cout << "Price: " << price << endl;
	}
private:
	double discount;
	size_t number;
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