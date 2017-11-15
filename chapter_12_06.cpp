#include <iostream>  
#include <vector>  
#include<memory>  

using namespace std;

vector<int>* vector_declare()
{
	vector<int> *ptr(new vector<int>);
	return ptr;
}

void vector_assign(vector<int> *ptr)
{
	int val;
	while (cin >> val)
		ptr->push_back(val);
}

void vector_print(vector<int> *ptr)
{
	for (size_t i = 0; i < (*ptr).size(); ++i)
		cout << (*ptr)[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> *my_ptr = vector_declare();
	vector_assign(my_ptr);
	vector_print(my_ptr);
	delete my_ptr;

	return 0;
}