#include <iostream>

typedef char ElemType;
//typedef double ElemType;

#define STACK_INIT_SIZE 10
typedef struct {
	ElemType *base;
	ElemType *top;
	int       stacksize;
} SqStack;

int InitStack(SqStack &S) {
	//����ռ�
	S.base = (ElemType*) malloc	(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S.base)	return false;
	S.top = S.base;           //����ָ��
	S.stacksize = STACK_INIT_SIZE;  //���ô�С
	return true;
}

int Push(SqStack &S, ElemType e) {
	if (S.top - S.base == S.stacksize) return false;
	*(S.top) = e;
	S.top++;
	return true;
}

int Pop(SqStack &S, ElemType &e) {
	if (S.top == S.base) return false;
	S.top--;
	e = *(S.top);
	return true;
}

//ȡջ��Ԫ��
int Top(SqStack &S, ElemType &e) {
	if (S.top == S.base) return false;
	e = *(S.top-1);
	return true;
}

bool isEmpty(SqStack &S) {
	return S.top == S.base;
}

/*
int main() {
	SqStack S;
	InitStack(S);
	Push(S, 30.5);
	Push(S, 40.5);
	Push(S, 50.5);
	std::cout << "����ջ��Ԫ��:\n";

	ElemType e;
	Top(S, e);
	std::cout << e << "\n";
	Pop(S, e);
	Top(S, e);
	std::cout << e << "\n";
	return 0;
}
*/

bool isLeftKuohao(char ch) {
	if (ch == '(' || ch == '[' || ch == '{')
		return true;
	return false;
}
bool isRightKuohao(char ch) {
	if (ch == ')' || ch == ']' || ch == '}')
		return true;
	return false;
}
bool isMatch(char left, char right) {
	if (left == '('  && right == ')'
		|| left == '[' &&right == ']'
		|| left == '{' &&right == '}'
		)
		return true;
	return false;
}
bool kuohao_pipei(char *str) {
	/*
	׼��һ��ջ�����ڴ��ɨ��������������
	�������ɨ��ÿһ���ַ�{
	  ����������������ţ�����ջ
	  ����������������ţ���
	     ��ջ���ַ��͵�ǰ�ַ��Ƚ�
	     ��ƥ�䣬�򵯳�ջ���ַ���������ǰɨ��
	     ����ƥ�䣬���򷵻ز�ƥ���־
	}
	�������ַ���ɨ����ϣ�ջӦ��Ϊ��
	*/
	SqStack S; InitStack(S);

	for (int i = 0; str[i] != '\0'; i++) {
		if (isLeftKuohao(str[i])) {
			Push(S, str[i]);
		}
		else if (isRightKuohao(str[i])) {
			char ch;
			Top(S, ch);
			if (isMatch(ch, str[i]) == false)
				return false;
			else {
				Pop(S, ch);
			}
		}
	}

	if (isEmpty(S)) return true;
	return false;	
}

int main() {
	char *s = "[(])��(()]"; // "{}[([][])]";
	bool ret = kuohao_pipei(s);
	if (ret)
		std::cout << "ƥ�䣡\n";
	else std::cout << "��ƥ�䣡\n";

	return 0;
}