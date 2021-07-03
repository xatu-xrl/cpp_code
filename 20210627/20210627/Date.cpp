#include<iostream>
using namespace std;

class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		//判断日期是否有效
		if (y <= 0 || m <= 0 || m > 12
			|| d <= 0 || d > getDay(y, m))
		{
			_y = 1;
			_m = 1;
			_d = 1;
			cout << "日期无效 ， 设为默认值 ： 1-1-1" << endl;
		}
		else
		{
			_y = y;
			_m = m;
			_d = d;
		}

	}

	int getDay(int y, int m)
	{
		static int days[] = { 0, 31, 28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[m];
		//如果是如年的二月 修改
		if (m == 2 && (((m % 4 == 0) && (m % 100 != 0)) || m % 400 ==0))
			day +=1;
		return day;
	}

	//日期运算
	//Date += int 左操作数发生变化 返回相加之后的值
	Date& operator +=(int day)
	{
		//判断是不是负数
		if (day < 0)
			return *this -= -day;
		//Date :2021.7.2
		//day:1 30 90 365
		_d += day;
		//判断天数是否溢出
		while (_d > getDay(_y, _m))
		{
			_d += getDay(_y, _m);

			++_m;
			if (_m == 13)
			{
				++_y;
				_m = 1;
			}
		}
		return *this;
	}

	//++Date
	Date& operator++()
	{
		return *this += 1;
	}
	//Date++
	Date operator++(int)//只是为了区分 没有实际的作用 
	{
		Date copy(*this);
		*this += 1;
		return copy;
	}

	Date& operator-=(int day)
	{
		//判断是否为负数
		if (day < 0)
			return *this += -day;
		//2021.2.5 - 90 :2021.2.-85 + 31-->2021.1.-54 + 31-->2020.12.-23 +30-->2021.11.7
		_d -= day;
		while (_d <= 0)
		{
			//用上一个月的天数回补
			--_m;
			//判断月份是否向下溢出
			if (_m == 0)
			{
				_y--;
				_m = 12;
			}
			_d += getDay(_y, _m);
		}
		return *this;
	}

	Date operator-(int day)
	{
		Date copy(*this);
		copy -= day;
		return copy;
	}

	//--Date
	Date& operator--()
	{
		return *this -= 1;
	}

	//Date--
	Date operator--(int)
	{
		Date copy(*this);
		*this -= 1;
		return copy;
	}

	//==
	bool operator==(const Date& d)
	{
		return _y == d._y
		&& _m == d._m
		&& _d == d._d;
	}
	//!=
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	//>
	bool operator > (const Date& d)
	{
		if (_y > d._y)
			return true;
		else if (_y == d._y)
		{
			if (_m > d._m)
				return true;
			else if (_m == d._m)
			{
				if (_d > d._d)
					return true;
			}
		}
		return false;
	}
	//<
	bool operator<(const Date& d)
	{
		return !(*this >= d);
	}
	//>=
	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;
	}
	//<=
	bool operator<=(const Date& d)
	{
		return !(*this > d);
	}

	//Date - Date 返回差值 差几天
	int operator-(const Date& d)//函数重载了
	{
		//一直加等 也可以计算多少次自加的运算次数
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (max < min) //operator<
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max)//operator<
		{
			++min;//operator++
			++day;
		}
		return flag * day;
	}
	

private:
	int _y;
	int _m;
	int _d;
};

void test()
{
	Date d1(2021, 2, 5);
	Date d2(2021, 2, 5);
	Date d3(2021, 2, 5);
	Date d4(2021, 2, 5);

	d1 -= 1;
	d1 -= 30;
	d1 -= 90;
	d1 -= 360;

	//-=-1 +=-1 循环条件不满足 得加判断条件
}

int main()
{
	test();
	return 0;
}