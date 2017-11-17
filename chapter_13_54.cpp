#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr&, const HasPtr&);
	friend void show(vector<HasPtr>&);
public:
	HasPtr(const string&s = string()) :ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr& p) :ps(p.ps), i(p.i), use(p.use) { ++*use; }
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
	HasPtr(HasPtr&& p)noexcept:ps(p.ps), i(p.i)
	{
		p.ps = 0;
		cout << "call move constructor" << std::endl;
	}

	HasPtr& operator=(HasPtr &&rhs)
	{
		swap(*this, rhs);
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

inline void swap(HasPtr &a, HasPtr &b)
{
	using std::swap;
	swap(a.ps, b.ps);
	std::swap(a.i, b.i);
	cout << "swap";
}

bool operator<(const HasPtr&s1, const HasPtr&s2)
{
	cout << "定义的operator<被调用" << endl;
	return *s1.ps < *s2.ps;
}

void show(vector<HasPtr> &vh)
{
	vector<HasPtr>::iterator it = vh.begin();
	while (it != vh.end())
	{
		cout << *(it->ps) << endl;
		++it;
	}
}

int main()
{
	HasPtr hp("hello"), hp2("world"), *p = new HasPtr("test");
	hp = hp2;
	hp = std::move(*p);

	return 0;
}