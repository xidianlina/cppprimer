#include <vector>  
#include <iostream>  
#include <algorithm>  

using std::vector;
using std::sort;

class Foo {
public:
	Foo() :data(0) {};
	Foo(vector<int> vi):data(vi){}
	Foo sorted() && ;
	Foo sorted() const&;
private:
	vector<int> data;
};

Foo Foo::sorted() &&
{
	sort(data.begin(), data.end());
	std::cout << "&&" << std::endl; 
	return *this;
}

Foo Foo::sorted() const &
{
	/*Foo ret(*this);  
	std::cout << "const &" << std::endl;
	return ret.sorted();*/

	std::cout << "const &" << std::endl;
	return Foo(*this).sorted();
}

int main()
{
	Foo().sorted(); // call "&&"  
	Foo f;
	f.sorted();
	return 0;
}