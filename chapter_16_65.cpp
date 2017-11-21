#include <string>

template<typename T>
std::string debug_rep(T *t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}
template<>
std::string debug_rep(char *t)
{
	return std::string(t);
}
template<>
std::string debug_rep(const char *t)
{
	return std::string(t);
}