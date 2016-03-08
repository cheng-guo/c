
#include <iostream>

using namespace std;

typedef double ElemType;

struct SqList{
	ElemType *data; //   ElemType data[100];
	int listsize;
	int length;

	SqList(int initsize=10);
	bool push_back(ElemType e);
	bool GetElem(int i, ElemType &e);	
	ElemType& operator[](int i);
	bool insert(int i, ElemType e);
	bool del(int i);
};

SqList::SqList(int initsize) {
	data = new ElemType[initsize];
	if (!data) return;
	listsize = initsize;
	length = 0;
	return ;
}

bool SqList::push_back( ElemType e) {
	if (length == listsize) return false;
	data[length] = e;  //0 ,1,..,length-1
	length++;
	return true;
}

bool SqList::GetElem(int i, ElemType &e) {
	if (i<1 || i>length) return false;
	e = data[i - 1];
	return true;
}

ElemType& SqList::operator[](int i) {
	ElemType e = -1;
	if (i<0 || i >= length) return e;
	return data[i];
}


bool SqList::insert( int i, ElemType e) {
	if (i < 1 || i > length + 1)
		return false;
	if (length == listsize)
		return false;
	for (int j = length; j >= i; j--) {
		data[j] = data[j - 1];
	}
	data[i - 1] = e;
	length++;
	return true;
}
bool SqList::del( int i) {
	if (i < 1 || i > length)
		return false;
	for (int j = i + 1; j <= length; j++)
		data[j - 2] = data[j - 1]; //序号是j（下标是j-1）的元素移动到前一个位置。 
	--length;
	return true;
}


void out(SqList L) {
	ElemType e;
	for (int i = 1; i <= L.length; i++) {
		e = L[i-1];
		std::cout << e << "\n";
	}
	std::cout << "\n";
}


int main_00() {
	SqList list;
	ElemType e = 45.6;
	

	list.insert(1, e);
	e = 56.6;
	list.insert(1, e);
	e = 66.6;
	list.insert(1, e);

	out(list);

	list.del(2);
	out(list);

	list[1] = 37.5;
	std::cout << list[1] << "\n";

	return 0;
}

int main() {
	SqList list;
	
	list.push_back(10.5);
	list.push_back(20.5);
	list.push_back(30.5);
	list.push_back(40.5);
	list.push_back(50.5);
	list[2] = -20.5;
	
	for (int i = 0; i < list.length; i++)
		std::cout << list[i] << "\n";
	std::cout << "\n";

	return 0;
}
