#include <iostream>    
#include <string>    
#include <memory> 
#include <utility>    
#include <initializer_list>    
#include <algorithm>  

class StrVec
{
	std::allocator<std::string> alloc; 

	void chk_n_alloc()         
	{
		if (size() == capacity())
			reallocate();
	}
	std::pair<std::string *, std::string *> alloc_n_copy(const std::string *b, const std::string *e);  
	void free();  
	void reallocate();  
	std::string *elements;
	std::string *first_free;
	std::string *cap;
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<std::string> il);
	StrVec(const StrVec &s);
	StrVec(StrVec &&s);
	StrVec &operator=(StrVec &&s);
	StrVec &operator=(const StrVec &s);

	template<typename... Args>                
	void emplace_back(Args&&... args)
	{
		chk_n_alloc();
		alloc.construct(first_free++, std::forward<Args>(args)...);
	}

	bool operator==(const StrVec &s) 
	{
		if (size() != s.size())
			return false;
		auto it = elements, its = s.elements;
		while (it != first_free)
		{
			if (*it++ != *its++)
				return false;
		}
		return true;
	}
	bool operator!=(const StrVec &s) 
	{
		return !(*this == s);
	}
	bool operator<(const StrVec &s)  
	{
		if (size()>s.size())
			return false;
		else if (size() < s.size())
			return true;
		for (auto it = elements, its = s.elements; it != first_free; ++it, ++its)
		{
			if (*it == *its)
				continue;
			else if (*it > *its)
				return false;
			else
				return true;
		}
		return false;
	}

	bool operator>(const StrVec &s)   
	{
		return !(*this < s) && *this != s;
	}

	bool operator<=(const StrVec &s)   
	{
		return !(*this > s);
	}

	bool operator>=(const StrVec &s)  
	{
		return !(*this < s);
	}

	StrVec &operator=(std::initializer_list<std::string> il)
	{
		auto nobj = alloc_n_copy(il.begin(), il.end());
		free();
		elements = nobj.first;
		first_free = cap = nobj.second;
		return *this;
	}

	std::string &operator[](std::size_t n)
	{
		return elements[n];
	}

	const std::string &operator[](std::size_t n)const
	{
		return elements[n];
	}

	~StrVec();
	void push_back(const std::string &s);

	size_t size()const
	{
		return first_free - elements;
	}
	size_t capacity()const
	{
		return cap - elements;
	}
	std::string *begin()const
	{
		return elements;
	}
	std::string *end()const
	{
		return first_free;
	}
};

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();    
	alloc.construct(first_free++, s);    
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);    
	return{ data, std::uninitialized_copy(b, e, data) }; 
}

void StrVec::free()
{
	if (elements)   
	{
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - first_free);
	}
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;    
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) :elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&s)
{
	if (this == &s)
		return *this;
	free();
	elements = s.elements;
	first_free = s.first_free;
	cap = s.cap;
	s.elements = s.first_free = s.cap = nullptr;
	return *this;
}

StrVec::~StrVec()
{
	free(); 
}

StrVec &StrVec::operator=(const StrVec &s)
{
	if (this == &s)
		return *this;
	auto data = alloc_n_copy(s.elements, s.first_free);
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;    
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;    
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));   
	free();               
	elements = newdata;  
	first_free = dest;           
	cap = elements + newcapacity;      
}