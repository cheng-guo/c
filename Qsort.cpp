#include <iostream>

using namespace std;

typedef int ElemType;
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
void outList(SqList L,int start=1) {
	ElemType e;
	for (int i = start; i < L.length; i++) {
		//GetElem(L, i, e);
		e = L.r[i];
		std::cout << e << "\n";
	}
	std::cout << "\n";
}


//----------------------QSort----------------------
int Partition(SqList &L, int low, int high) {
	ElemType pivotvalue = L.r[low];
	L.r[0] = L.r[low];    //把最左元素当作基准
	while (low < high) {
		//high向左，直到遇见比pivot小的
		while (low < high && L.r[high] >= pivotvalue)
			high--;
		L.r[low] = L.r[high];
		//low向右，直到遇见比pivot大的
		while (low<high && L.r[low] <= pivotvalue)
			low++;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}

void QSort(SqList &L, int low, int high) {
	if (low < high) {    //待排序数列长度大于1
		int pivotloc = Partition(L, low, high);
		
		//对左子序列进行排序
		QSort(L, low, pivotloc - 1);
		//对右子序列进行排序
		QSort(L, pivotloc + 1, high);
	}
}

//------------SelectSort-------------
int Min(SqList &L, int low, int high) {	
	int index = low;
	for (int i = low + 1; i <= high;i++)
		if (L.r[i] < L.r[index]) {
			index = i;
		}
	return index;
}

void swap(int &a, int &b) {
	int t = a; a = b; b = t;
}
void SelectSort(SqList &L) {
	for (int i = 1; i < L.length; i++) {
		int index = Min(L, i, L.length - 1);
/*		int index = i;
		for (int j = i; j < L.length;j++)
			if (L.r[j] < L.r[index]) {
				index = j;
			}
*/
		if (index != i) {
			swap(L.r[i], L.r[index]);
		}
	}
}


void merge(SqList &A, SqList  &B, SqList &C)
{
	int i = 1, j = 1,k=1;
	while (i < A.length && j < B.length){
		if (A.r[i] <= B.r[j]) {
			C.r[k] = A.r[i]; i++; k++;
		}
		else {
			C.r[k] = B.r[j]; j++; k++;
		}
	}

	while (i < A.length) {
		C.r[k] = A.r[i]; i++; k++;
	}
	while (j < B.length) {
		C.r[k] = B.r[j]; j++; k++;
	}
	C.length = A.length -1+ B.length-1; //1..3  1...5 1,...8
	C.length++; 
}


//---------------------------
int main()
{
	SqList list;
	initList(list); //initList(list,10);
	push_back(list, -1);
	push_back(list, 25);
	push_back(list, 11);
	push_back(list, 19);
	push_back(list, 81);
	push_back(list, 2);
	push_back(list, 7);
	push_back(list, 32);
	push_back(list, 14);

	outList(list);

	
//	QSort(list, 1, 8);
	SelectSort(list);
	outList(list);
	

	SqList list2;
	initList(list2); //initlist2(list2,10);
	push_back(list2, -2);
	push_back(list2, 42);
	push_back(list2, 46);
	push_back(list2, 15);
	push_back(list2, 26);
	push_back(list2, 1);
	push_back(list2, 6);
	push_back(list2, 23);
	push_back(list2, 57);

	outList(list2);	
	SelectSort(list2);
	outList(list2);

	SqList list3;
	initList(list3); 
	merge(list, list2, list3);
	outList(list3);
	
	int sss;   cin >> sss;
	return 0;

}
