#include<iostream>    
#include<string>    
#include<fstream>  
#include<vector>   
#include<map>    
#include<cctype>
#include<algorithm>

using namespace std;

int main()
{
	map<string, size_t> word_count;
	fstream in("test.txt");
	string word;

	while (in >> word)
	{
		string::iterator it;
		for (it = word.begin(); it != word.end(); ++it)
		{
			*it = tolower(*it);
		}
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end()); 
		++word_count[word];
	}

	map<string, size_t>::iterator mapi;
	for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)  
	{
		cout << mapi->first << " occurs ";
		cout << mapi->second << (mapi->second == 1 ? " time" : " times") << endl;
	}

	return 0;
}