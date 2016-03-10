//�ο��� http://www.learncpp.com/cpp-tutorial/85-constructors/
//http://c.biancheng.net/cpp/biancheng/cpp/jichu/
//http://c.biancheng.net/cpp/biancheng/cpp/rumen/
//http://www.prglab.com/
//http://www.runoob.com/cplusplus/cpp-tutorial.html
//http://www.learncpp.com/

#include <iostream>
int main_00() {
	int x, y;
	std::cin >> x >> y; //std�Ǳ�׼���ֿռ�
	std::cout << x << " " << y << '\n';
	return 0;
}

//----------C++��һ��string����,��ʾ�ַ���---------
#include <string>
using std::string; //�����׼���ֿռ�std�ж��������string
int main_01() {
	std::string s1, s2(" world");
	s1 = "hello";
	string s3 = s1 + s2;
	std::cout << s3 << "\n";
	return 0;
}

//--------C++�಻ͬ��C���ԵĽṹ��������������C++��������������⣬���к������Ի��Ա-------
//������һ������student���࣬��������һ���������ͣ���ͬint����һ��
//���Զ�����������student�ı�������student stu;
struct student {
	int id;
	double score;

	//C++������������ݳ�Ա�����к�����Ա��������һ���Ĺ��ܻ���Ϊ��
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

//---------������Ĺؼ�����class,struct, enum-------------------
//������struct�ؼ��ֶ������⣬����Ҳ������class�ؼ��ֶ�����
class Box
{
public:
	double length;   // Length of a box
	double width;  // Breadth of a box
	double height;   // Height of a box
	//������󳤷�����ӵ��������
	double area() {
		return length*width*height;
	}
};

int main_11() {
	Box box; //box��Box���͵�һ��������Ҳ��Ϊ������C++������Ͷ�����һ����˼
	box.length = 2.5;
	box.width = 4;
	box.height = 3;

	//����box��Ӧ��Box�ĳ�Ա���������Ի��box��������
	std::cout <<"���box������� :"<< box.area()<< "\n";
	return 0;
}

//----------------���ʿ���---------------------------------
//�ඨ��ķ��ʿ������η�public,protected,private���Կ������Ա�Ƿ��ܱ��ⲿ��������
//public��ʾ�ǡ������ġ����ⲿ������ֱ��ͨ������������Щpublic����
//private��ʾ��˽�еġ�����ֻ�ܱ������Լ��ĳ�Ա�������ʣ����ܱ��ⲿ��������
//�Ӷ�����ͨ��private������η����������ĳЩ���ԣ��Ӷ����غͱ�������Щ���ݡ�
class BBox
{
private:  //length,width,height����˽�����ݣ���粻��ֱ�ӷ�������
	double length;   // Length of a box
	double width;  // Breadth of a box
	double height;   // Height of a box
public:
	//������󳤷�����ӵ������������Ϊ�ǹ����ģ����Ա�������
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
	box.length = 2.5; //����main��������Box��ĳ�Ա������
	                  // ��һ���ⲿ���������ܷ���box��length��Ա
	*/

	box.set(2.5, 4, 3); //����ͨ��Box�Ĺ�������set���޸�box����������

	std::cout << "���box������� :" << box.area() << "\n";
	return 0;
}

//--------------------------------------
//��struct��������ԱĬ���ǹ����ģ���class������ĳ�ԱĬ����˽�е�
class BBBox
{
	//�������г�Ա(����������Ա)Ĭ�϶���˽�еģ������ܱ�������
	double length;   // Length of a box
	double width;  // Breadth of a box
	double height;   // Height of a box

	//������󳤷�����ӵ������������Ϊ�ǹ����ģ����Ա�������
	double area() {
		return length*width*height;
	}
	void set(double l, double w, double h) {
		length = l; 		width = w; 		height = h;
	}
};

//��ΪBBBox���������Զ���˽�еģ��൱��һ����ȫ�ܷ�ĺں��ӣ����޷��������κ���Ϣ����.
int main_13() {
	/*
	BBBox box;
	box.length = 2.5; //�����ܷ���box��˽�г�Աlength
	std::cout << "���box������� :" << box.area() << "\n";
	                      //�����ܷ���box��˽�г�Աarea

	*/
	return 0;
}

//------------����
//���Դ�һ������Base������һ��������Derived��
//Ҳ����˵����Derived�̳��˻���Base��һЩ���Ժ͹��ܣ���ͨ���������Լ����еĹ��ܻ���Ϊ

//�������Ա��Employee
class Employee {
protected:    //protected�����ı������ԣ����ܱ������ʣ������Ա����������̳�
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

//������Manager��һ������Ĺ�Ա������������һ�������Ĺ�Ա
//����Manager�����ǲ�ͬ����ľ���,���Գ���Ա��һ�������⣬������һЩ�ض�������
//��ΪManager���ǹ���public�̳�Employee����Ϣ�����ԣ�
//Employee�ĳ�private˽���������������public������protected�������ܱ��̳�����
class Manager : public Employee {
	int level;  //����ļ���
public:
	void set_level(int l) { level = l; }
	int get_level() { return level; }

	//��Ա��out���������˱仯������Ҫ�������ļ�����Ϣ
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


//------------------���캯��Constructors-----------
//1.���������г�Ա�ǹ����ģ������ڶ���ñ���ʱ�������ó�ʼ����Ա�б�initialization list��
// ����ȳ�ʼ����uniform initialization (in C++11):�������г�ʼ��
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

//��������˽�е����ݳ�Ա����������������������ʼ�������(�����)��
//�����Ҫ���������캯������constructors���������Ա��������ɶ������ĳ�ʼ����
//��������ͬ�ĳ�Ա�������������캯������һ��������ж����ͬ�Ĺ��캯����ֻҪ���ǵĲ����б��ǲ�ͬ��
//2. ��Ĭ�Ϲ��캯���� ��Default constructors���������������������Ĭ��ֵ�Ĺ��캯��

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
	Fraction2 frac2(2,3);  //���õ��ǹ��캯��Fraction2(int numerator, int denominator = 1)
	Fraction2 frac3(4); //���õ��ǹ��캯��Fraction2(int numerator, int denominator = 1)

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


//--------------��������� Overloading operators---

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
//��Ϊ�ⲿ����������operator+
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
