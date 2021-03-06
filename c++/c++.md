
##C++ 简介  
C++是C语言的扩展(超集)，C语言编写的程序也是合法的C++程序，C++语言除包含“过程式”(即函数)C语言的特征外，还增加了“面向对象语言”的特征。即程序可以看成许多对象通过发送、接受消息完成程序的功能。具有相同属性（即数据成员）和功能（即函数成员）的对象用一个“类”(class)来刻画它们。
  
例如一个游戏程序有”精灵“、”怪物“、”子弹“、”事件“、”事件监听器“等不同类的对象。比如一个”触摸监听器“对象检测到一个”触摸“事件对象，它可向某个”精灵“对象sprite发送一个带有该触摸对象信息touch的触摸消息 "OnTouchBegin"。sprite对象就执行自己的“OnTouchBegin”过程： sprite.OnTouchBegin(touch);

面向对象程序设计的关键要素是“类和对象”，类即数据类型，即类似于C语言中的int类型，而对象就是具体的变量，用以表示实际的数据。类则是用于刻画同类对象的共同特性有哪些。 类类似于C语言的结构，实际上C语言的结构在C++中就称之为"类"。因此类表示了某种抽象概念，描述了该类对象具有哪些数据(成员变量)和功能（成员函数）。如在游戏中定义一个怪物monster类,具有比如名字、位置、颜色、纹理等信息，还具有比如 “移动”、“死亡”等功能。

```
struct student{
	int id; 
	double score;

	double get_id() {
	    return score; 
	}
	double get_id() {
	    return score; 
	}
	double set_id( int i) {
		id = i;
	double set_score(double s) {
		score = s;
	}
};
```

上述代码就定义了一个叫做“student”的类型，这种类的对象具有类型分别为int和double的数据成员id和score。 此外，这种类的对象还具有 查询 (如get_id) 和 修改 (如set_id)的函数成员，用于获取或修改其数据成员id和score。

```
int main(){
	student stu;

    /* 下列2句的结果是一样的，都是修改stu对象的数据成员id */
	stu.id = 2;
	stu.set_id(2) ; 

	return 0；
}
```


##C++安装

  为了将C++代码编译(Compile)成可执行程序，需要在你的系统(system)上安装C++编译器（Compiler）。

  - windows系统上可以安装[Visual Studio(VS)](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx)、[CodeBlocks](http://www.codeblocks.org/downloads)、[Dev-C++](https://sourceforge.net/projects/orwelldevcpp/)，[MimGW](http://www.mingw.org/)等集成开发环境，集成开发环境除了编译器，还有编辑器（用于编写代码）、连接器（用于将编译器生成的目标文件连接成一个完整的可执行程序）、调试器(Debuger，用于调试程序的错误等)等。

  - Unix/Linux上一般都安装了C++编译器gcc,可以用下列命令检查是否安装了gcc:   
 '''gcc-v'''

  - Mac上有[XCode](https://developer.apple.com/technologies/tools/)集成开发环境

**C++程序结构**

一个程序通常包含下列一些：  
  - 文档    
  - 预处理语句    
  - 全局声明    
  - main函数  
       - 局部变量    
       - 程序语句和表达式    
  - 用户定义函数  
  - 用户定义类型，如类类型（struct，class,enum)   


**输入输出**

```
/*
   这是程序的文档，用以说明这个程序具有哪些功能  
   比如这个程序从键盘输入两个整数，然后再向窗口中  
   输出这2个整数和一个换行，'\n'表示换行符号  
   创建于2016.03-14日
*/
#include <iostream>   
int main() {
	int x, y;
	std::cin >> x >> y;   //std是标准库名字空间
	std::cout << x << " " << y << '\n';
	return 0;
}
```

/\*和\*/两者之间的部分是程序的说明文档，也称之为“注释”，用以对代码进行说明，方便今后或别人阅读理解代码  
/\*和\*/构成的注释是C语言的多行注释，即注释部分可以包含多行文字。注意：注释的内容不是程序代码！

C++增加了一个新的**单行注释**，即从“//”开头的这一行后面的都是程序注释而不是代码。

main()是程序的主函数，程序总是从main开头执行，每个程序只能包含一个main函数。

C++提供了实现各种输入输出功能的各种类，成为“输入输出流库”，它将输入输出看成从或向一个对象流动的数据流。如<iostream>就是一个输入输出库的头文件，其中包含了各种输入输出相关的类的定义。

为了避免程序中变量或类的名称相同发生冲突(如不同的软件库都提供了一个叫做Vector3的数学向量类，就会发生冲突)，通过将 类型名、变量名等都放入某个所谓的**“名字空间(namespace)”**就可以避免这种名字冲突。如两个不同班级都有一个叫做“李平”的同学，我们就可以通过这两个李平所属的“班级（相当于名字空间）”来区分它们。如 “班级A::李平”、“班级B::李平”。

std::cin是标准名字空间std中的一个变量，表示一个输入对象（键盘），而std::cout也是标准名字空间std中的一个变量，表示一个输出对象（程序窗口）。

">>"是输入运算符，表示从一个流对象(如这里的std::cin)输入数据到其后面跟着的变量(如x、y)中。类似的，"<<"是输出运算符，表示将其右边的一个变量输出到其左边的输出流对象(如这里的std::cout)。

因为表达式"std::cin >> x"的结果仍然是"std::cin "，因此输入流运算符">>"可以接连使用。如"std::cin >> x >> y"相当于2次具体输入"std::cin >> x"和"std::cin >> x"。


##名字空间namespace

如前所述，名字空间是为了防止代码中的名字冲突（同一个名字表示不同的东西）。如"std::cin"表示了名字空间std中的一个变量（对象）cin。  如果你在一个代码前面声明了“using namespace std”，那么以后就不需要在一个名字如cin前加上名字空间的限定词"std::"，可以直接用cin，如：  
```

   #include <iostream>
   using namespace std;
   int main(){
       int x; 
       cin >> x;
       cout << "x=:"<< x <<"\n";   //输出字符床"x=:"、x的值，换行
       return 0;
   }
  
```


##数据类型和变量

C++中的每个变量(实际就是一块内存)都要说明其数据类型，类型的作用有：决定该类型变量占据多大内存、取值范围、对该类型变量能进行哪些运算。

定义变量的格式是： 

*类型名  变量名;*

*类型名  变量1名, 变量2名, 变量3名, 变量4名; *

每个变量实际就是一块内存。它存储在计算机的某个内存地址处，占据一定的内存大小。

如：  
```
int x;
char c,d;
```

定义了一个数据类型是int（整型）的变量x，对它能进行一些整数的运算如加减乘除。定义了类型为char（字符类型）的两个变量叫做c和d。

C++的数据类型主要分为内在类型（built-in type, 如 int）和用户定义类型 (user defined type,如 struct student)。

内在类型有：整型(integer)、字符型(character)、浮点型(floating-point)、逻辑型(boolean)、void型。  
如整型类型有：

   ![integer data type](https://github.com/shdong/shdong/blob/master/c%2B%2B/integerType.jpg)

了解更多的[内在类型](http://www.w3schools.in/cplusplus/data-types/)。

除变量外，程序的数据还包括常量（constants也叫做文字量literals），它们是永远不会改变了的量。常量的类型可以是任何类型，习惯上用大写字母命名它们。如  
```
const double PI =  3.14159265; 
```
定义了一个叫做PI的double类型的常量。

##存储类(storage class )

这里的class不是C++中的类class，而是类别的意思。存储类说明了变量的生命周期和作用域(可见性)  
C++的存储类有下列几种：

  - Automatic
  - External
  - Static
  - Register

  ***自动存储类 Automatic(auto) storage class***

  定义在一个函数体里的变量称为“自动变量 (auto variable)”。也成为局部变量(local variable)。可以用auto来定义：  
   ```
    auto a,b,c = 100;
  ``` 
定义了整型变量a,b,c。用auto定义的变量其数据类型可以从初始化表达式如"c=100"中自动推断出来。 
等价于
  ```
  int a,b,c = 100;
  ```
***外部存储类 External storage class***

定义在函数外部的变量叫做“外部变量(External variable)”。外部变量一旦定义，就可以用在后续的任何程序代码中。
```
#include <iostream>
int count;
void f(){
	count = count+2;
}
int main(){
	count = 0 ;
	f();
	std::cout << count;
}
```

外部修饰符(External modifiers)通常用于说明（声明）一个被程序多个文件使用的局部变量。仅仅是说明存在这样的一个变量而不是定义这个变量，变量的定义可能存在在其他某个文件中。

***first file: main.cpp***
```
#include <iostream>
#include "file.cpp"
int count ;
extern void write_extern();
 
main()
{
   count = 5;
   write_extern();
   system("PAUSE");
}
```
在该文件中声明了存在一个外部函数write_extern()，可能定义在其他文件中，在该文件中并没有定义这个函数。
***second file: file.cpp***
```
#include <iostream>
extern int count;
 
void write_extern(void)
{
   std::cout << "Count is " << count << std::endl;
}
```
在该文件中定义了main.cpp中的main()函数所需要的write_extern()。声明了在其他文件中可能定义了一个叫做"count"的整型变量。

##运算符(Operators)

运算符是用于对数据进行运算(如算术运算、逻辑运算)的符号。运算符按照其种类可以分为：算术运算符Arithmetric、增量(increment)和减量(decrement)运算符、
关系(Relational)运算符、逻辑(logical)运算符、位(bitwise)运算符、赋值(Assignment)运算符、  
以及其他一些运算符,如逗号运算符',',检测内存大小运算符sizeof, 取地址运算符&, 取内容运算符*, 条件运算符?: 。

更多[运算符信息](http://www.w3schools.in/cplusplus/operators/)或 [这里](http://www.tutorialspoint.com/cplusplus/cpp_operators.htm)

##关键字(Keywords)

C/C++程序中定义变量、函数或类型时，不用使用那些被用作C++关键字的标识符(identifier)。这些被C++ 语言保留的标识符称为关键字。如[C++ Keywords List](http://www.w3schools.in/cplusplus/keywords/)


##控制结构(Control structures)
C/C++通过条件语句和循环语句控制程序的执行过程。   
条件语句根据条件是否满足，执行相应的程序代码(程序块) ，主要有if 系列和switch语句。即：
  - [if语句(if statements)](http://www.w3schools.in/cplusplus/decision-making/if/)
  - [if-else语句(if-else statements)](http://www.w3schools.in/cplusplus/decision-making/if-else/)
  - [else if语句(lse if statements)](http://www.w3schools.in/cplusplus/decision-making/else-if/)
  - [switch语句(switch statements)](http://www.w3schools.in/cplusplus/decision-making/switch/)

##数组和字符串

###数组

语法：
```
  类型 数组名[数组大小]; 
```
如：
```
  double salary[1500];
```
定义了一个数据元素类型是double的大小为1500的数组。

数组可以在定义时初始化，如：
```
 int age[5] = {22,25,30,32};  //只初始化了前面4个元素，最后一个元素没有初始化
 float scores[] = {60.5, 30.1, 78.3,30.4, 77.3, 85}; //数组的大小由{}里的元素个数决定
```
age在内存的存储样子如下：

   | 22 | 25 | 30 | 32 |___|

访问数组中的元素，可以用下标（下标从0开始），如age[0]、age[1]分别表示数组age的第1个、第2个整数。
如：
```
int newArray[10];
int n = 0;

// Initializing elements of array seperately
for(n=0; n < sizeof(newArray); n++)
{
  newArray[n] = n;
}

int a = newArray[5]; // Assigning 5th element of array value to integer 'a'.
```

###字符串 String

C++中的C风格的字符串是结尾带有结束字符'\0'的字符数组。如：
```
  char str[5] = {'a','b','c','d','e'}; //是5个字符的数组
  char str2[5] = {'a','b','c','d','\0'};  //表示一个有4个字符的字符串"abcd"
  char *str3 = "hello"; // "hello"是一个字符串常量，用它给一个char型指针变量strs赋值，  
                        //就是将它的起始地址给str3赋值，因此str3里存储的是"hello"的
                        //第一个字符'h'的地址         

```
针对这种C风格的字符串的字符串操作函数有：查询长度(strlen)、字符串拷贝(strcpy)、  
字符串拼接(strcat)、 字符串比较(strcmp)、字符查找(strchr)、 字符串查找(strchr)等。  
例子可参考[C风格字符串](http://www.tutorialspoint.com/cplusplus/cpp_strings.htm)


标准C++库提供了一个叫做"string"的类(class)支持字符串的许多基本操作。如:
```
#include <iostream>
#include <string>

using namespace std;

int main ()
{
   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;

   // copy str1 into str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;

   // concatenates str1 and str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;

   // total lenghth of str3 after concatenation
   len = str3.size();
   cout << "str3.size() :  " << len << endl;

   return 0;
}
```

##指针(Pointers)

指针变量定义语法：  
类型 *变量名；

如：
```
int  *height;
char  *age;
```
定义了指针变量height和age,height用于存储int型变量的地址。age用于存储char型变量的地址。  
```
#include<iostream>
using namespace std;

int main ()
{
   int  n = 20, *ptr;  //定义了int型变量n 和int指针型的变量ptr

   ptr = &n;  //ptr存储的是n的地址，其中&n得到了n的地址。
 
   cout << "变量n的地址是: " << &n << endl;
   
   // 打印存储在指针变量ptr中的地址(指针)  
   cout << "存储在ptr变量中的地址是: " << ptr << endl;

   //打印存储在  *ptr 里的值  
   cout << "变量 *ptr 的值是: " << *ptr << endl;
   
   *ptr = 10; // *是“取内容”运算符，得到指针ptr指向的那块内存

   system("pause");
   return 0;
}
```

数组名是指向数组第一个元素的指针，可以通过 “指针+一个整数”来指向相应的数组元素。例如：
```
#include <iostream>
int main(){
	int a[5] = {10,20,30,40,50};

	//通过下标访问每个元素
	for(int i = 0 ; i<5; i++)
	   a[i] = i+2;

  //通过z指针偏移访问每个元素
	int *p = a;
	for(int i = 0 ; i<5; i++){
		*(p+i) = i+3;     //p+i就是指针p（也就是数组首地址）向后偏移i个int型元素内存大小，
		                 // 也就是 a[i]的地址， *(p+i) 就是a[i]。
	}   
}
```

##C++的面向对象

###类(class)

在C++,Java这种面向对象编程语言中，数据和函数（对数据的处理过程）被捆绑在一个完整的叫做“对象”的单元中。  
C++中的类(class)类型是C语言的结构(struct)的扩展，在C语言的结构类型只描述了  
这种类型的变量具有哪些属性（数据成员），而C++的类类型，则描述了这种类型的对象所具有  
的属性（数据成员）和行为（函数）。

如同C语言的结构（struct）不是一个变量(在C++中变量也称为"对象"")，C++中的类(class)也不是一个变量(对象)，而是刻画同类型所有对象共同具有的特性( 属性和行为)。

**类是什么(What is class)**

  - 类(class)是一个类似于C语言的结构(struct)的抽象数据类型
  - 类刻画了对象的属性，以及可以做用于对象的操作(函数)  
    即类包含：数据成员（也称成员数据） 、 函数成员（也称成员函数）

**类的定义(Definition of a class)**

语法：
```
Class class_name
{
    Data Members;
    Methods;
}
```
例如：
```
class A
{
    public:
    double length; // Length of a box
    double breadth; // Breadth of a box
    double height; // Height of a box 
}
```
  - *privated,protected,public*是可见性标记  
  - 声明为*privated*的成员只能被该类的成员函数访问，外部（其他类或全局函数）   
    不能访问这些*private*成员
  - 声明为*privated*的成员能被类(class)外的函数访问  
  - 在C++中，数据可以通过被声明为*private*对外界隐藏起来。称为“信息隐蔽”。  

**类成员(class members)**

类中的成员有**数据(data)**和**函数(function)**成员。
```
Class A
{
    int i;
    int j;
    void f (int, int);
    int g(); 
    int i; //错，不能在类里定义两个同名的成员i
}
```
*f*和*g*是类A的成员函数，它们定义了类A的对象具有的行为。

**成员访问运算符 (.)**

类似于C语言，成员访问运算符(.)可用于访问类对象的成员。如
```
#include <iostream> 
using namespace std;

class Box
{
 public:
   double length; // Length of a box
   double breadth; // Breadth of a box
   double height; // Height of a box
   double volume(){
	  return height * length * breadth;
   }
}

int main( )
{
  Box Box1; // Declare Box1 of type Box
  Box Box2; // Declare Box2 of type Box
  double vol = 0.0; // Store the volume of a box here

  // box 1 specification
  Box1.height = 4.0; 
  Box1.length = 6.0; 
  Box1.breadth = 3.0;

  // box 2 specification
  Box2.height = 10.0;
  Box2.length = 12.0;
  Box2.breadth = 12.0;

  // volume of box 1
  vol = Box1.height * Box1.length * Box1.breadth;
  cout << "Volume of Box1 : " << vol << endl; 

  //  volume of box 2
  vol = Box2.volume()
  cout << "Volume of Box2 : " << vol << endl;
  return 0;
}
```
再如:
```
using namespace std;

class stud 
{
    public:
    char name[30],clas[10];
    int rol,age;
    float per;

   void enter() 
  {
    cout<<"\n Enter Student Name, Age, Roll number";     cin>>name>>age>>rol;
    cout<<"\n Enter Student Class and percentage in previous class";     cin>>clas>>per; 
  }

  void display() 
  {
    cout<<"\n Age\tName\tR.No.\tClass\t%ge";
    cout<<"\n"<<age<<"\t"<<name<<"\t"<<rol<<"\t"<<clas<<"\t"<<per<<"%"; 
  }
};

int main()
{
    class stud s;
    s.enter();    //通过类stud的对象s调用类stud的成员函数enter() 输入数据到对象s的数据成员中
    s.display();
    cin.get();	//use this to wait for a keypress 
} 
```

**this 指针**

C++类的每个成员函数都隐含一个叫做"this"指针，存储调用这个成员函数的对象地址。  
如上述代码中的enter()和dispaly()函数实际是 enter(stud *this) 和 dispaly(stud *this) 。  
其中的参数this指向main函数中调用它们的那个对象s（即this指针变量存贮的是s的地址）。

同样的Box代码实际应该是:
```
class Box
{
 public:
   double length; // Length of a box
   double breadth; // Breadth of a box
   double height; // Height of a box
   double volume(Box *this){
	  return this->height * this->length * this->breadth;
   }
}

int main(){
	Box Box1, Box2;
	//...
	double vol;
	vol = Box1.volume(); //实际上是: vol = doubleBox1.volume(&Box1); 
	vol = Box2.volume(); //实际上是: vol = doubleBox1.volume(&Box2);
}
```

**间接访问运算符 (->)**
可以通过一个指向类对象(变量)的指针变量间接访问这个对象的成员(数据成员和函数成员)，如
```
#include <iostream>
class Box
{
 public:
   double length; // Length of a box
   double breadth; // Breadth of a box
   double height; // Height of a box
   double volume(Box *this){
	  return this->height * this->length * this->breadth;
   }
}
  int main(){
	Box box;
	Box *p = & box;
	p->length = 20.5;
	p->breadth = 2;
	p->height = 4.5;

	double vol;
	vol = p->volume(); 
    std::cout << vol<<"\n";
	return 0;
	
}
```

**构造函数(Constructors)、析构函数（Deconstructors）**
```
//1.如果类的所有成员是公开的，我们在定义该变量时，可以用初始化成员列表（initialization list）
// 或均匀初始化（uniform initialization (in C++11):）来进行初始化
class Foo
{
public:
  int m_x;
  int m_y;
};

int main()
{
  Foo foo1 = { 4, 5 }; // initialization list
  Foo foo2{ 6, 7 }; // uniform initialization (C++11)

  return 0;
}
```

```
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
  Fraction() // 默认构造函数(default constructor)
  {
    m_numerator = 0;
    m_denominator = 1;
  }

  int getNumerator() { return m_numerator; }
  int getDenominator() { return m_denominator; }
  double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

int main()
{
  Fraction frac; // Since no arguments, calls Fraction() default constructor
  std::cout << frac.getNumerator() << "/" << frac.getDenominator() << '\n';

  return 0;
}
```

多个构造函数

```
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
```
###继承(Inheritance)

C++的一个重要特性是继承(Inheritance)，继承是一种重用和扩展已有类(class)而无需修改它们的机制。

通过从已有的类派生出新的类，可以重用已有的代码功能并快速实现新的功能。

被继承的类称为“基类(base class)”或“父类(Parent class)”，从基类派生出的新类称为“派生类(derived class)”或“子类 child class”。从这些子类又可以派生出新的子类，如此，形成一个层次性的继承关系。

如果一个派生类(子类)是从一个基类(父类)直接派生定义的，这种继承称为“单继承(single inheritance)”  
如果一个派生类(子类)是从2个以上基类(父类)直接派生定义的，这种继承称为“多继承(multiple inheritance)” 

```
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
```

![继承(Inheritance)关系](https://github.com/shdong/shdong/blob/master/c++/inheritance.jpg)

**可见模式visibility mode**

通过关键字public,protected,private控制基类成员在派生类中的可见性（可访问性）。  
因此根据可见性的不同，可将继承分为：  
  - 私有继承private inheritance - 当声明是从基类私有(private)派生时，基类的公开(public)  
  和保护(protected)成员在派生类中都成了私有(private)成员。
  - 保护继承protected inheritance - 当声明是从基类保护(protected)派生时，基类的公开(public)  
  和保护(protected)成员在派生类中都成了保护(protected)成员。
  - 公开继承public inheritance - 当声明是从基类公开(publice)派生时，基类的公开(public)  
  和保护(protected)成员在派生类中仍然分别为公开(public) 和保护(protected)成员。

![可见模式](https://github.com/shdong/shdong/blob/master/c++/control_inheritance.jpg)

###友元(friends)

在C++中，一个函数或一个类可以被声明为另一个函数或类的友元(friends)  
一个函数如果不是一个类的成员函数，就不能访问这个类的私有数据。然而一个类的友元函数  
(不是这个类的成员函数)可以访问这个类的私有数据。 同行，一个类A的函数不能访问其他类如类B的  
私有数据，但如果类A是类B的友元类，则类A的函数就可以访问类B的私有数据。

例如
```
/* C++ program to demonstrate the working of friend function.*/
#include <iostream>
using namespace std; 

class Distance {
    private:
        int meter; 
    public:
        Distance(): meter(0){ }
        friend int func(Distance); //类Distance将外部函数fun视为其友元
};

int func(Distance d){
    //function definition
    d.meter=10; // 不是类Distance的函数func可以访问类的私有数据
    return d.meter; 
}

int main(){ Distance D;
    cout<<"Distace: "<< func(D);
    system("pause"); 
    return 0;
}
```


###函数重载，运算符重载(function overloading, operator overloading)

**函数重载(function overloading)**

C语言不能有两个同名函数，而C++则允许在一个名字空间里定义多个同名的函数，
只要它们的参数列表不一样，这种行为称为*函数重载(function overloading)*。

例如
```
int add(int x, int y){ return x+y; }
double add(double x, double y){ return x+y; }
struct Vector2{
	double x,y;
	Vector2(double x0,double y0) :x(x0),y(y0) { }
};
dVector2 add(Vector2 x, Vector2 y){
   Vector2 z; z.x = x.x+y.x; z.y = x.y+y.y; 
  return z; 
}
int main(){
	Vector2 v1(2.5, 3.5),v2(-1.2, 7.6);
	Vector2 v = add(v1,v2);
	int a = 3,b=4;
	int c = add(a,b);
	return 0;
}
```

```
#include <iostream>
using namespace std;
 
class printData 
{
   public:
      void print(int i) {
        cout << "Printing int: " << i << endl;
      }

      void print(double  f) {
        cout << "Printing float: " << f << endl;
      }

      void print(char* c) {
        cout << "Printing character: " << c << endl;
      }
};

int main(void)
{
   printData pd;
 
   // Call print to print integer
   pd.print(5);
   // Call print to print float
   pd.print(500.263);
   // Call print to print character
   pd.print("Hello C++");
 
   return 0;
}
```
**运算符重载(operator overloading)**

上面对Vector2类型的对象用函数add进行相加，不如通常的算术运算符'+'来得自然。  
为了能用'+'对两个Vector2类的对象进行加法运算，我们需要对类Vector2重载“加法运算符”，  
即告诉加法运算符'+'，如果对它们进行相加。加法运算符的完整函数名是"operator+"，  
因此，可以如下重新定义参数列表是两个Vector2对象的"operator+"函数。
```
struct Vector2{
	double x,y;
	Vector2(double x0,double y0) :x(x0),y(y0) { }
};
Vector2 operator+(Vector2 v1,Vector2 v2){
	return Vector2(v1.x+v2.x,v1.y+v2.y);
}
int main(){
	Vector2 v1(2.5, 3.5),v2(-1.2, 7.6);
	Vector2 v = v1+v2;  //实际上调用的是: Vector2 v = operator+(v1,v2);
	
	return 0;
}

```
假如Vector2的数据x,y是私有数据，而“operator+”被定义为全局函数（外部函数），则  
在该函数中访问v1.x即v1的私有数据x是非法的。解决这个问题的方式有两种

  - 方法一：将operator+定义为Vector2的成员函数  
  ```
  struct Vector2{
  private:
	double x,y;
  public:
	Vector2(double x0,double y0) :x(x0),y(y0) { }
	Vector2 operator+(Vector2 v2){  //相当于 Vector2 operator+(Vector2 *this,Vector2 v2)
         return Vector2(this->x+v2.x, this->y+v2.y);
    } 
  };
 
  int main(){
    	Vector2 v1(2.5, 3.5),v2(-1.2, 7.6);
	   Vector2 v = v1+v2;  //实际上调用的是: Vector2 v = v1.operator+(v2);
	   return 0;
   }
  ```
  - 方法二： 在类Vector2中将外部函数operator声明为其友元。
  ```
  struct Vector2{
  private:
	double x,y;
  public:
	Vector2(double x0,double y0) :x(x0),y(y0) { }
	friend Vector2 operator+(Vector2 v1,Vector2 v2)； //类Vector2将该函数声明为自己的友元
  };

   Vector2 operator+(Vector2 v1,Vector2 v2){
	return Vector2(v1.x+v2.x,v1.y+v2.y);
   }
  int main(){
    	Vector2 v1(2.5, 3.5),v2(-1.2, 7.6);
	   Vector2 v = v1+v2;  //实际上调用的是: Vector2 v = v1.operator+(v2);
	   return 0;
   }
   ```


###模板(template)

**函数模板**

假如要求针对不同类型的两个变量的最小值函数，我们需要对每种参数类型定义一个对应的函数，如
```
  int min(int a ,int b){
     if(a < b) return a;
     else return b;
  }
  float min(float a ,float b){
     if(a < b) return a;
     else return b;
  }
  double min(double a ,double b){
     if(a < b) return a;
     else return b;
  }
```
 显然这些函数的代码都是一样的，唯一不同的是其参数和返回值的类型，我们只要复制、粘贴、  
 修改一下函数规范就可以将同行的函数体用于其它类型的参数。尽管很方面，但复制粘帖修改也  
 比较麻烦，更主要的问题是这样的函数不能用于将来可能出现的新的类型参数。

 解决这个问题的方法是定义一个模板函数，将其中的参数和返回值用所谓的“模板参数”进行参数化。
 ```
 template< class Type>
 Type min(Type a ,Type b){
     if(a < b) return a;
     else return b;
  }
 ```
 在实际调用这个函数时，编译器通常会根据传入的实际参数自动推断出模板参数的类型，  
 从而自动帮助我们生成对应参数类型的函数版本，而不需要我们自己编写该参数类型的  
 函数版本。
 ```
    int main(){
    	int a=3,b = 5;
    	float f = 2.5, g = 3.5;
    	double x = 2.4, y = 6.5;
    	int c = min(a, b);   //编译器编译到该句时，会自动生成int类型作为参数和返回值
    	                    // 的min函数  int min(int a, int b);
    	float h = min(f, h) ;  //编译器编译到该句时，会自动生成int类型作为参数和返回值
    	                     // 的min函数  float min(float a, float b);
    	float h = min(f, h) ;  //编译器编译到该句时，会自动生成int类型作为参数和返回值
    	                    // 的min函数  double min(double a, double b);
    	double z = min(x, y); 
    }
 ```
**类模板**

上述我们定义的Vector2只能表示分量数值类型是double类型的平面向量，如要  
要表示int类型或float类型的平面向量，需要重新定义不同名字的向量类。如  
Vector2i ,Vector2f。对于不同数值类型都要定义这样一个类，很不方便。
C++类模板（或称模板类）则可以定义一个泛型的向量类。如下：
 ```
 template < class Type>
 class Vector2{
   private:
	Type x,y;
  public:
	Vector2(Type x0,Type y0) :x(x0),y(y0) { }
	Vector2 operator+(Vector2 v2){ //相当于 Vector2 operator+(Vector2 *this,Vector2 v2)
       return Vector2(this->x+v2.x, this->y+v2.y);
    } 
  };

  

   int main(){    	
    	Vector2<int> u(3, 5) ,u2(4, 6);
    	Vector2<float> v(3.5 ,5.5)，v2(2.5, 10.5);	  //
        Vector2<int> u3 = u + u2;   // u. operator(u2);
        Vector2<int> v3 = v + v2;   // v. operator(v2);
	   return 0;
   }
 ```
 编译器根据Vector2<int>从类模板Vector2中生成int类型的一个具体Vector2类的所有代码，   
 根据Vector2<float>从类模板Vector2中生成float类型的另一个具体Vector2类的所有代码。 

##标准模板库

C++的标准模板库(STL)中定义了许多实用的类模板和函数模板(算法)。

例如向量vector类模板表示一个顺序表（数组）。
```
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector< int > ia ; //int类型的向量
	vector< float > fa ; //float类型的向量
	ia.push_back(2);   //从后面加入一个整数2
	ia.push_back(3);   //从后面加入一个整数3
	ia.push_back(4);   //从后面加入一个整数4
	int n = ia.size();  //ia向量中整数的个数
	for(int i = 0 ; i< n ;i++)
        std::cout << ia[i]<<"\n";

    fa.push_back(2.5);   //从后面加入一个整数2
	fa.push_back(3.5);   //从后面加入一个整数3
	fa.push_back(4.5);   //从后面加入一个整数4
	int n = fa.size();
	for(int i = 0 ; i< n ;i++)
        std::cout << fa[i]<<"\n";
               
}
```  
关于标准模板库(STL)，可以参考[c++ stl tutorial](http://www.tutorialspoint.com/cplusplus/cpp_stl_tutorial.htm)


 
###参考资料(Reference)：

1. [http://www.w3schools.in/cplusplus/intro/](http://www.w3schools.in/cplusplus/intro/) 

2. [http://www.tutorialspoint.com/cplusplus/cpp_quick_guide.htm](http://www.tutorialspoint.com/cplusplus/cpp_quick_guide.htm)

3. [C++ tutorial for C users](http://www.4p8.com/eric.brasseur/cppcen.html)

4. [http://www.learncpp.com/cpp-tutorial/](http://www.learncpp.com/cpp-tutorial/)