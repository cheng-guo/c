//http://www.runoob.com/cprogramming/c-tutorial.html 
#include <stdio.h> 
/*
   Thisi is my first C program
   hello world
*/

//
int main_00() {
	printf("hello   world\n\n"); //  n��ʾ���з���newline
	return 0;
}

/*���� = ������������ݽ��д���,���ݰ��������ͳ�����
������У�������������Ƚ���������߼��������λ�������...
���ݲ���������������ĸ������������Ϊ��
��Ԫ�������+��-��*��\��+=,
һԪһ����� ++
��Ԫ������� ��? :�� ������c =  a>b?a:b 
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
	scanf_s("%d", &x);  //&��ȡ��ַ�������&xȡ�ñ���x�ĵ�ַ
	scanf_s("%d", &y);

	z = x + y;
	printf("%d+%d=:%d\n", x, y, z);
	return 2;
}

//�����������http://www.runoob.com/cprogramming/c-operators.html
#include <stdio.h>
void main_04() {
	int a = 21;
	int b = 10;
	int c;

	c = a + b;
	printf("Line 1 - c ��ֵ�� %d\n", c);
	c = a - b;
	printf("Line 2 - c ��ֵ�� %d\n", c);
	c = a * b;
	printf("Line 3 - c ��ֵ�� %d\n", c);
	c = a / b;
	printf("Line 4 - c ��ֵ�� %d\n", c);
	c = a % b;
	printf("Line 5 - c ��ֵ�� %d\n", c);
	c = a++;
	printf("Line 6 - c ��ֵ�� %d\n", c);
	c = a--;
	printf("Line 7 - c ��ֵ�� %d\n", c);

}

/*
ÿ�������������͵ģ����;͹涨�����ֱ����Ĵ洢�ռ�Ĵ�С�������ֱ����ܽ���ʲô����
��������Ϳ��Բο���http://www.tutorialspoint.com/cprogramming/c_data_types.htm 
*/


//�������:scanf ,printf
int main_03() {
	float y = 45.67; //������doule��4���ֽڣ�
	double x = 34.56;  //������doule��8���ֽڣ���float���ȸ��ߣ�ռ���ڴ浱ȻҲ�࣬����ʱ��Ҳ��
	
	scanf_s("%f", &y);

	double z = x + y; //�������ͬ���͵Ľ������㣬����y����float������Ϊdouble
	printf("%f+%7.2f=:%f\n", x, y, z);
	return 0;
}



/*
   ������䣺ѭ��������
   ѭ����for ,while, do-while
   �������: if, if-else, if-else if-else
            switch
*/

int main_10() {
	int sum = 0;
	for (int i = 1; i <= 100; i++)  //i++�൱��  i = i+1;
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
		printf("����һ������!\n");
	else 
		printf("����һ���Ǹ���!\n");
	return 0;
}

int main_31() {
	int a;
	scanf_s("%d", &a);
	if (a < 0)
		printf("����һ������!\n");
	else if(a==0)
		printf("������!\n");		
	else
		printf("����һ���Ǹ���!\n");
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
	printf("����������\n");
	scanf_s("%c",&cmd,1);
	switch (cmd) {
	case 'I':
	case 'i':
		printf("��ʼ��������\n");
		break;
	case 'F':
	case 'f':
		printf("��ѯ����\n");
		break;
	default:
		printf("��ʾ��ǰĿ¼\n");
		break;
	}
	return 0;
}
int main_42() {
	char cmd;
	bool e = false;
	while(1) {
		printf("����������\n");
		scanf_s("%c", &cmd, 1);
		switch (cmd) {
		case 'I':
		case 'i':
			printf("��ʼ��������\n");
			break;
		case 'F':
		case 'f':
			printf("��ѯ����\n");
			break;
		case 'Q':
		case 'q':
			e = true;
			break;
		default:
			printf("��ʾ��ǰĿ¼\n");
			break;
		}
		scanf_s("%c", &cmd, 1);
		printf("\n");
		if (e) break;
	}
	return 0;
}


/*-----------����-------------------
�������壺����ֵ���͡��������� (�����б�)
      �����б����磺Type1 name1, type2 name2,....
	  ����������Ĳ�����������ʽ������
�������ã�
    ʵ�ʲ�������ֵ����ʽ������
*/
int add(int x, int y) { //�������壬x,y����ʽ����	
	return x + y;
}

int main_50() {
	int a = 3, b = 4;
	int c = add(a, b);  //�������ã�a,b��ʵ�ʲ���
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
  ���鶨�壺
      ���� ������[�����С]
	  ����  ������[] = { ��ʼ����Ԫ�� }
  ���� int a[10]�Ͷ�������10��������һ������a
  ͨ���±��������Ԫ�أ�
     ������[�±�]
  ����a[2]��ʾ�����������±���2���Ǹ�������������±��Ǵ�0��ʼ�ġ�����a[2]�ǵ���������

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

	//����Сֵ
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
��ά���飬�ж���±꣬�����ά����
  int a[2][3];
  ���൱��һ������
  a[0][0] a[0][1] a[0][2] 
  a[1][0] a[1][1] a[1][2]

  ������Ǵ���ⷽ�������ģ������Ԫһ�η���
  a1*x+b1*y = c1
  a2*x+b2*y = c2
 
  ���������о������
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
  ָ���ָ�����
  ָ�룺�����ĵ�ַ
  ָ��������洢ָ��ı���
*/

//�����ĵ�ַ
#include <stdio.h>
int main_70()
{
	int  var1;
	char var2[10];

	printf("var1 �����ĵ�ַ�� %x\n", &var1);
	printf("var2 �����ĵ�ַ�� %x\n", &var2);
	printf("var2 �����ĵ�ַ�� %x\n", var2);

	return 0;
}


//ָ�����������һ����ʽΪ�� type *var-name;
int main_71() {
	int a = 3;
	int* p = &a; //&��ȡ��ַ�������&a���ǵõ�a�Ĵ洢��ַ��
	             //�ڶ���һ��������p��ǰ����*��˵��p��ָ�������p�洢�������ͱ�����ָ��
	             //Ҳ����˵p������������"int *"
	             //��Ϊp�洢����a�ĵ�ַ������Ҳ˵pָ��a��

	printf("Address of a variable: %x\n", &a);
	printf("Address stored in p variable: %x\n", p);

	printf("a = %d\n", a);
	*p = 45; //*��ȡ�����������*p����a�� Ҳ����a�����ݱ��45
	         //�൱��ͨ��ָ��a��ָ�����p��ӷ���a
	printf("a = %d\n", a);
	return 0;
}

/*
��̬�ڴ����
    �����ϵͳ����һ���ڴ棬Ȼ��ͨ��ָ������ڴ��ָ�����ȡ��������ڴ������
	���亯�� malloc(size)��ʾ����size��С���ڴ棬�ú����������뵽���ڴ�ĵ�ַ��
	  �������ʧ�ܣ�Ȼ��ľ���0
    �ͷ��ڴ棬ͨ��malloc������ڴ治��Ҫʱ�����Ի�������ϵͳ�����ʱ�����free����
	free(p) ��ʾ�ͷ�pָ����ǿ��ڴ棨����������ϵͳ��
	sizeof(Type)������ѯtypeռ�ݶ����ڴ�
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

//��������������ĵ�һ��Ԫ�ص�ָ��
int main_73() {
	int a[5] = { 3,4,5,6,7 };
	for (int i = 0; i < 5; i++)
		printf("*(a+%d)=%d\n",i, *(a + i) );  // *(a+i)����a[i]

	printf("\n");
	return 0;
}

/*
�����Ĳ�������

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
  �ַ�������ַ���
*/
#include <string.h>
int main_80() {
	
	//�ַ����������н����ַ�'\0'���ַ�����
	char *ss = "hello"; // ���ڴ���"hello"��������ŵ�: h e l l o '\0'

	int len = strlen(ss);
	printf("len of ss is:%d\n", len);

	//�ַ�����
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
			printf("��ʾ��ǰĿ¼\n");
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

int sub(int x, int y) { //�������壬x,y����ʽ����	
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
			printf("��ʾ��ǰĿ¼\n");
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
	printf("a: ���һ��ѧ����Ϣ\n");
	printf("f: ����һ��ѧ����Ϣ\n");
	printf("s: ��ʾ����ѧУ��Ϣ\n");
	printf("q. �����˳�\n");
}
int main_exer4() {
	int ids[MAX_NUM];
	float programs[MAX_NUM];
	float maths[MAX_NUM];
	int num = 0;

	char cmd;

	int id; float prog, math; //һ��ѧ������Ϣ

	showMenuStudent();
	while (1) {
		printf("��ѡ����Ӧ����:");
		scanf_s("%c", &cmd, 1);
		switch (cmd) {
		case 'a':
		case 'A':
			printf("������ѧ����Ϣ(id,prog,math):\n");
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


/*struct����ṹ����*/
struct student {
	int id;
	double program, math;
};

int main_90() {
	struct student stu;  //����һ������stu���������ǽṹ���� struct student
	stu.id = 3;   // .���ǳ�Ա��������������ڷ��ʽṹ���ͱ����ĳ�Ա��
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
		printf("������ѧ����Ϣ(id,prog,math):\n");
		scanf_s("%d %lf %lf", &(stu.id), &(stu.program), &(stu.math)); //doubleҪ��%lf��ʽ��
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
   ͨ��ָ��һ���ṹ���ͱ�����ָ�����ȡ��������ṹ����
   ���ַ���:
     * ȡ���� �����
     ->��ӷ��������     
*/
int main_92() {
	struct student stu;
	struct student *p;
	p = &stu; //&stu�����;���struct student *
	(*p).id = 20;
	(*p).program = 35.5;
	(*p).math = 55.5;

	printf("%d\t%f\t%f\t\n", stu.id, stu.program, stu.math);

	p->id = 2; // ->�Ǽ�ӷ����������
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
		printf("������ѧ����Ϣ(id,prog,math):\n");
		scanf_s("%d %lf %lf", &(stu.id), &(stu.program), &(stu.math)); //doubleҪ��%lf��ʽ��
																	  
		if (stu.id <= 0) break;
		students[num] = stu;
		num++;
	}

	struct student *p = &(students[0]); // pָ������ĵ�һ��Ԫ�أ���&(students[0])
	                                    // ������students���������һ��Ԫ�صĵ�ַ��
	                                    // ���ȼ���&(students[0])
	                                    //���Ҳ����д��
	struct student *q = p + num - 1; // qָ�����һ��Ԫ�� struct student *p = students;
	for (; p <= q; p++ )
		printf("%d\t %f\t%f\n", p->id, p->program, p->math);
	return 0;
}

//-----------------
void InputStudent(struct student *s) {
	printf("������ѧ����Ϣ(id,prog,math):\n");
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


//----------��̬����---
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
		
		if (num == capacity) {//�ռ��Ѿ�������Ҫ��������
			struct student *p = (struct student *) realloc(students,
				(capacity+ INC_SIZE) *sizeof(struct student));
			if (p == 0) {
				printf("�ռ�����ʧ�ܣ����������\n");
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
�ڴ��3�֣�
1����̬�洢�����䣺ȫ�ֱ����;�̬����
2) ջ�Ϸ���ģ� �����ľֲ�����
3) ��̬����ģ�
*/


//��̬����
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

//ȫ�ֱ���
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


//C++�����ñ���:�����������ı���
int main_120() {
	int a = 9;
	int &b = a;
	b = 3;
	printf("%d\n", a);
	return 0;
}
//���ñ�����Ҫ�ô�����Ϊ����֮��Ĳ�������
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
  C++�������
  C++�ַ���string
*/
#include<iostream> //C++����������ļ��� ͷ�ļ�
using std::cout;  //cout�Ǳ�׼���ֿռ�std�ﶨ���һ����ʾ����̨���ڵı���
using std::cin;   //cin�Ǳ�׼���ֿռ�std�ﶨ���һ����ʾ���̵ı���
int main_130() {
	int x, y;
	cin >> x >> y;  
	int z = x + y;
	cout << z << "\n";
	return 0;
}

#include <string>  //C++���ַ��� ͷ�ļ�
using std::string; //string�Ǳ�׼���ֿռ�std�ﶨ���һ���ַ�������
int main_131() {
	string s, t("world");
	s = "hello";
	string ss = s + t;
	//printf("%s", ss.c_str());
	cout << ss << "\n";  //  <<��C++������������	
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