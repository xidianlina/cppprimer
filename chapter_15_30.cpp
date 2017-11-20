#include <iostream>
#include <string>
#include <memory>
#include <set>

using namespace std;

class Quote
{
public:
	Quote()
	{
		cout << "Quote Constructor" << endl;
	}
	Quote(const string &b, double p) :bookNo(b), price(p)
	{
		cout << "Quote Constructor taking two parameters" << endl;
	}
	Quote(const Quote &rhs) :bookNo(rhs.bookNo), price(rhs.price)
	{
		cout << "Quote Copy Constructor" << endl;
	}
	Quote& operator=(const Quote &rhs)
	{
		cout << "Quote Copy assignment operator" << endl;
		price = rhs.price;
		bookNo = rhs.bookNo;
		return *this;
	}
	Quote(Quote &&rhs)noexcept
		:bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price))
	{
		cout << "Quote Move Constructor" << endl;
	}
	Quote& operator=(Quote &&rhs)noexcept
	{
		cout << "Quote Move assignment operator" << endl;
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		return *this;
	}
	virtual ~Quote()
	{
		cout << "Quote Destructor" << endl;
	}
	string isbn()const { return bookNo; }
	virtual double net_price(size_t n)const { return n*price; }
	virtual Quote* clone()const& { return new Quote(*this); }
	virtual Quote* clone() && {return new Quote(std::move(*this)); }
private:
	string bookNo;
protected:
	double price = 0.0;
};

class Bulk_quote :public Quote
{
public:
	Bulk_quote()
	{
		cout << "Bulk_quote Constructor" << endl;
	}
	Bulk_quote(const string &b, double p, size_t q, double d)
		:Quote(b, p), min_qty(q), discount(d)
	{
		cout << "Bulk_quote Constructor taking four parameters" << endl;
	}
	Bulk_quote(const Bulk_quote &rhs)
		:Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount)
	{
		cout << "Bulk_quote Copy Constructor" << endl;
	}
	Bulk_quote& operator=(const Bulk_quote& rhs)
	{
		cout << "Bulk_quote Copy assignment operator" << endl;
		Quote::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;
		return *this;
	}
	Bulk_quote(Bulk_quote &&rhs)noexcept
		:Quote(rhs), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount))
	{
		cout << "Bulk_quote Move constructor" << endl;
	}
	Bulk_quote& operator=(Bulk_quote &&rhs)noexcept
	{
		cout << "Bulk_quote Move assignment operator" << endl;
		Quote::operator=(rhs);
		min_qty = std::move(rhs.min_qty);
		discount = std::move(rhs.discount);
		return *this;
	}
	virtual~Bulk_quote()
	{
		cout << "Bulk_quote destructor" << endl;
	}
	virtual double net_price(size_t cnt)const override
	{
		if (cnt >= min_qty)
			return cnt*(1 - discount)*price;
		else
			return cnt*price;
	}
	Bulk_quote* clone()const & { return new Bulk_quote(*this); }
	Bulk_quote* clone() && {return new Bulk_quote(std::move(*this)); }
protected:
	size_t min_qty = 0;
	double discount = 0.0;
};

class Basket
{
public:
	void add_item(const Quote& sale) 
	{ 
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote &&sale)
	{
		items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
	}
	double total_receipt(std::ostream&)const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

double Basket::total_receipt(ostream &os)const
{
	double sum = 0.0;

	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))

		sum += print_total(os, **iter, items.count(*iter));
	os << "Total Sale: " << sum << endl;

	return sum;
}

double print_total(ostream& os, Quote const& item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}