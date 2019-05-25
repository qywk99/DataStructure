// （1）按屏幕提示用前序方法建立一棵二叉树，并能按凹入法显二叉树结构。
// （2）编写前序遍历、中序遍历、后序遍历，层次遍历程序。
// （3）编写求二叉树的叶结点数，总结点数和深度和程序。
// （4）设计一个选择式菜单，以菜单方式选择下列操作。
//                           二 叉 树 子系 统
//                   ***********************************
//                   *      1－－－－建 二 叉 树       *
//                   *      2－－－－凹 入 显 示       *
//                   *      3－－－－先 序 遍 历       *
//                   *      4－－－－中 序 遍 历       *
//                   *      5－－－－后 序 遍 历       *
//                   *      6－－－－层 次 遍 历       *
//                   *      7－－－－求 叶 子 数       *
//                   *      8－－－－求 结 点 数       *
//                   *      9－－－－求 树 深 度       *
//                   *      0－－－－返       回       *
//                  ***********************************
#include <iostream>
#include <malloc.h>
using namespace std;
char ch;
int m, n;
typedef struct BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

typedef BiTree QueueElementType;
typedef struct Node
{
    QueueElementType data;
    struct Node  *next;
} LinkQueueNode;

typedef struct
{
    LinkQueueNode *front; 
    LinkQueueNode *rear;
} LinkQueue;


//前序遍历建立二叉链表
void InitBiTree(BiTree& T) {
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else {
		T = new BiTNode;
		T->data = ch;
		InitBiTree(T->lchild);
		InitBiTree(T->rchild);
	}
}
//遍历二叉树
void TraverseBiTree(BiTree T, int number) {
	if (T) {
		if (number == 0) cout << T->data << " ";//先序遍历
		TraverseBiTree(T->lchild, number);
		if (number == 1) cout << T->data << " ";//中序遍历
		TraverseBiTree(T->rchild, number);
		if (number == 2) cout << T->data << " ";//后序遍历
	}
}
//节点数
int NodeCout(BiTree T) {
	if (T)
		return NodeCout(T->lchild) + NodeCout(T->rchild) + 1;
	else
		return 0;
}
//叶子节点数
int LeafNodeCout(BiTree T) {
	if (T) {
		if (T->lchild or T->rchild) {
			return LeafNodeCout(T->lchild) + LeafNodeCout(T->rchild);
		}
		else
			return 1;
	}
	else
		return 0;
}

//凹入显示；
void Dent(BiTree T, int depth) {
	int i;
	if (T) {
		for (i = 0; i < depth; i++) {
			cout << T->data;
		}
		cout << endl;
		Dent(T->lchild, depth - 1);
		Dent(T->rchild, depth - 1);
	}
}

//初始化队列
int InitQueue(LinkQueue *Q ) {
    Q->front=(LinkQueueNode * )malloc(sizeof(LinkQueueNode));
    if(Q->front != NULL){
        Q->rear=Q->front;
        Q->front->next=NULL;
        return 1;
    }
    else return 0;//溢出
}
//元素x入链队列 尾插法
int EnterQueue(LinkQueue *Q,QueueElementType x) {
    LinkQueueNode * newnode;
    newnode=(LinkQueueNode *) malloc(sizeof(LinkQueueNode));
    if(newnode != NULL){

        newnode->data=x;
        newnode->next=NULL;
        Q->rear->next=newnode;
        Q->rear=newnode;
        return 1;
    }
    else
		return 0;
}
//链队列出队 从开始的头开始取
int DeleteQueue(LinkQueue *Q,QueueElementType *x ) {
    LinkQueueNode *p;
    if(Q->front==Q->rear)
        return 0;
    p=Q->front->next;
    Q->front->next=p->next;
    if(Q->rear==p )
         Q->rear=Q->front;  //如果去掉结点p后，队列为空 不要忘记将队列置空
    *x=p->data;
    free(p);
    return 1;
}
//层次遍历
int LevelOrderTraverse(BiTree  T) {
	LinkQueue  Q;
    BiTree p;
    InitQueue(&Q);
    if(T==NULL)
		return 0;
    EnterQueue(&Q,T);
    while(Q.front!=Q.rear){
        if(DeleteQueue(&Q,&p));
            cout<<p->data;
        if(p->lchild)
			EnterQueue(&Q,p->lchild);
        if(p->rchild)
			EnterQueue(&Q,p->rchild);
    }
    return 1;

}
//二叉树深度
int Depth(BiTree T) {
	if (T) {
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		return m > n ? m + 1 : n + 1;
	}
	else
		return 0;
}
//功能展示
void ShowFuntion() {
	cout << "\t\t\t\t二 叉 树 子 系 统" << endl;
	cout << "***************************************************************************" << endl;
	cout << "1.建二叉树\t2.凹入显示\t3.先序遍历\t4.中序遍历\t5.后序遍历" << endl;
	cout << "6.层次遍历\t7.求叶子数\t8.求节点数\t9.求树深度\t0.返    回" << endl;
	cout << "***************************************************************************" << endl;
	cout << "请选择相应的功能序号：";
}
int main() {
	int j;
	BiTree Tree=NULL;
	while (true) {
		ShowFuntion();
		cin >> j;
		cout << endl;
		switch (j) {
		case 1:
			cout<<"前序遍历建立二叉树，以'#'表示空："<<endl;
			InitBiTree(Tree);
			break;
		case 2:
			cout<<"凹入显示"<<endl;
			Dent(Tree, Depth(Tree));
			break;
		case 3:
			cout << endl << "先序遍历:";
			TraverseBiTree(Tree, 0);
			cout<<endl;
			break;
		case 4:
			cout << endl << "中序遍历:";
			TraverseBiTree(Tree, 1);
			cout<<endl;
			break;
		case 5:
			cout << endl << "后序遍历:";
			TraverseBiTree(Tree, 2);
			cout<<endl;
			break;
		case 6:
			cout << "层次遍历" ;
			LevelOrderTraverse(Tree);
			cout<<endl;
			break;
		case 7:
			cout << "叶子节点数：";
			cout<<LeafNodeCout(Tree)<<endl;
			break;
		case 8:
			cout << "节点数：";
			cout<<NodeCout(Tree)<<endl;
			break;
		case 9:
			cout << "二叉树深度：";
			cout<<Depth(Tree)<<endl;
			break;
		case 0:return 0;
		}
	}
}
