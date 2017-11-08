#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int main()
{
	using std::cout;
	using std::endl;
	
	const char str1[] = "hello";
	const char str2[] = "world";
	char res[20];

	strcpy(res, str1);
	strcat(res, " ");
	strcat(res, str2);

	cout << str1 << endl << str2 << endl << res << endl;

	return 0;
}