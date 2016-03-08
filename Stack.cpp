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
	//分配空间
	S.base = (ElemType*) malloc	(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S.base)	return false;
	S.top = S.base;           //设置指针
	S.stacksize = STACK_INIT_SIZE;  //设置大小
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

//取栈顶元素
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
	std::cout << "下载栈顶元素:\n";

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
	准备一个栈，用于存放扫描遇到的左括号
	从左向后扫描每一个字符{
	  如果遇到的是左括号，则入栈
	  如果遇到的是右括号，则
	     把栈顶字符和当前字符比较
	     若匹配，则弹出栈顶字符，继续向前扫描
	     若不匹配，程序返回不匹配标志
	}
	当所有字符都扫描完毕，栈应当为空
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
	char *s = "[(])，(()]"; // "{}[([][])]";
	bool ret = kuohao_pipei(s);
	if (ret)
		std::cout << "匹配！\n";
	else std::cout << "不匹配！\n";

	return 0;
}