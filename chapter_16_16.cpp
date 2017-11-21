#include <iostream>    
#include <string>    
#include <memory>   
#include <initializer_list>    
#include <algorithm> 

template<class T>
class StrVec
{
	std::allocator<T> alloc;  
	void chk_n_alloc()      
	{
		if (size() == capacity())
			reallocate();
	}
	std::pair<T *, T *> alloc_n_copy(const T *b, const T *e);    
	void free();
	void reallocate();  
	T *elements;
	T *first_free;
	T *cap;
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(std::initializer_list<T> il);
	StrVec(const StrVec &s);
	StrVec(StrVec &&s);
	StrVec &operator=(StrVec &&s);
	StrVec &operator=(const StrVec &s);
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
		else if (size() < s.size)
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
	StrVec &operator=(std::initializer_list<T> il)
	{
		auto nobj = alloc_n_copy(il.begin(), il.end());
		free();
		elements = nobj.first;
		first_free = cap = nobj.second;
		return *this;
	}
	T &operator[](std::size_t n)
	{
		return elements[n];
	}
	const T &operator[](std::size_t n)const
	{
		return elements[n];
	}
	~StrVec();
	void push_back(const T &s); 
	size_t size()const
	{
		return first_free - elements;
	}
	size_t capacity()const
	{
		return cap - elements;
	}
	T *begin()const
	{
		return elements;
	}
	T *end()const
	{
		return first_free;
	}
	template<class TT>
	friend std::ostream &operator<<(std::ostream &os, const StrVec<TT> &s);
};

template<class T>
void StrVec<T>::push_back(const T &s)
{
	chk_n_alloc();   
	alloc.construct(first_free++, s);    
}
template<class T>
std::pair<T *, T *> StrVec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto data = alloc.allocate(e - b);    
	return{ data, std::uninitialized_copy(b, e, data) };    
}
template<class T>
void StrVec<T>::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);    
							       
		alloc.deallocate(elements, cap - first_free);   
	}
}
template<class T>
StrVec<T>::StrVec(std::initializer_list<T> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
template<class T>
StrVec<T>::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());    
	elements = newdata.first;    
	first_free = cap = newdata.second;    
}
template<class T>
StrVec<T>::StrVec(StrVec &&s) :elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}
template<class T>
StrVec<T> &StrVec<T>::operator=(StrVec &&s)
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
template<class T>
StrVec<T>::~StrVec()
{
	free();
}
template<class T>
StrVec<T> &StrVec<T>::operator=(const StrVec &s)
{
	if (this == &s)
		return *this;
	auto data = alloc_n_copy(s.elements, s.first_free);
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
template<class T>
void StrVec<T>::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;  
	auto newdata = alloc.allocate(newcapacity);    
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));    
	}                                                   
	free();                 
	elements = newdata;     
	first_free = dest;          
	cap = elements + newcapacity;   
}
template<class TT>
std::ostream &operator<<(std::ostream &os, const StrVec<TT> &s)
{
	for (auto x : s)
		std::cout << x;
	return os;
}