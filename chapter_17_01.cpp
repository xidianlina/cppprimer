#include <iostream>
#include <tuple>
#include <string>

int main()
{
	using namespace std;

	auto item = make_tuple(10, 20, 30);
	typedef decltype(item) trans;
	size_t sz=tuple_size<trans>::value;
	tuple_element<1, trans>::type cnt = get<1>(item);

	tuple<int, string, double> tp{ 40,"hello",70.99 };
	size_t size = tuple_size < tuple<int, int, int>>::value;
	tuple_element < 1, tuple<int, string, double>>::type count = get<1>(tp);

	cout << sz << " " << cnt << endl;
	cout << size << " " << count << endl;

	return 0;
}