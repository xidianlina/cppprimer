#include <iostream>
#include <string>
#include <memory>

class DebugDelete
{
public:
	DebugDelete(std::ostream &s=std::cerr):os(s){}
	template <typename T> void operator()(T *p)const
	{
		os << "deleting ptr" << std::endl;
		delete p;
	}
private:
	std::ostream &os;
};

int main()
{
	double *p = new double;
	DebugDelete d;
	d(p);
	int *ip = new int;
	DebugDelete()(ip);
	//std::unique_ptr<int, DebugDelete> p(new int, DebugDelete());
	std::unique_ptr<std::string, DebugDelete> sp(new std::string, DebugDelete());

	return 0;
}