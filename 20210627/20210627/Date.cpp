#include<iostream>
using namespace std;

class Date
{
public:
	Date(int y = 1, int m = 1, int d = 1)
	{
		//�ж������Ƿ���Ч
		if (y <= 0 || m <= 0 || m > 12
			|| d <= 0 || d > getDay(y, m))
		{
			_y = 1;
			_m = 1;
			_d = 1;
			cout << "������Ч �� ��ΪĬ��ֵ �� 1-1-1" << endl;
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
		//���������Ķ��� �޸�
		if (m == 2 && (((m % 4 == 0) && (m % 100 != 0)) || m % 400 ==0))
			day +=1;
		return day;
	}

	//��������
	//Date += int ������������仯 �������֮���ֵ
	Date& operator +=(int day)
	{
		//�ж��ǲ��Ǹ���
		if (day < 0)
			return *this -= -day;
		//Date :2021.7.2
		//day:1 30 90 365
		_d += day;
		//�ж������Ƿ����
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
	Date operator++(int)//ֻ��Ϊ������ û��ʵ�ʵ����� 
	{
		Date copy(*this);
		*this += 1;
		return copy;
	}

	Date& operator-=(int day)
	{
		//�ж��Ƿ�Ϊ����
		if (day < 0)
			return *this += -day;
		//2021.2.5 - 90 :2021.2.-85 + 31-->2021.1.-54 + 31-->2020.12.-23 +30-->2021.11.7
		_d -= day;
		while (_d <= 0)
		{
			//����һ���µ������ز�
			--_m;
			//�ж��·��Ƿ��������
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

	//Date - Date ���ز�ֵ ���
	int operator-(const Date& d)//����������
	{
		//һֱ�ӵ� Ҳ���Լ�����ٴ��Լӵ��������
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

	//-=-1 +=-1 ѭ������������ �ü��ж�����
}

int main()
{
	test();
	return 0;
}