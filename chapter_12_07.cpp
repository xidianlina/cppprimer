#include <iostream>  
#include <vector>  
#include<memory>  

using namespace std;

shared_ptr<vector<int>> vector_declare()
{
	shared_ptr<vector<int>> ptr(new vector<int>);
	return ptr;
}

void vector_assign(shared_ptr<vector<int>> ptr)
{
	int val;
	while (cin >> val)
		ptr->push_back(val);
}

void vector_print(shared_ptr<vector<int>> ptr)
{
	for (size_t i = 0; i < (*ptr).size(); ++i)
		cout << (*ptr)[i] << " ";
	cout << endl;
}

int main()
{
	shared_ptr<vector<int>> my_ptr = vector_declare();
	vector_assign(my_ptr);
	vector_print(my_ptr);

	return 0;
}