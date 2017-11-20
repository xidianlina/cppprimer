class  Base
{
public:
	void pub_mem();
protected:
	int pro_mem();
private:
	char pri_mem();
};

class Pub_derv :public Base
{
	void memfcn(Base &b) { b = *this; }

	int f() { return pro_mem(); }

	//错误，私有成员不可访问  
	char g() { return pri_mem(); }
};
class Pri_derv :private Base
{
	void memfcn(Base &b) { b = *this; }

	int f1() { return pro_mem(); }

	//错误，私有成员也不可访问  
	char g1() { return pri_mem(); }
};
class Pro_derv :protected Base
{
	void memfcn(Base &b) { b = *this; }
	int f2() { return pro_mem(); }

	//错误，私有成员也不可访问  
	char g3() { return pri_mem(); }
};

class Derivated_from_Public :public Pub_derv
{
	void memfcn(Base &b) { b = *this; }
	int use() { return pro_mem(); }
};
class Derivated_from_Protected :public Pro_derv
{
	void memfcn(Base &b) { b = *this; }
	int use() { return pro_mem(); }
};
class Derivated_from_Private :public Pri_derv
{
	void memfcn(Base &b) { b = *this; }
	//错误，不可访问  
	int use() { return pro_mem(); }
};

int main()
{
	Pub_derv d1;
	Pri_derv d2;
	Pro_derv d3;
	Derivated_from_Public dd1;
	Derivated_from_Protected dd2;
	Derivated_from_Private dd3;
	d1.pub_mem();
	d2.pub_mem();//错误，不可访问，该对象成员都为私有
	Base *p = &d1;
	p = &d2;//不允许对不可访问的基类进行转换  
	p = &d3;//不允许对不可访问的基类进行转换  
	p = &dd1;
	p = &dd2;//不允许对不可访问的基类进行转换  
	p = &dd3;//不允许对不可访问的基类进行转换  

	return 0;
}