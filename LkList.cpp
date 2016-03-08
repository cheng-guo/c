#include <iostream>

typedef double ElemType;

typedef struct lnode {
	ElemType data;
	struct lnode *next;
}LNode;

typedef LNode * LkList;

//bool InitLkList(LkList &L){
bool InitLkList(LNode* &L) {
	L = (LNode *)malloc(sizeof(LNode)); //L = new LNode;
	if (!L) return false;
	L->next = 0; return true;
}

bool GetElem(LNode* L,int i,ElemType &e) {
	LNode *p = L; int j = 0; //LNode *p = L->next; j = 1;
	while (p && j < i) {
		p = p->next; 
		j++;
	}
	if (!p || j>i) return false;
	e = p->data;
	return true;
}
bool SetElem(LNode* L, int i, ElemType e) {
	LNode *p = L; int j = 0; //LNode *p = L->next; j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j>i) return false;
	p->data = e;
	return true;
}

bool InsertList(LNode* L, int i, ElemType e) {
	LNode *p = L; int j = 0; //LNode *p = L->next; j = 1;
	while (p && j < i-1) {
		p = p->next;
		j++;
	}
	if (!p || j>i-1) return false;

	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->next = 0;
	s->data = e;

	s->next = p->next;
	p->next = s;
	return true;
}

bool DeleteList(LNode* L, int i) {
	LNode *p = L; int j = 0; //LNode *p = L->next; j = 1;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j>i - 1) return false;

	LNode *q = p->next;
	p->next = q->next;
	free(q);
	return true;
}

void OutList(LNode* L) {
	LNode *p = L->next;
	while (p) {
		std::cout << p->data << "\n";
		p = p->next;
	}
	std::cout << "\n";
}

int main() {
	LNode* list = 0;
	InitLkList(list);
	InsertList(list,1, 30.0);
	InsertList(list, 1, 40.0);
	InsertList(list, 1, 50.0);
	InsertList(list, 1, 60.0);

	OutList(list);

	DeleteList(list,2);
	OutList(list);

	SetElem(list, 2, 78.56);
	OutList(list);
	return 0;
}