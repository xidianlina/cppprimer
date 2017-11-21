#include <iostream>    
#include <string>    
#include <sstream>    

template <typename T> std::string debug_rep(const T& t);
template <typename T> std::string debug_rep(T* p);

std::string debug_rep(const std::string &s);
std::string debug_rep(char* p);
std::string debug_rep(const char *p);

template<typename T>
std::string debug_rep(const T &s)
{
	std::ostringstream ret;
	ret << s;
	return ret.str();
}

template<typename T>
std::string debug_rep(T *p)
{
	std::ostringstream ret;
	std::cout << "point:" << s;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << "point is NULL!";
	return ret.str();
}

template<typename T>
std::ostream &print(std::ostream &os, const T &t)
{
	return os << t;
}

template<typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... args)
{
	os << t << ", ";
	return print(os, args...);
}

std::string debug_rep(const std::string &s)
{
	return '"' + s + '"';
}

std::string debug_rep(char *p)
{
	return debug_rep(std::string(p));
}

std::string debug_rep(const char *p)
{
	return debug_rep(std::string(p));
}

template<typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args... args)
{
	return print(os, debug_rep(args)...);
}

int main()
{
	using namespace std;
	string str = "c++";
	errorMsg(cout, str, "primer", 4, 8.6, '5');

	return 0;
}