//http://www.runoob.com/cprogramming/c-tutorial.html 
#include <stdio.h> 
/*
   Thisi is my first C program
   hello world
*/

int main_00() {
	printf("hello   world\n\n"); //  n��ʾ���з���newline
	return 0;
}

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

int main_03() {
	float y = 45.67; //������doule��4���ֽڣ�
	double x = 34.56;  //������doule��8���ֽڣ���float���ȸ��ߣ�ռ���ڴ浱ȻҲ�࣬����ʱ��Ҳ��
	
	scanf_s("%f", &y);

	double z = x + y; //�������ͬ���͵Ľ������㣬����y����float������Ϊdouble
	printf("%f+%7.2f=:%f\n", x, y, z);
	return 0;
}

#include <stdio.h>
void main_04(){
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
//�����������http://www.runoob.com/cprogramming/c-operators.html


//��������Ϳ��Բο���http://www.tutorialspoint.com/cprogramming/c_data_types.htm 

//������䣺ѭ��������

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

int main_40() {
	char cmd,c;
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


//--------------------����-------------------
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

int main() {
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