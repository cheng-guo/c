#include <iostream>
typedef char ElemType;

typedef struct binode {
	ElemType data;
	struct binode *lchild, *rchild;
}BiNode;

void LevelOrderTraverse(BiNode * T);

//中序遍历二叉树，是一个递归过程。
//对树种的任何一个结点：
//先中序左子树，然后结点本身，然后中序右子树
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

	//上述两个结点是鼓励，互不相干的
	//现在我们要建立父子关系
	root->lchild = p;


	//建立一个新结点，
	p = new BiNode;
	p->lchild = p->rchild = 0;
	p->data = 'C';
	//新结点成为root的右边孩子
	root->rchild = p;

	//建立一个新结点，
	p = new BiNode;
	p->lchild = p->rchild = 0;
	p->data = 'D';

	root->lchild->lchild = p; //D这个结点就成为了B结点的左孩子


	//建立一个新结点，
	p = new BiNode;
	p->lchild = p->rchild = 0;
	p->data = 'E';

	root->lchild->rchild = p; //D这个结点就成为了B结点的左孩子


	IOT(root);  //中序遍历
	std::cout << "\n";

	LevelOrderTraverse(root); //层次遍历
	std::cout << "\n";

	return 0;
}


//二叉树的层次遍历，需要一个队列存放将访问的结点
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
	EnQueue(Q, T); //根结点指针入队
	while (!isEmpty(Q)) { //如果队列不空
		DeQueue(Q, p); //出队一个节点, 并访问之
		std::cout << p->data << " "; // visit(p->data)
		if(p->lchild)
			EnQueue(Q, p->lchild);
		if (p->rchild)
			EnQueue(Q, p->rchild);
	}
	return;
}