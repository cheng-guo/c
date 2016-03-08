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

void outList(SqList L, int start = 0) {
	ElemType e;
	for (int i = start; i < L.length; i++) {
		//GetElem(L, i, e);
		e = L.r[i];
		std::cout << e << "\n";
	}
	std::cout << "\n";
}

void merge(SqList A, SqList B, SqList &C) {
	int i = 0, j = 0, k = 0;
	while (i < A.length && j < B.length) {
		if (A.r[i] <= B.r[j]) {
			C.r[k] = A.r[i];
			i++; k++;
		}
		else {
			C.r[k] = B.r[j];
			j++; k++;
		}
	}

	while (i < A.length) {
		C.r[k] = A.r[i];
		i++; k++;
	}
	while (j < B.length) {
		C.r[k] = B.r[j];
		j++; k++;
	}

	C.length = A.length + B.length;
}

int main() {
	SqList A, B, C;
	initList(A);
	initList(B);
	initList(C);

	push_back(A, 10);
	push_back(A, 20);
	push_back(A, 50);
	push_back(A, 60);
	outList(A);

	push_back(B, 12);
	push_back(B, 23);
	push_back(B, 35);
	outList(B);

	merge(A, B, C);
	outList(C);

	return 0;
}