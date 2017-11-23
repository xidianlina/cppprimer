#include <iostream>
#include <cstdlib>

void *operator new(std::size_t n)
{
	std::cout << "new(size_t)" << std::endl;
	if (void *mem = malloc(n))
		return mem;
	else
		throw std::bad_alloc();
}

void operator delete(void *mem)noexcept
{
	std::cout << "delete(void*)" << std::endl;
	free(mem);
}

int main()
{
	using namespace std;

	int *p = new int(486);
	cout << p << " " << *p << endl;
	delete p;

	return 0;
}