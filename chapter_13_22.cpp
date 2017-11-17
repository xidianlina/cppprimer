#include <string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string&s=string()) :ps(new string(s)), i(0) {};
	HasPtr(const HasPtr& p) :ps(new string(*p.ps)), i(p.i) {}
	HasPtr& operator=(const HasPtr& p)
	{
		auto new_ps = new string(*p.ps);;
		delete ps;
		ps = new_ps;
		i = p.i;
		return *this;
	}
	~HasPtr() { delete ps; }
private:
	string *ps;
	int i;
};