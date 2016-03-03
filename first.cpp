//http://www.runoob.com/cprogramming/c-tutorial.html 
#include <stdio.h> 
/*
   Thisi is my first C program
   hello world
*/

//
int main_00() {
	printf("hello   world\n\n"); //  n表示换行符，newline
	return 0;
}

/*程序 = 用运算符对数据进行处理,数据包括变量和常量，
运算符有：算术运算符、比较运算符、逻辑运算符、位运算符、...
根据参与运算的运算数的个数，运算符分为：
二元运算符如+、-、*、\、+=,
一元一算符如 ++
三元运算符如 “? :” ，例如c =  a>b?a:b 
*/
int main_01() {
	int x = 20 , y =30, z;
	char ch = 'A';
	x = 45;
	z = x + y;
	
	printf("x+y=:%d\n",z);
	printf("%d+%d=:%d\n", x,y,z);

	return 2;
}

int main_02() {
	int x ,y,z=0;
	scanf_s("%d", &x);  //&：取地址运算符，&x取得变量x的地址
	scanf_s("%d", &y);

	z = x + y;
	printf("%d+%d=:%d\n", x, y, z);
	return 2;
}

//更多运算符：http://www.runoob.com/cprogramming/c-operators.html
#include <stdio.h>
void main_04() {
	int a = 21;
	int b = 10;
	int c;

	c = a + b;
	printf("Line 1 - c 的值是 %d\n", c);
	c = a - b;
	printf("Line 2 - c 的值是 %d\n", c);
	c = a * b;
	printf("Line 3 - c 的值是 %d\n", c);
	c = a / b;
	printf("Line 4 - c 的值是 %d\n", c);
	c = a % b;
	printf("Line 5 - c 的值是 %d\n", c);
	c = a++;
	printf("Line 6 - c 的值是 %d\n", c);
	c = a--;
	printf("Line 7 - c 的值是 %d\n", c);

}

/*
每个变量都是类型的，类型就规定了这种变量的存储空间的大小、对这种变量能进行什么运算
更多的类型可以参考：http://www.tutorialspoint.com/cprogramming/c_data_types.htm 
*/


//输入输出:scanf ,printf
int main_03() {
	float y = 45.67; //浮点型doule是4个字节，
	double x = 34.56;  //浮点型doule是8个字节，比float精度更高，占用内存当然也多，运算时间也多
	
	scanf_s("%f", &y);

	double z = x + y; //运算符对同类型的进行运算，这里y类型float被提升为double
	printf("%f+%7.2f=:%f\n", x, y, z);
	return 0;
}



/*
   控制语句：循环和条件
   循环：for ,while, do-while
   条件语句: if, if-else, if-else if-else
            switch
*/

int main_10() {
	int sum = 0;
	for (int i = 1; i <= 100; i++)  //i++相当于  i = i+1;
	{
		sum = sum + i;
	}

	printf("sum = :%d \n", sum);
	return 0;
}

int main_12() {
	int sum = 0 ,i =1;
	while (i <= 100) {
		sum = sum + i;
		i++;
	}
	printf("sum = :%d \n", sum);
	return 0;
}
int main_13() {
	int sum = 0, i = 1;
    do {
		sum = sum + i;
		i++;
	} while (i <= 100);

	printf("sum = :%d \n", sum);
	return 0;
}

int main_30() {
	int a;
	scanf_s("%d", &a);
	if (a < 0)
		printf("这是一个负数!\n");
	else 
		printf("这是一个非负数!\n");
	return 0;
}

int main_31() {
	int a;
	scanf_s("%d", &a);
	if (a < 0)
		printf("这是一个负数!\n");
	else if(a==0)
		printf("这是零!\n");		
	else
		printf("这是一个非负数!\n");
	return 0;
}

int main_33() {
	int a = 3, b = 4;
	int c = a>b ? a : b;
	printf("the max of %d and %d is: %d \n",a,b,c);
	return 0;
}
int main_34() {
	int sum = 0;
	int i;
	for (i = 1; i <= 10;i++ )
	{
		if (i % 3 == 0)
			sum += i;

	}
	printf("%d", sum);
	return 0;
}

int main_40() {
	char cmd;
	printf("请输入命令\n");
	scanf_s("%c",&cmd,1);
	switch (cmd) {
	case 'I':
	case 'i':
		printf("开始插入数据\n");
		break;
	case 'F':
	case 'f':
		printf("查询功能\n");
		break;
	default:
		printf("显示当前目录\n");
		break;
	}
	return 0;
}
int main_42() {
	char cmd;
	bool e = false;
	while(1) {
		printf("请输入命令\n");
		scanf_s("%c", &cmd, 1);
		switch (cmd) {
		case 'I':
		case 'i':
			printf("开始插入数据\n");
			break;
		case 'F':
		case 'f':
			printf("查询功能\n");
			break;
		case 'Q':
		case 'q':
			e = true;
			break;
		default:
			printf("显示当前目录\n");
			break;
		}
		scanf_s("%c", &cmd, 1);
		printf("\n");
		if (e) break;
	}
	return 0;
}


/*-----------函数-------------------
函数定义：返回值类型　　函数名 (参数列表)
      参数列表形如：Type1 name1, type2 name2,....
	  函数定义里的参数叫做“形式参数”
函数调用：
    实际参数传递值给形式参数。
*/
int add(int x, int y) { //函数定义，x,y是形式参数	
	return x + y;
}

int main_50() {
	int a = 3, b = 4;
	int c = add(a, b);  //函数调用，a,b是实际参数
	printf("c = %d\n", c);
	return 0;
}

int sum(int m, int n) {
	int s = 0;
	for (int i = m; i <= n; i++)
		 s = s + i;
	return s;
}

int main_51() {	
	int s;
	s = sum(1, 100);
	printf("s = %d\n", s);
	
	s = sum(10,50);  
	printf("s = %d\n", s);
	return 0;
}

/*
  数组定义：
      类型 数组名[数组大小]
	  类型  数组名[] = { 初始数据元素 }
  例如 int a[10]就定义了有10个整数的一个数组a
  通过下标访问数组元素：
     数组名[下标]
  例如a[2]表示访问数组中下标是2的那个整数，数组的下标是从0开始的。所以a[2]是第三个整数

*/

int main_60() {
	double d[] = { 23.5, 35.6, 89.1, 11.5, 72.2 };
	int s[10];
	for (int i = 0; i < 5; i++)
		printf("%f\n", d[i]);
	printf("\n");

	for (int i = 0; i < 10; i++)
		s[i] = 2 * (1 + i);

	for (int i = 0; i < 10; i++)
		printf("%d\n",s[i]);
	return 0;
}

int main_61() {
	int s[10];
	int min ;
	for (int i = 0; i < 10; i++)
		scanf_s("%d", &(s[i]),1);
	printf("\n");

	for (int i = 0; i < 10; i++)
		printf("%d\n", s[i]);

	//求最小值
	min = s[0];
	for (int i = 1; i < 10; i++)
		if (s[i] < min)
			min = s[i];
	printf("min = %d\n", min);

	return 0;
}
int main_62() {
	int s[10];
	int i;
	for (i = 0; i <100; i++)
	{
		printf("%d\t", i);
		if (i % 10 == 9)
			printf("\n");
	}
		

	return 0;
	

}
/*
多维数组，有多个下标，例如二维数组
  int a[2][3];
  就相当于一个矩阵
  a[0][0] a[0][1] a[0][2] 
  a[1][0] a[1][1] a[1][2]

  矩阵就是从求解方程组来的，比如二元一次方程
  a1*x+b1*y = c1
  a2*x+b2*y = c2
 
  可以由下列矩阵决定
  a1 b1 c1
  a2 b2 c2 
*/
int main_63() {
	int a[2][3];
	int b[][3] = { {1,2,3},{2,3,4} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d  ", b[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = b[i][j] + 3;
		}
	}

	printf("\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/*
  指针和指针变量
  指针：变量的地址
  指针变量：存储指针的变量
*/

//变量的地址
#include <stdio.h>
int main_70()
{
	int  var1;
	char var2[10];

	printf("var1 变量的地址： %x\n", &var1);
	printf("var2 变量的地址： %x\n", &var2);
	printf("var2 变量的地址： %x\n", var2);

	return 0;
}


//指针变量声明的一般形式为： type *var-name;
int main_71() {
	int a = 3;
	int* p = &a; //&是取地址运算符，&a就是得到a的存储地址。
	             //在定义一个变量如p的前面有*，说明p是指针变量，p存储的是整型变量的指针
	             //也就是说p的数据类型是"int *"
	             //因为p存储的是a的地址，我们也说p指向a。

	printf("Address of a variable: %x\n", &a);
	printf("Address stored in p variable: %x\n", p);

	printf("a = %d\n", a);
	*p = 45; //*是取内容运算符，*p就是a。 也就是a的内容变成45
	         //相当于通过指向a的指针变量p间接访问a
	printf("a = %d\n", a);
	return 0;
}

/*
动态内存分配
    向操作系统申请一块内存，然后通过指向这块内存的指针变量取访问这块内存的内容
	分配函数 malloc(size)表示申请size大小的内存，该函数返回申请到的内存的地址，
	  如果申请失败，然后的就是0
    释放内存，通过malloc分配的内存不需要时，可以还给操作系统，这个时候调用free函数
	free(p) 表示释放p指向的那块内存（即还给操作系统）
	sizeof(Type)用来查询type占据多少内存
*/
#include <malloc.h>
int main_72() {
	int * p = (int*) malloc(4 * sizeof(int) );
	p[0] = 23;  
	p[1] = 25; //   *(p+1) = 25
	p[2] = 35;
	p[3] = 45;

	for (int i = 0; i < 4; i++)
		printf("%d ", p[i]);
	printf("\n");

	char *s = (char*)p;
	printf("s is: %x \n",s);
	printf("p is: %x \n", p);

	s[2] = 'A';   

	for (int i = 0; i < 4; i++)
		printf("%d ", p[i]);
	printf("\n");

	return 0;
}

//数组名就是数组的第一个元素的指针
int main_73() {
	int a[5] = { 3,4,5,6,7 };
	for (int i = 0; i < 5; i++)
		printf("*(a+%d)=%d\n",i, *(a + i) );  // *(a+i)就是a[i]

	printf("\n");
	return 0;
}

/*
函数的参数传递

*/
int main_74() {
	int a = 3, b = 4;
	int t = a; a = b; b = t;
	printf("%d\t%d\n", a, b);
	return 0;
}

void swap(int x, int y) {
	int t = x;
	x = y;
	y = t;
	printf("x = %d\ty = %d\n", x, y);
}

int main_75() {
	int a = 3, b = 4;
	swap(a, b);
	printf("a = %d\tb = %d\n", a, b);
	return 0;
}

void swap(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
	printf("x = %d\ty = %d\n", *x, *y);
}

int main_76() {
	int a = 3, b = 4;
	swap(&a, &b);
	printf("a = %d\tb = %d\n", a, b);
	return 0;
}


/*
  字符数组和字符串
*/
#include <string.h>
int main_80() {
	
	//字符串：最后带有结束字符'\0'的字符数组
	char *ss = "hello"; // 在内存里"hello"是这样存放的: h e l l o '\0'

	int len = strlen(ss);
	printf("len of ss is:%d\n", len);

	//字符数组
	char s[10];
	len = strlen(s);
	printf("len of s is:%d\n", len);
	s[0] = 'A';
	s[1] = 'B';
	s[2] = 'c';
	len = strlen(s);
	printf("len of s is:%d\n", len);

	s[3] = '\0';
	len = strlen(s);
	printf("len of s is:%d\n", len);

	return 0;
}



int main_exer2() {
	char cmd;
	bool e = false;
	printf("--------MENU-------\n");
	printf("1.Add\n");
	printf("2.Subtract\n3.Multiply\n4.Divide\n5.Modulus\n6.ShowMenu\n7.Quit\n");
	int a, b;
	int  c;
	while (1) {
		printf("Enter your choice:");
		scanf_s("%c", &cmd, 1);
		switch (cmd) {
			case '1':
			
			printf("%d", add(a,b) );
		    break;
		case '2':
			printf("Enter two Number:\n");
			scanf_s("%d", &a);
			scanf_s("%d", &b);
			printf("%d", a - b);
			break;
		case '3':
			printf("Enter two Number:\n");
			scanf_s("%d", &a);
			scanf_s("%d", &b);
			printf("%d", a * b);
			break;
		case '4':
			printf("Enter two Number:\n");
			scanf_s("%d", &a);
			scanf_s("%d", &b);
			printf("%d", a / b);
			break;
		case '5':
			printf("Enter two Number:\n");
			scanf_s("%d", &a);
			scanf_s("%d", &b);
			printf("%d", a % b);
			break;
		case '7':
			e = true;
			break;
		default:
			printf("显示当前目录\n");
			break;
		}
		scanf_s("%c", &cmd, 1);
		printf("\n");
		if (e) break;
	}
	return 0;
}

void input2number(int *x, int *y) {
	printf("Enter two Number:");
	scanf_s("%d", x);
	scanf_s("%d", y);
}

int sub(int x, int y) { //函数定义，x,y是形式参数	
	return x + y;
}

void showMenu() {
	printf("--------MENU-------\n");
	printf("1.Add\n");
	printf("2.Subtract\n3.Multiply\n4.Divide\n5.Modulus\n6.ShowMenu\n7.Quit\n");
}

int main_exer3() {
	char cmd;
	bool e = false;	
	int a, b;
	
	showMenu();
	while (1) {
		printf("Enter your choice:");
		scanf_s("%c", &cmd, 1);
		switch (cmd) {
		case '1':
			input2number(&a, &b);
			printf("%d", add(a, b));
			break;
		case '2':
			input2number(&a, &b);
			printf("%d", sub(a, b));
			break;
		case '3':
			input2number(&a, &b);
			printf("%d", a * b);
			break;
		case '4':
			input2number(&a, &b);
			printf("%d", a / b);
			break;
		case '5':
			input2number(&a, &b);
			printf("%d", a % b);
			break;
		case '6':
			showMenu();
			break;
		case '7':
			e = true;
			break;
		default:
			printf("显示当前目录\n");
			break;
		}
		scanf_s("%c", &cmd, 1);
		printf("\n");
		if (e) break;
	}
	return 0;
}

#define MAX_NUM 200
void showMenuStudent() {
	printf("--------MENU-------\n");
	printf("a: 添加一个学生信息\n");
	printf("f: 查找一个学生信息\n");
	printf("s: 显示所有学校信息\n");
	printf("q. 程序退出\n");
}
int main_exer4() {
	int ids[MAX_NUM];
	float programs[MAX_NUM];
	float maths[MAX_NUM];
	int num = 0;

	char cmd;

	int id; float prog, math; //一个学生的信息

	showMenuStudent();
	while (1) {
		printf("请选择相应功能:");
		scanf_s("%c", &cmd, 1);
		switch (cmd) {
		case 'a':
		case 'A':
			printf("请输入学生信息(id,prog,math):\n");
			scanf_s("%d", &id,1);
			scanf_s("%f", &prog,1);
			scanf_s("%f", &math,1);
			ids[num] = id; programs[num] = prog; maths[num] = math;
			num++;
			break;
		case 'f':
		case 'F':
			break;
		case 's':
		case 'S':
			for (int i = 0; i < num; i++) {
				printf("%d,%f,%f\n", ids[i], programs[i], maths[i]);
			}
			printf("\n");
			break;
		case 'q':
		case 'Q':
			break;
		}
		scanf_s("%c", &cmd, 1);
	}

	return 0;
}


/*struct定义结构类型*/
struct student {
	int id;
	double program, math;
};

int main_90() {
	struct student stu;  //定义一个变量stu，其类型是结构类型 struct student
	stu.id = 3;   // .就是成员访问运算符，用于访问结构类型变量的成员。
	stu.program = 45.5;
	stu.math = 60.5;

	printf("%d,%f,%f\n", stu.id,stu.program,stu.math);
	return 0;
}

int main_91() {
	struct student students[100];
	int num = 0;
	struct student stu;

	while (1) {
		printf("请输入学生信息(id,prog,math):\n");
		scanf_s("%d %lf %lf", &(stu.id), &(stu.program), &(stu.math)); //double要用%lf格式符
/*		scanf_s("%d", &(stu.id), 1);
		scanf_s("%1f", &(stu.program), 1);
		scanf_s("%1f", &(stu.math), 1);
*/
		if (stu.id <= 0) break;
		students[num] = stu;
		num++;
	}
	
	for (int i = 0; i < num;i++)
		printf("%d\t %f\t%f\n", students[i].id, students[i].program, students[i].math);
	return 0;
}

/*
   通过指向一个结构类型变量的指针变量取访问这个结构变量
   两种方法:
     * 取内容 运算符
     ->间接访问运算符     
*/
int main_92() {
	struct student stu;
	struct student *p;
	p = &stu; //&stu的类型就是struct student *
	(*p).id = 20;
	(*p).program = 35.5;
	(*p).math = 55.5;

	printf("%d\t%f\t%f\t\n", stu.id, stu.program, stu.math);

	p->id = 2; // ->是间接访问运算符，
	p->program = 35.5;
	p->math = 60.5;
	printf("%d\t%f\t%f\t\n", stu.id, stu.program, stu.math);
	return 0;
}

//
int main_93() {
	struct student students[100];
	int num = 0;
	struct student stu;

	while (1) {
		printf("请输入学生信息(id,prog,math):\n");
		scanf_s("%d %lf %lf", &(stu.id), &(stu.program), &(stu.math)); //double要用%lf格式符
																	  
		if (stu.id <= 0) break;
		students[num] = stu;
		num++;
	}

	struct student *p = &(students[0]); // p指向数组的第一个元素，即&(students[0])
	                                    // 数组名students就是数组第一个元素的地址，
	                                    // 即等价于&(students[0])
	                                    //因此也可以写成
	struct student *q = p + num - 1; // q指向最后一个元素 struct student *p = students;
	for (; p <= q; p++ )
		printf("%d\t %f\t%f\n", p->id, p->program, p->math);
	return 0;
}

//-----------------
void InputStudent(struct student *s) {
	printf("请输入学生信息(id,prog,math):\n");
	scanf_s("%d %lf %lf", &(s->id), &(s->program), &(s->math));
}


void outStudents(struct student students[], int num) {
	for (int i = 0; i < num; i++)
		printf("%d\t %f\t%f\n", students[i].id, students[i].program, students[i].math);
}

int main_94() {
	struct student students[10];
	int num = 0;
	struct student stu;

	while (1) {
		InputStudent(&stu);
		if (stu.id <= 0) break;
		students[num] = stu;
		num++;
	}
	outStudents(students,num);
	return 0;
}


//----------动态数组---
#define INIT_SIZE 5
#define INC_SIZE 2

int main_95() {
	struct student *students = 0;
	int capacity = INIT_SIZE;
	int num = 0;
	struct student stu;

	students = (struct student *) malloc( INIT_SIZE*sizeof(struct student) );
	


	while (1) {
		InputStudent(&stu);
		if (stu.id <= 0) break;
		
		if (num == capacity) {//空间已经满，需要增加容量
			struct student *p = (struct student *) realloc(students,
				(capacity+ INC_SIZE) *sizeof(struct student));
			if (p == 0) {
				printf("空间申请失败，程序结束！\n");
				break;
			}
			students = p;
			capacity += INC_SIZE;
		}
		
		students[num] = stu;
		num++;
	}
	outStudents(students, num);
	return 0;
}

/*
内存的3种：
1）静态存储区分配：全局变量和静态变量
2) 栈上分配的： 函数的局部变量
3) 动态分配的：
*/


//静态变量
void f() {
	int s = 0;
	s++;
	printf("%d\n", s);
}
void h() {
	static int s = 0;
	s++;
	printf("%d\n", s);
}
int main_100() {
	f();
	f();

	h();
	h();
	return 0;
}

//全局变量
int g = 0;
void ff() {
	g++;
}
void gg() {
	g++;
}

int main_101() {
	ff();
	gg();
	printf("%d\n",g);
	return 0;
}

//
int main_110() {
	int i ;
	int s = 0;
	for (i = 0; i < 10; i++,printf("%d\n",i)) {
		int i = 5;
		s += i;
	}
	printf("%d\n", s);
	return 0;
}


//C++的引用变量:是其他变量的别名
int main_120() {
	int a = 9;
	int &b = a;
	b = 3;
	printf("%d\n", a);
	return 0;
}
//引用变量主要用处是作为函数之间的参数传递
void sswap(int &x, int &y) {
	int t = x; 
	x = y; 
	y = t;
}

int main_121() {
	int a = 3, b = 4;
	sswap(a, b);
	printf("a = %d b = %d\n", a,b);
	return 0;
}

/*
  C++输入输出
  C++字符串string
*/
#include<iostream> //C++的输入输出文件流 头文件
using std::cout;  //cout是标准名字空间std里定义的一个表示控制台窗口的变量
using std::cin;   //cin是标准名字空间std里定义的一个表示键盘的变量
int main_130() {
	int x, y;
	cin >> x >> y;  
	int z = x + y;
	cout << z << "\n";
	return 0;
}

#include <string>  //C++的字符串 头文件
using std::string; //string是标准名字空间std里定义的一个字符串类型
int main_131() {
	string s, t("world");
	s = "hello";
	string ss = s + t;
	//printf("%s", ss.c_str());
	cout << ss << "\n";  //  <<是C++的输出流运算符	
	return 0;
}

typedef struct{
	string name;
	int id;
	double score;
}Student;

void Scanf(Student &s) {
	cin >> s.name >> s.id >> s.score;
}

int main() {
	Student stu;
	Scanf(stu);
	cout << stu.name << " " << stu.id << " " << stu.score << "\n";
	return 0;
}