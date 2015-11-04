#include "SqStack.h"

#include<cstdlib>
#include<cstdio>


int InitStack(SqStack &S){
	S.base=(SElemType *) malloc(sizeof(SElemType)* STACK_INIT_SIZE);
	if(!S.base) exit(0);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return true;
}

int DestroyStack(SqStack &S)
{
	if(!S.base) exit(0);
	free(S.base);
	S.base=S.top=NULL;
	return true;
	
}

int ClearStack(SqStack &S)
{
	S.top=S.base;
	return true;
}

int StackEmpty(SqStack S)
{
	if(S.base==S.top) return true;
	else return false;
}

int StackLength(SqStack S)
{
	return S.top-S.base;
}

int GetTop(SqStack S, SElemType &e)
{
	if(S.top==S.base) return false;
	e=*(S.top-1);
	return true;
}

int Push(SqStack &S,SElemType e)
{
	if(S.top-S.base>=S.stacksize){
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) exit(0);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return true;

}

int Pop(SqStack &S, SElemType &e)
{
	if(S.base==S.top) return false;
	e=*(--S.top);
	return true;
}

int StackTraverse(SqStack S,int(*visit)(SElemType&))
{
	SElemType* temp=S.base;
	while(temp!=S.top)
	{
		visit(*temp);
		temp++;
	}
	return true;
}

void PrintStack(SqStack S)
{
	if(S.base==S.top) printf("Contain NO Element.\n");
	SElemType* t=S.top-1;
	while(t>=S.base)
	{
		printf("(%2d,%2d) Di:%d <<<---",(*t).seat.x,(*t).seat.y,(*t).di);
		t--;
	}
	printf("\n");

}