#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
	using size_type = vector<string>::size_type;
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);
	friend bool operator>(const StrBlob&, const StrBlob&);
	friend bool operator<=(const StrBlob&, const StrBlob&);
	friend bool operator>=(const StrBlob&, const StrBlob&);
public:
	StrBlob():data(make_shared<vector<string>>()){}
	StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){}

	StrBlob(const StrBlob &sb):data(make_shared<vector<string>>(*sb.data)){}
	StrBlob &operator=(const StrBlob&);

	StrBlob(StrBlob &&rhs)noexcept:data(std::move(rhs.data)){}
	StrBlob &operator=(StrBlob &&)noexcept;

	StrBlobPtr begin();
	StrBlobPtr end();

	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;

	string &operator[](size_t n);
	const string &operator[](size_t n)const;

	size_type size()const { return data->size(); }
	bool empty()const { return data->empty(); }

	void push_back(const string &t) { data->push_back(t); }
	void push_back(string &&s) { data->push_back(std::move(s)); }

	void pop_back();
	string &front();
	string &back();
	const string &front()const;
	const string &back()const;
private:
	void check(size_type, const string&)const;
	shared_ptr<vector<string>> data;
};

inline void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

inline string &StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

inline string &StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

inline const string &StrBlob::front()const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

inline const string &StrBlob::back()const
{
	check(0, "back ont empty StrBlob");
	return data->back();
}

inline void StrBlob::check(size_type i, const string &msg)const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

inline string &StrBlob::operator[](size_t n)
{
	check(n, "out of range");
	return data->at(n);
}

inline const string &StrBlob::operator[](size_t n)const
{
	check(n, "out of range");
	return data->at(n);
}

class StrBlobPtr
{
	friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);;
	friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

public:
	StrBlobPtr():curr(0){}
	StrBlobPtr(StrBlob &s,size_t sz=0):wptr(s.data),curr(sz){}

	string &deref() const;
	StrBlobPtr &operator++();
	StrBlobPtr &operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	StrBlobPtr &operator+=(size_t);
	StrBlobPtr &operator-=(size_t);
	StrBlobPtr operator+(size_t) const;
	StrBlobPtr operator-(size_t) const;

	string &operator[](size_t n);
	const string &operator[](size_t n) const;

private:
	shared_ptr<vector<string>> check(size_t, const string &) const;

	std::weak_ptr<vector<string>> wptr;
	size_t curr;
};

inline string &StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline StrBlobPtr &StrBlobPtr::operator++() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

inline StrBlobPtr &StrBlobPtr::operator--() {
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

inline StrBlobPtr StrBlobPtr::operator++(int) {
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}

inline StrBlobPtr StrBlobPtr::operator--(int) {
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}

inline StrBlobPtr &StrBlobPtr::operator+=(size_t n) {
	curr += n;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

inline StrBlobPtr &StrBlobPtr::operator-=(size_t n) {
	curr -= n;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

inline StrBlobPtr StrBlobPtr::operator+(size_t n) const {
	StrBlobPtr ret = *this;
	ret += n;
	return ret;
}

inline StrBlobPtr StrBlobPtr::operator-(size_t n) const {
	StrBlobPtr ret = *this;
	ret -= n;
	return ret;
}

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i,
	const string &msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

inline string &StrBlobPtr::operator[](size_t n) {
	auto p = check(n, "dereference out of range.");
	return (*p)[n];
}

inline const string &StrBlobPtr::operator[](size_t n) const {
	auto p = check(n, "dereference out of range.");
	return (*p)[n];
}

class ConstStrBlobPtr {
	friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
	friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &s, size_t sz = 0) : wptr(s.data), curr(sz) {}

	const string &operator*() const;
	const string *operator->() const;
	ConstStrBlobPtr &operator++();
	ConstStrBlobPtr &operator--();
	ConstStrBlobPtr operator++(int);
	ConstStrBlobPtr operator--(int);
	ConstStrBlobPtr &operator+=(size_t);
	ConstStrBlobPtr &operator-=(size_t);
	ConstStrBlobPtr operator+(size_t) const;
	ConstStrBlobPtr operator-(size_t) const;

	const string &operator[](size_t n) const;

private:
	std::shared_ptr<vector<string>> check(size_t, const string &) const;

	std::weak_ptr<vector<string>> wptr;
	size_t curr;
};

inline const string &ConstStrBlobPtr::operator*() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline const string *ConstStrBlobPtr::operator->() const {
	return &this->operator*();
}

inline ConstStrBlobPtr &ConstStrBlobPtr::operator++() {
	check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}

inline ConstStrBlobPtr &ConstStrBlobPtr::operator--() {
	--curr;
	check(-1, "decrement past begin of ConstStrBlobPtr");
	return *this;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator++(int) {
	ConstStrBlobPtr ret = *this;
	++*this;
	return ret;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator--(int) {
	ConstStrBlobPtr ret = *this;
	--*this;
	return ret;
}

inline ConstStrBlobPtr &ConstStrBlobPtr::operator+=(size_t n) {
	curr += n;
	check(curr, "increment past end of ConstStrBlobPtr");
	return *this;
}

inline ConstStrBlobPtr &ConstStrBlobPtr::operator-=(size_t n) {
	curr -= n;
	check(curr, "increment past end of ConstStrBlobPtr");
	return *this;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator+(size_t n) const {
	ConstStrBlobPtr ret = *this;
	ret += n;
	return ret;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator-(size_t n) const {
	ConstStrBlobPtr ret = *this;
	ret -= n;
	return ret;
}

inline std::shared_ptr<vector<string>>
ConstStrBlobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

inline const string &ConstStrBlobPtr::operator[](size_t n) const {
	auto p = check(n, "dereference out of range.");
	return (*p)[n];
}

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlob& lhs, const StrBlob& rhs)
{
	return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
		rhs.data->begin(), rhs.data->end());
}

bool operator>(const StrBlob& lhs, const StrBlob& rhs)
{
	return rhs < lhs;
}

bool operator<=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs < rhs);
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& x, const StrBlobPtr& y)
{
	return x.curr < y.curr;
}

bool operator>(const StrBlobPtr& x, const StrBlobPtr& y)
{
	return x.curr > y.curr;
}

bool operator<=(const StrBlobPtr& x, const StrBlobPtr& y)
{
	return x.curr <= y.curr;
}

bool operator>=(const StrBlobPtr& x, const StrBlobPtr& y)
{
	return x.curr >= y.curr;
}

bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr < rhs.curr;
}

bool operator>(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr > rhs.curr;
}

bool operator<=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr <= rhs.curr;
}

bool operator>=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr >= rhs.curr;
}

StrBlob& StrBlob::operator=(const StrBlob& lhs)
{
	data = make_shared<vector<string>>(*lhs.data);
	return *this;
}

StrBlob& StrBlob::operator=(StrBlob&& rhs) noexcept
{
	if (this != &rhs) {
		data = std::move(rhs.data);
		rhs.data = nullptr;
	}

	return *this;
}
StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::cbegin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const
{
	return ConstStrBlobPtr(*this, data->size());
}