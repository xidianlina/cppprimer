#include <iostream>
#include <fstream>
#include "StrBlobPtr.h"

int main()
{
	using namespace std;

	ifstream in("test.txt");
	string s;
	StrBlob blob;
	int cnt = 0;
	while (getline(in, s))
	{
		blob.push_back(s);
		cnt++;
	}

	StrBlobPtr ptr(blob);
	for(int i=0;i<cnt;++i)
	{
		cout << ptr.deref() << endl;
		ptr.incr();
	}

	return 0;
}