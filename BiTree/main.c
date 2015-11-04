#include"BiTree.h"

#include<stdio.h>
#include<stdlib.h>


int printTreeElem(char elem){
	printf("%c",elem);
	return true;
}
void main(){

	BiTree T=NULL;
	CreateBiTree(&T);
	InOrderTraverse(T,printTreeElem);
	DestroyBiTree(&T);

	system("pause");
}