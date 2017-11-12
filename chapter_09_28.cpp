#include<iostream>  
#include<string>  
#include<forward_list>  

using namespace std;

void func(forward_list<string> &, string, string);

int main()
{
	forward_list<string> flist{ "I","like","java","and","cpp","!" };
	string a = "javaa";
	string b = "sad";

	func(flist, a, b);

	forward_list<string>::iterator it1 = flist.begin();
	for (it1; it1 != flist.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;

	return 0;
}

void func(forward_list<string> &flist, string target, string str)
{
	forward_list<string>::iterator it1 = flist.before_begin();
	forward_list<string>::iterator it2 = flist.begin();

	bool flag = false;
	for (it2; it2 != flist.end(); it1 = it2++)
	{
		if (*it2 == target)
		{
			flist.insert_after(it2, str);
			flag = true;
		}
	}

	if (!flag)
	{
		flist.insert_after(it1, str);
	}
}