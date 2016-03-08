#include <iostream>
typedef char ElemType;

typedef struct binode {
	ElemType data;
	struct binode *lchild, *rchild;
}BiNode;

void LevelOrderTraverse(BiNode * T);

//�����������������һ���ݹ���̡�
//�����ֵ��κ�һ����㣺
//��������������Ȼ���㱾��Ȼ������������
void IOT(BiNode *T) {
	if (!T) return;
	IOT(T->lchild);
	std::cout << T->data << " "; //visit(T->data)
	IOT(T->rchild);
}

int main() {
	
	BiNode *root;
	root = new BiNode;
	root->lchild = root->rchild = 0;
	root->data = 'A';

	BiNode *p = new BiNode;
	p->lchild = p->rchild = 0;
	p->data = 'B';

	//������������ǹ�����������ɵ�
	//��������Ҫ�������ӹ�ϵ
	root->lchild = p;


	//����һ���½�㣬
	p = new BiNode;
	p->lchild = p->rchild = 0;
	p->data = 'C';
	//�½���Ϊroot���ұߺ���
	root->rchild = p;

	//����һ���½�㣬
	p = new BiNode;
	p->lchild = p->rchild = 0;
	p->data = 'D';

	root->lchild->lchild = p; //D������ͳ�Ϊ��B��������


	//����һ���½�㣬
	p = new BiNode;
	p->lchild = p->rchild = 0;
	p->data = 'E';

	root->lchild->rchild = p; //D������ͳ�Ϊ��B��������


	IOT(root);  //�������
	std::cout << "\n";

	LevelOrderTraverse(root); //��α���
	std::cout << "\n";

	return 0;
}


//�������Ĳ�α�������Ҫһ�����д�Ž����ʵĽ��
typedef BiNode* EType;
typedef struct lnode {
	EType data;
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

bool EnQueue(LkQueue &Q, EType e) {
	LNode * p = (LNode *)malloc(sizeof(LNode));
	p->next = 0;
	p->data = e;

	Q.rear->next = p;
	Q.rear = p;

	return true;
}

bool DeQueue(LkQueue &Q, EType &e) {
	if (Q.front == Q.rear) return false;
	LNode *q = Q.front->next;
	Q.front->next = q->next;
	e = q->data;
	if (Q.rear == q) Q.rear = Q.front;
	free(q);
	return true;
}

bool GetFront(LkQueue &Q, EType &e) {
	if (Q.front == Q.rear) return false;
	e = Q.front->next->data;
	return true;
}
bool isEmpty(LkQueue &Q) {
	return Q.front == Q.rear;
}

void LevelOrderTraverse(BiNode * T) {
	EType p; //BiNode *p
	LkQueue Q; InitQueue(Q);
	EnQueue(Q, T); //�����ָ�����
	while (!isEmpty(Q)) { //������в���
		DeQueue(Q, p); //����һ���ڵ�, ������֮
		std::cout << p->data << " "; // visit(p->data)
		if(p->lchild)
			EnQueue(Q, p->lchild);
		if (p->rchild)
			EnQueue(Q, p->rchild);
	}
	return;
}