#include"BiTree.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int CreateBiTree(BiTree* T){
	char ch=getchar();
	if(ch!=' '){
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->data=ch; (*T)->lchild=NULL; (*T)->rchild=NULL;
		if(CreateBiTree(&(*T)->lchild))
			if(CreateBiTree(&(*T)->rchild))
				return true;
		return false;

	}else{
		(*T)=NULL;
		return true;
	}
	return false;
}

int InOrderTraverse(BiTree T,int(*Visit)(char elem)){
	if(T!=NULL){
		if(Visit(T->data))
			if(InOrderTraverse(T->lchild,Visit))
				if(InOrderTraverse(T->rchild,Visit))
					return true;
		return false;
	}
	else{
		return true;
	}
	return false;
}

int DestroyBiTree(BiTree* T){
	if((*T)!=NULL){
		if(DestroyBiTree(&(*T)->lchild))
			if(DestroyBiTree(&(*T)->rchild)){
				free(*T); (*T)=NULL;
				return true;
			}
		return false;
	}
	return true;
}