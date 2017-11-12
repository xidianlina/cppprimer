#include<iostream>  
#include<string>  
  
using namespace std;

class Date
{
public:
	unsigned _year;
	unsigned _month;
	unsigned _day;
	void _show()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
	
	Date(string);
};

Date::Date(string s)
{
	int flag = 0;
	string number = "0123456789/";
	string coma = ",";
	string month;
	unsigned pos, pos1, pos2, pos3;
	unsigned _pos, _pos1;

	/*利用一个判断，现判定怎样初始化*/
	if ((pos = s.find_first_not_of(number)) == string::npos)
	{
		flag = 1;
	}
	if ((pos = s.find_first_of(coma)) != string::npos)
	{
		flag = 2;
	}

	switch (flag)
	{
	case 1:/*处理1/1/1991的格式*/
		pos1 = 0;
		pos1 = s.find_first_of("/", pos1);
		_day = stoul(s.substr(0, pos1));//先截取目标字符串，再将字符串转化为unsigned  
		pos2 = ++pos1;
		pos1 = s.find_first_of("/", pos1);
		_month = stoul(s.substr(pos2, pos1));
		pos3 = ++pos1;
		_year = stoul(s.substr(pos3, s.size() - 1));
		break;
	case 2:/*处理January 1,1900的格式*/
		_pos;
		_pos = s.find_first_of(number);
		month = s.substr(0, _pos);
		  
		if (month == "January ") _month = 1;
		if (month == "February ") _month = 2;
		if (month == "March ") _month = 3;
		if (month == "April ") _month = 4;
		if (month == "May ") _month = 5;
		if (month == "June ") _month = 6;
		if (month == "July ") _month = 7;
		if (month == "August ") _month = 8;
		if (month == "September ") _month = 9;
		if (month == "October ") _month = 10;
		if (month == "November ") _month = 11;
		if (month == "December ") _month = 12;

		_pos1 = ++_pos;
		_pos = s.find_first_of(number, _pos);
		_day = stoul(s.substr(_pos1 - 1, _pos));

		_year = stoul(s.substr(_pos, s.size() - 1));
		break;
	case 0:/*处理Jan 1 1995的格式*/
		_pos;
		_pos = s.find_first_of(number);
		month = s.substr(0, _pos);
		if (month == "Jan ") _month = 1;
		if (month == "Feb ") _month = 2;
		if (month == "Mar ") _month = 3;
		if (month == "Apr ") _month = 4;
		if (month == "May ") _month = 5;
		if (month == "Jun ") _month = 6;
		if (month == "Jul ") _month = 7;
		if (month == "Aug ") _month = 8;
		if (month == "Sep ") _month = 9;
		if (month == "Oct ") _month = 10;
		if (month == "Nov ") _month = 11;
		if (month == "Dec ") _month = 12;

		_pos1 = ++_pos;
		_pos = s.find_first_of(number, _pos);
		_day = stoul(s.substr(_pos1 - 1, _pos));

		_year = stoul(s.substr(_pos, s.size() - 1));
		break;
	}
}

int main(int argc, char**argv)
{
	Date _today("25/2/2017");
	_today._show();

	Date _tomorrow("January 1,1995");
	_tomorrow._show();

	Date _2tomorrow("Jan 1 1995");
	_2tomorrow._show();

	return 0;
}