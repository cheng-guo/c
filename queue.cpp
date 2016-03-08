
#include <iostream>

typedef double ElemType;

typedef struct lnode {
	ElemType data;
	struct lnode *next;
}LNode;

typedef struct {
	LNode *front;
	LNode *rear;
}LkQueue;


bool InitQueue(LkQueue &Q) {
	Q.front = Q.rear = (LNode *)malloc(sizeof(LNode)); //L = new LNode;
	if (!Q.front) return false;
	Q.front->next = 0; 
	return true;
}

bool EnQueue(LkQueue &Q, ElemType e) {
	LNode * p = (LNode *)malloc(sizeof(LNode));
	p->next = 0;
	p->data = e;

	Q.rear->next = p;
	Q.rear = p;

	return true;

}

bool DeQueue(LkQueue &Q, ElemType &e) {
	if (Q.front == Q.rear) return false;
	LNode *q = Q.front->next;
	Q.front->next = q->next;
	e = q->data;
	free(q);
	return true;
}

bool GetFront(LkQueue &Q, ElemType &e) {
	if (Q.front == Q.rear) return false;
	e = Q.front->next->data;
	return true;
}

int main() {
	LkQueue q;
	InitQueue(q);
	EnQueue(q, 30.5);
	EnQueue(q, 40.5);
	EnQueue(q, 50.5);
	EnQueue(q, 60.5);

	ElemType e;
	DeQueue(q, e); 
	std::cout << e << "\n";
	DeQueue(q, e);
	std::cout << e << "\n";
	DeQueue(q, e);
	std::cout << e << "\n";

	std::cout << "现在队列里的对头元素是:\n";
	GetFront(q, e);
	std::cout << e << "\n";

	return 0;
}