#ifndef SQSTACK_H_
#define SQSTACK_H_

const int STACK_INIT_SIZE=100;;
const int STACKINCREMENT=10;

typedef struct  
{
	int x;
	int y;
}PosType;

typedef struct  
{
	int ord;
	PosType seat;
	int di;

} SElemType;

typedef struct  
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

int InitStack(SqStack &S);
int DestroyStack(SqStack &S);
int ClearStack(SqStack &S);
int StackEmpty(SqStack S);
int StackLength(SqStack S);
int GetTop(SqStack S, SElemType &e);
int Push(SqStack &S,SElemType e);
int Pop(SqStack &S, SElemType &e);
int StackTraverse(SqStack S,int(*visit)(SElemType &e));
void PrintStack(SqStack S);
#endif