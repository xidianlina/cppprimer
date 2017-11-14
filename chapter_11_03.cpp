#include<iostream>    
#include<string>    
#include<fstream> 
#include<map>    

using namespace std;

int main()
{
	map<string, size_t> word_count;
	fstream in("test.txt");
	string word;

	while (in >> word)
		++word_count[word];

	map<string, size_t>::iterator mapi;
	for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)
	{
		cout << mapi->first << " occurs ";
		cout << mapi->second << (mapi->second == 1 ? " time" : " times") << endl;
	}

	return 0;
}