
#include <iostream>

using namespace std;

typedef double ElemType;
typedef struct {
	ElemType *r; //   ElemType r[100];
	int listsize;
	int length;
}SqList;

bool initList(SqList &L, int initsize = 100) {
	L.r = new ElemType[initsize];
	if (!L.r) return false;
	L.listsize = initsize;
	L.length = 0;
	return true;
}
bool push_back(SqList &L, ElemType e) {
	if (L.length == L.listsize) return false;
	L.r[L.length] = e;  //0 ,1,..,length-1
	L.length++;
	return true;
}
bool GetElem(SqList L, int i, ElemType &e) {
	if (i<1 || i>L.length) return false;
	e = L.r[i - 1];
	return true;
}

bool insertList(SqList &L, int i, ElemType e) {
	if (i < 1 || i > L.length + 1)
		return false;
	if (L.length == L.listsize)
		return false;
	for (int j = L.length; j >= i; j--) {
		L.r[j] = L.r[j - 1];
	}
	L.r[i - 1] = e;
	L.length++;
	return true;
}
bool deleteList(SqList &L, int i) {
	if (i < 1 || i > L.length)
		return false;
	ElemType *p;
	p = i - 1;
	--L.length;
	return true;
}

void outList(SqList L, int start = 0) {
	ElemType e;
	for (int i = start; i < L.length; i++) {
		//GetElem(L, i, e);
		e = L.r[i];
		std::cout << e << "\n";
	}
	std::cout << "\n";
}

int main() {
	SqList list;
	ElemType e = 45.6;
	initList(list);

	insertList(list,1,e);
	e = 56.6;
	insertList(list, 1, e);
	e = 66.6;
	insertList(list, 1, e);

	outList(list);

	deleteList(list, 2);
	outList(list);
	return 0;
}