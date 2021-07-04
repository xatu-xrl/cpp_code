#include<iostream>
using namespace std;

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		//const 引用必须在定义的时候初始化
//		//初始化列表：真正初始化的位置
//		//const,引用成员必须在初始化列表中初始化
//		//const,引用成员定义的地方初始化列表
//		//如果自定义成员没有默认构造，自定义必须在初始化列表中显式初始化
//		: _year(year)
//		, _month(month)
//		, _day(day)
//		, _hour(12)
//	{
//		//并不是初始化 只能将其称作为赋初值
//	/*	_year = year;
//		_month = month;
//		_day = day;*/
//	}
//private:
//	int& _year;
//	int& _month;
//	int& _day;
//	const int _hour;
//};

//void test()
//{
//	Date d(2021,7,3);
//}



// 成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//}
//
//void test2()
//{
//	A aa(1);
//	aa.Print();
//}

//用explicit修饰构造函数，将会禁止单参构造函数的隐式转换
//单参构造函数的隐式转换
// aboj3 = 40;
//1.用40，调用构造函数创建一个匿名对象
//2.调用赋值运算符，把匿名对象的内容付给左操作数


//静态成员 静态的成员变量一定要在类外进行初始化

//1. 静态成员为所有类对象所共享，不属于某个具体的实例
//2. 静态成员变量必须在类外定义，定义时不添加static关键字
//3. 类静态成员即可用类名::静态成员或者对象.静态成员来访问
//4. 静态成员函数没有隐藏的this指针，不能访问任何非静态成员
//5. 静态成员和类的普通成员一样，也有public、protected、private3种访问级别，也可以具有返回值

//cout<<A::GetACount()<<endl 第二种访问形式 类似于整个类中的全局变量

//1. 静态成员函数不可以调用非静态成员函数 静态成员函数不包含this指针 
// 静态函数可以通过类名访问，通过类名访问时，没有对象，this没有指向
//2. 非静态成员函数可以调用类的静态成员函数

class A
{
public:
	/*A(int a)
		:_a(a)
	{

	}*/
private:
	//c++11 新的初始化方式：在变量声明时，给一个缺省值 只限于非静态成员
	int _a = 0;
};

//友元函数可以直接访问类的私有成员，它是定义在类外部的普通函数，不属于任何类，但需要在类的内部声明，声明时需要加friend关键字
//此函数是一个普通函数，不使用类的成员函数
//友元的声明可以放在类的地方

class Date
{
	//友元函数的声明
	friend ostream& operator<<(ostream& _cout, const Date& d);
	
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

void test()
{
	Date d(2021, 3, 7);
	//简写
	cout << d;
	//完整
	operator<<(cout, d);
	//连续输出
	cout << d << endl;
	operator << (cout, d) << endl;

	cout << d << d;
	operator<<(operator<<(cout, d), d);

}

//友元关系是单向的
// 友元关系不能传递
//友元类的所有成员函数都可以是另一个类的友元函数，都可以访问另一个类中的非公有成员


//相比于友元类 内部类可以直接访问外部的静态staic成员
//内部类可以通过外部类的访问权限，限制内部类的可见范围
// 
//内部类是独立于外部类的 只是作用域在外部类之中
// 定义的位置会影响可见范围 定义在private外部不可见
//sizeof求得的是独立的外部类
// 
//内部类时外部类的友元类 相反则不是 不能访问内部类的私有成员

//封装：相关的数据以及行为定义在一起