#ifndef _BITREE_H
#define _BITREE_H

#define	true	1
#define false	0

typedef struct BiTNode 
{
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;

int CreateBiTree(BiTree* T);
int InOrderTraverse(BiTree T,int(*Visit)(char elem));
int DestroyBiTree(BiTree* T);

#endif // !_BITREE_H
