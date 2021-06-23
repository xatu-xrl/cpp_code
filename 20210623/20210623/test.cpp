#include<iostream>
using namespace std;

//类与对象

//数据和相关行为全部定义在一起 定义一个c++的类 和结构体定义方式一样
//pubilc公有成员在类外可见
//private私有成员在类外不可见 protected也是
class Student
{
	public://访问权限
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;
};


//访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止
//在类中 访问权限修饰符 成员之间可以相互访问

//C++中struct和class的区别
//C++需要兼容C语言，所以C++中struct可以当成结构体去使用。另外C++中struct还可以用来定义类。
//和class是定义类是一样的，区别是struct的成员默认访问方式是public，class是struct的成员默认访问方式
//是private。

//面向对象的三大特性：封装、继承、多态。
//在类和对象阶段，我们只研究类的封装特性，那什么是封装呢？
//封装：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来和对象进行
//交互。
//封装本质上是一种管理：我们如何管理兵马俑呢？比如如果什么都不管，兵马俑就被随意破坏了。那么我们
//首先建了一座房子把兵马俑给封装起来。但是我们目的全封装起来，不让别人看。所以我们开放了售票通
//道，可以买票突破封装在合理的监管机制下进去参观。类也是一样，我们使用类数据和方法都封装到一下。
//不想给别人看到的，我们使用protected / private把成员封装起来。开放一些共有的成员函数对成员合理的访
//问。所以封装本质是一种管理。

//类定义了一个新的作用域，类的所有成员都在类的作用域中。在类体外定义成员，需要使用::作用域解析符
//指明成员属于哪个类域 通过.的形式


//用类类型创建对象的过程，称为类的实例化
//1. 类只是一个模型一样的东西，限定了类有哪些成员，定义出一个类并没有分配实际的内存空间来存储它
//2. 一个类可以实例化出多个对象，实例化出的对象 占用实际的物理空间，存储类成员变量
//3. 做个比方。类实例化出对象就像现实中使用建筑设计图建造出房子，类就像是设计图，只设计出需要什
//么东西，但是并没有实体的建筑存在，同样类也只是一个设计，实例化出的对象才能实际存储数据，占
//用物理空间


//类大小计算 按照和结构体一样大小计算
// 不包含函数 空类的大小 一个字节 
// 成员的函数不占对象空间  放在代码段
// 都是类实例化后 ，对象的大小
// 类中既有成员变量，又有成员函数
class A1 {
public:
	void f1() {}
private:
	int _a;
};
// 类中仅有成员函数
class A2 {
public:
	void f2() {}
};
// 类中什么都没有---空类
class A3
{};

//判断当前机器是采用大端还是小端
void test3()
{
	int a = 1;
	char* pa = (char*)&a;
	if (*pa)
		cout << "小端" << endl;
	else
		cout << "大端" << endl;
}

struct A
{
	int a = 10;
	int b = 10;
	double d;
	int e;
};//24

struct B
{
	char a;
	double d;
	char e;
	A objA;
};

//每个变量都要对齐到对其书的整数倍
//对齐数是  默认对齐数和该变量的较小值
// 结构体总大小为：最大对齐数（所有变量类型最大者与默认对齐参数取最小）的整数倍
// 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是
//所有最大对齐数（含嵌套结构体的对齐数）的整数倍。

//为什么存在内存对齐 ?
//1. 平台原因(移植原因)： 不是所有的硬件平台都能访问任意地址上的任意数据的；某些硬件平台只能
//在某些地址处取某些特定类型的数据，否则抛出硬件异常。
//2. 性能原因： 数据结构(尤其是栈)应该尽可能地在自然边界上对齐。 原因在于，为了访问未对齐的
//内存，处理器需要作两次内存访问；而对齐的内存访问仅需要一次访问。
//总体来说：
//结构体的内存对齐是拿空间来换取时间的做法。

//pragma pack(1)  修改默认对齐数的大小

//this

class Date
{
public:
	//每一个非静态成员函数中，都有一个this指针
	//作为函数第一个形参
	//this指向当前调用此函数的对象
	// this指针的类型：类类型* const this
	void Display()//编译器底层操作  void Display(this)
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void SetDate(int year, int month, int day)//void SetDate(this,int year, int month, int day)
	{
		//地下也是 this->_year = year;
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};
int main()
{
	Date d1, d2;
	d1.SetDate(2021, 5, 1);
	d2.SetDate(2021, 7, 1);
	d1.Display();
	d2.Display();
	return 0;
}

//this 一般放在寄存器中（最高的 紧挨cpu）
