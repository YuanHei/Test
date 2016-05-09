#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef enum { TRUE, FALSE } Status;

typedef struct BiNode
{
	char          data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode, *BiTree;

Status Create(BiTree *T)
{
	char ch;
	scanf("%c", &ch);

	if (' ' == ch)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiNode*)malloc(sizeof(BiNode));
		(*T)->data = ch;
		Create(&((*T)->lchild));
		Create(&((*T)->rchild));
	}

	return TRUE;
}

//前序遍历
//递归
void PreOrderTravers(BiTree T)
{
	if (T)
	{
		printf("%c ", T->data);
		PreOrderTravers(T->lchild);
		PreOrderTravers(T->rchild);
	}
}

//非递归
void PreOrderTravers_(BiTree T)
{
	BiNode *st[MaxSize];
	BiNode *p = T;
	int top = -1;
	do
	{
		while (p)
		{
			printf("%c ", p->data);
			st[++top] = p;
			p = p->lchild;
		}
		p = st[top--];
		p = p->rchild;
	} while (top != -1 || p != NULL);
}
//中序遍历
//递归
void InOrderTravers(BiTree T)
{
	if (T)
	{
		InOrderTravers(T->lchild);
		printf("%c ", T->data);
		InOrderTravers(T->rchild);
	}
}
//非递归
void InOrderTravers_(BiTree T)
{
	BiNode *st[MaxSize];
	BiNode *p = T;
	int top = -1;

	do
	{
		while (p)
		{
			st[++top] = p;
			p = p->lchild;
		}
		p = st[top--];
		printf("%c ", p->data);
		p = p->rchild;
	} while (top != -1 || p != NULL);
}
//后序遍历
//递归

void PostOrderTravers(BiTree T)
{
	if (T)
	{
		PostOrderTravers(T->lchild);
		PostOrderTravers(T->rchild);
		printf("%c ", T->data);
	}
}

//非递归
void PostOrderTravers_(BiTree T)
{
	//相当于将前序遍历进行修改，在前序遍历中先遍历
	//根结点，再遍历右子树，再遍历左子树。
	BiNode *st[MaxSize], *st_[MaxSize];
	BiNode *p = T;
	int top = -1, top_ = -1;
	do
	{
		while (p)
		{
			st_[++top_] = p;
			st[++top] = p;
			p = p->rchild;
		}
		p = st[top--];
		p = p->lchild;
	} while (top != -1 || p != NULL);
	while (top_ != -1)
	{
		printf("%c ", st_[top_--]->data);
	}
}
int main()
{
	BiTree T;
	Create(&T);
	PreOrderTravers(T);
	printf("\n");
	PreOrderTravers_(T);
	printf("\n");
	InOrderTravers(T);
	printf("\n");
	InOrderTravers_(T);
	printf("\n");
	PostOrderTravers(T);
	printf("\n");
	PostOrderTravers_(T);
	printf("\n");
	return 0;
}
