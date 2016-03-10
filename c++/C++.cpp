//参考： http://www.learncpp.com/cpp-tutorial/85-constructors/
//http://c.biancheng.net/cpp/biancheng/cpp/jichu/
//http://c.biancheng.net/cpp/biancheng/cpp/rumen/
//http://www.prglab.com/
//http://www.runoob.com/cplusplus/cpp-tutorial.html
//http://www.learncpp.com/

#include <iostream>
int main_00() {
	int x, y;
	std::cin >> x >> y; //std是标准名字空间
	std::cout << x << " " << y << '\n';
	return 0;
}

//----------C++有一个string类型,表示字符串---------
#include <string>
using std::string; //引入标准名字空间std中定义的名字string
int main_01() {
	std::string s1, s2(" world");
	s1 = "hello";
	string s3 = s1 + s2;
	std::cout << s3 << "\n";
	return 0;
}

//--------C++类不同于C语言的结构的显著区别在于C++的类除数据属性外，还有函数属性或成员-------
//定义了一个叫做student的类，这个类就是一个数据类型，如同int类型一样
//可以定义这里类型student的变量，如student stu;
struct student {
	int id;
	double score;

	//C++的类除了有数据成员，还有函数成员，即具有一定的功能或行为。
	int get_id() { return id; }
	double get_score() { return score; }
};

int main_10() {
	student stu;
	stu.id = 12;
	stu.score = 60.5;
	std::cout << stu.id << " " << stu.score << "\n";
	std::cout << stu.get_id() << " " << stu.get_score() << "\n";
	return 0;
}

//---------定义类的关键字有class,struct, enum-------------------
//除了用struct关键字定义类外，我们也可以用class关键字定义类
class Box
{
public:
	double length;   // Length of a box
	double width;  // Breadth of a box
	double height;   // Height of a box
	//定义个求长方体盒子的面积函数
	double area() {
		return length*width*height;
	}
};

int main_11() {
	Box box; //box是Box类型的一个变量，也称为对象。在C++里变量和对象是一个意思
	box.length = 2.5;
	box.width = 4;
	box.height = 3;

	//调用box对应类Box的成员函数，可以获得box对象的面积
	std::cout <<"这个box的面积是 :"<< box.area()<< "\n";
	return 0;
}

//----------------访问控制---------------------------------
//类定义的访问控制修饰符public,protected,private可以控制类成员是否能被外部函数访问
//public表示是“公开的”，外部都可以直接通过该类对象的这些public属性
//private表示“私有的”，即只能被该类自己的成员函数访问，不能被外部函数访问
//从而可以通过private这个修饰符对外界屏蔽某些属性，从而隐藏和保护了这些数据。
class BBox
{
private:  //length,width,height都是私有数据，外界不能直接访问他们
	double length;   // Length of a box
	double width;  // Breadth of a box
	double height;   // Height of a box
public:
	//定义个求长方体盒子的面积函数，因为是公开的，可以被外界调用
	double area() {
		return length*width*height;
	}
	void set(double l, double w, double h) {
		length = l; 		width = w; 		height = h;
	}
};

int main_12() {
	BBox box;
	/*
	box.length = 2.5; //错！，main函数不是Box类的成员函数，
	                  // 是一个外部函数，不能访问box的length成员
	*/

	box.set(2.5, 4, 3); //可以通过Box的公开函数set来修改box变量的数据

	std::cout << "这个box的面积是 :" << box.area() << "\n";
	return 0;
}

//--------------------------------------
//用struct定义的类成员默认是公开的，而class定义类的成员默认是私有的
class BBBox
{
	//下列所有成员(包括函数成员)默认都是私有的，都不能被外界访问
	double length;   // Length of a box
	double width;  // Breadth of a box
	double height;   // Height of a box

	//定义个求长方体盒子的面积函数，因为是公开的，可以被外界调用
	double area() {
		return length*width*height;
	}
	void set(double l, double w, double h) {
		length = l; 		width = w; 		height = h;
	}
};

//因为BBBox的所有属性都是私有的，相当于一个完全密封的黑盒子，你无法访问其任何信息或功能.
int main_13() {
	/*
	BBBox box;
	box.length = 2.5; //错，不能访问box的私有成员length
	std::cout << "这个box的面积是 :" << box.area() << "\n";
	                      //错，不能访问box的私有成员area

	*/
	return 0;
}

//------------派生
//可以从一个类如Base派生出一个新类如Derived，
//也就是说新类Derived继承了基类Base的一些属性和功能，但通常还具有自己特有的功能或行为

//定义个雇员类Employee
class Employee {
protected:    //protected声明的保护属性，不能被外界访问，但可以被派生类所继承
	string  name;
	string address;
	double salary;
public:
	void set_name(string n) { name = n; }
	void set_address(string add) {  address=add; }
	void set_salary(double s) {  salary = s; }
	string get_name() { return name; }
	string get_address() { return address; }
	double get_salary() { return salary; }
	void out() {
		std::cout << name << " " << address << " " << salary << "\n";
	}
};

//经理类Manager是一个特殊的雇员，他管理其他一定数量的雇员
//而且Manager可能是不同级别的经理,所以除雇员的一般属性外，还具有一些特定的属性
//因为Manager类是公开public继承Employee的信息，所以：
//Employee的除private私有属性外的属性如public公开或protected保护都能被继承下来
class Manager : public Employee {
	int level;  //经理的级别
public:
	void set_level(int l) { level = l; }
	int get_level() { return level; }

	//雇员的out函数发生了变化，还需要输出经理的级别信息
	void out() {
		std::cout <<level<<" "<< name << " " << address << " " << salary << "\n";
	}
};

int main_20() {
	Employee e;
	Manager m;
	e.set_name("Lipin");
	e.set_address("Zhenjiang");
	e.set_salary(1500);
	e.out();

	m.set_name("ZhangWei");
	m.set_address("Wuxi");
	m.set_salary(2500);
	m.set_level(1);
	m.out();
	return 0;
}


//------------------构造函数Constructors-----------
//1.如果类的所有成员是公开的，我们在定义该变量时，可以用初始化成员列表（initialization list）
// 或均匀初始化（uniform initialization (in C++11):）来进行初始化
class Foo
{
public:
	int m_x;
	int m_y;
};

int main_30()
{
	Foo foo1 = { 4, 5 }; // initialization list
	Foo foo2{ 6, 7 }; // uniform initialization (C++11)

	return 0;
}

//如果类存在私有的数据成员变量，则不能用上述方法初始化类对象(类变量)，
//这就需要叫做“构造函数”（constructors）的特殊成员函数来完成对类对象的初始化。
//与类名相同的成员函数叫做“构造函数”，一个类可以有多个不同的构造函数，只要它们的参数列表是不同的
//2. “默认构造函数” （Default constructors）：不带参数或参数都有默认值的构造函数

#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
public:
	Fraction() // default constructor
	{
		m_numerator = 0;
		m_denominator = 1;
	}

	int getNumerator() { return m_numerator; }
	int getDenominator() { return m_denominator; }
	double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

int main_31()
{
	Fraction frac; // Since no arguments, calls Fraction() default constructor
	std::cout << frac.getNumerator() << "/" << frac.getDenominator() << '\n';

	return 0;
}

#include <cassert>
class Fraction2
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction2() // default constructor
	{
		m_numerator = 0;
		m_denominator = 1;
	}

	// Constructor with parameters
	Fraction2(int numerator, int denominator = 1)
	{
		assert(denominator != 0);
		m_numerator = numerator;
		m_denominator = denominator;
	}

	int getNumerator() { return m_numerator; }
	int getDenominator() { return m_denominator; }
	double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

int main_32() {
	Fraction2 frac; //default constructor
	Fraction2 frac2(2,3);  //调用的是构造函数Fraction2(int numerator, int denominator = 1)
	Fraction2 frac3(4); //调用的是构造函数Fraction2(int numerator, int denominator = 1)

	std::cout << frac.getNumerator() << "/" << frac.getDenominator() << '\n';
	std::cout << frac2.getNumerator() << "/" << frac2.getDenominator() << '\n';
	std::cout << frac3.getNumerator() << "/" << frac3.getDenominator() << '\n';
	return 0;
}

class Date
{
private:
	int m_year;
	int m_month;
	int m_day;

public:
	void out() {
		std::cout << m_year << " " << m_month << " " << m_day << "\n";
	}
	Date(int year, int month, int day) // not a default constructor
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	// No default constructor provided
};

int main_33()
{
	/*
	Date date; // error: Can't instantiate object because default constructor doesn't exist
	*/
	Date today(2020, 10, 14); // today is initialized to Oct 14th, 2020

	today.out();
	return 0;
}


//--------------运算符重载 Overloading operators---

class Vector2d {
public:
	double x, y;
	Vector2d(double x0 = 0, double y0 = 0) {
		x = x0; y = y0;
	}

	Vector2d  operator+ (Vector2d b) {
		Vector2d c(x + b.x, y + b.y);
		return c;
	}

};

Vector2d add(Vector2d a, Vector2d b) {
	Vector2d c(a.x + b.x, a.y + b.y);
	return c;
}

/*
//作为外部函数，重载operator+
Vector2d operator+ (Vector2d a, Vector2d b) {
	Vector2d c(a.x + b.x, a.y + b.y);
	return c;
}
*/

int main() {
	Vector2d V1(2.5, 3.5),V2(4.5),V3;
	V3 = add(V1, V2);
	std::cout << V3.x << " " << V3.y << "\n";

	V3 = V1 + V2; // V1.operator+(V2)
	std::cout << V3.x << " " << V3.y << "\n";
	return 0;
}
