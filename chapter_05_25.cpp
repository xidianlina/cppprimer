#include <iostream>  
#include <stdexcept>

using namespace std;

int main()
{
	int a, b;
	cout << "���������������������";
	while (cin >> a >> b)
	{
		try
		{
			if (b == 0) throw std::runtime_error("����������Ϊ0");  
			cout << static_cast<double>(a) / b << endl;  
		}
		catch (runtime_error err) 
		{
			cout << err.what(); 
			cout << "\n�Ƿ���Ҫ��������? Enter y or n:" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break; 
		} 
	}

	return 0;
}