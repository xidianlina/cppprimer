#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr& s1, const HasPtr& s2);
	friend void show(vector<HasPtr>& vh);
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0), use(new size_t(1)) {};
	HasPtr(const HasPtr&p) :ps(p.ps), i(p.i), use(p.use) { ++*use; }
	HasPtr& operator=(const HasPtr& p)
	{
		++*p.use;
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
		ps = p.ps;
		use = p.use;
		i = p.i;
		return *this;
	}
	~HasPtr()
	{
		if (*use == 0)
		{
			delete ps;
			delete use;
		}
	}
private:
	string *ps;
	size_t *use;
	int i;
};

inline void swap(HasPtr& left, HasPtr& right)
{
	using std::swap;
	swap(left.ps, right.ps);
	swap(left.i, right.i);
	cout << "i am swap" << endl;
}

bool operator<(const HasPtr &s1, const HasPtr &s2)
{
	cout << "call operator<" << endl;
	return *s1.ps < *s2.ps;
}

void show(vector<HasPtr>& vh)
{
	vector<HasPtr>::iterator it = vh.begin();
	while (it != vh.end())
	{
		cout << *(it->ps) << '\t';
		++it;
	}
	cout << endl;
}

int main()
{
	vector<HasPtr> vh;
	HasPtr a("1");
	HasPtr b("1111");
	HasPtr c("11");
	vh.push_back(a);
	vh.push_back(b);
	vh.push_back(c);
	vector<HasPtr>::iterator it = vh.begin();
	sort(vh.begin(), vh.end());
	show(vh);

	return 0;
}