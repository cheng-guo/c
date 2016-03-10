/*
//�������أ�C++������������������ͬ�����֣�ֻҪ���ǵĲ����ǲ�ͬ��
int add(int x, int y){
	return x + y;
}

double add(double x, double y){
	return x + y;
}

int main(){
	int a = 3, b = 8l;
	double c = 3.3, d = 5.6;

	int e = add(a, b);
	add(c, d);
	return 0;
}
*/

//C++����ģ��,ʹ�ô���߸����ԣ�ֻҪдһ�δ���Ϳ����ˡ�
template<typename T>
T add(T x, T y){
	return x + y;
}
int main_00(){
	int a = 3, b = 8l;
	double c = 3.3, d = 5.6;

	int e = add(a, b);
	add(c, d);
	return 0;
}

//C++����ģ��
template<typename ElemType>
class SqList{
public:
	ElemType *data; //   ElemType data[100];
	int listsize;
	int length;

	SqList(int initsize = 10);
	bool push_back(ElemType e);	
	ElemType& operator[](int i);
	bool insert(int i, ElemType e);
	bool del(int i);
};

template<typename ElemType>
SqList<ElemType>::SqList(int initsize) {
	data = new ElemType[initsize];
	if (!data) return;
	listsize = initsize;
	length = 0;
	return;
}

template<typename ElemType>
bool SqList<ElemType>::push_back(ElemType e) {
	if (length == listsize) return false;
	data[length] = e;  //0 ,1,..,length-1
	length++;
	return true;
}

template<typename ElemType>
ElemType& SqList<ElemType>::operator[](int i) {
	if (i < 0 || i >= length) throw "out or range";
	return data[i];
}

template<typename ElemType>
bool SqList<ElemType>::insert(int i, ElemType e) {
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

template<typename ElemType>
bool SqList<ElemType>::del(int i) {
	if (i < 1 || i > length)
		return false;
	for (int j = i + 1; j <= length; j++)
		data[j - 2] = data[j - 1]; //�����j���±���j-1����Ԫ���ƶ���ǰһ��λ�á� 
	--length;
	return true;
}

#include <iostream>
int main() {
	SqList<double> list;

	list.push_back(10.5);
	list.push_back(20.5);
	list.push_back(30.5);
	list.push_back(40.5);
	list.push_back(50.5);
	list[2] = -20.5;

	for (int i = 0; i < list.length; i++)
		std::cout << list[i] << "\n";
	std::cout << "\n";

	SqList<char> list2;
	list2.push_back('A');
	list2.push_back('B');
	list2.push_back('C');
	for (int i = 0; i < list2.length; i++)
		std::cout << list2[i] << "\n";
	std::cout << "\n";

	return 0;
}