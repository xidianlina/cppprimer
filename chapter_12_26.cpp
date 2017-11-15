#include <iostream>
#include <string>
#include <memory>

int main()
{
	using namespace std;

	string s;
	allocator<string> alloc;
	auto p = alloc.allocate(10);
	auto q = p;
	while (cin >> s&&q != p + 10)
		alloc.construct(q++, s);
	while (q != p)
		alloc.destroy(--q);
	alloc.deallocate(p, 10);

	return 0;
}