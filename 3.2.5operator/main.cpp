#include "SqStack.h"
#include<cstdio>
#include<cstring>
using namespace std;


char op[]={'+','-','*','/','(',')','#','\0'};

char relation[7][7]=
{
	{'>','>','<','<','<','>','>'},
	{'>','>','<','<','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'<','<','<','<','<','=','?'},
	{'>','>','>','>','?','>','>'},
	{'<','<','<','<','<','?','='}
};

bool In(char c, char OP[])
{
	char* locate=strchr(op,c);
	if(locate!=NULL) return true;
	else return false;
}

int getIndex(char c)
{
	int i;
	switch (c)
	{
	case '+': i=0;
		break;
	case '-': i=1;
		break;
	case '*': i=2;
		break;
	case '/': i=3;
		break;
	case '(': i=4;
		break;
	case ')': i=5;
		break;
	case '#': i=6;
		break;
	}
	return i;
}

char Preceed(char c1, char c2)
{
	int i=getIndex(c1);
	int j=getIndex(c2);
	return relation[i][j];
}


char Operate(char a, char op, char b)
{
	char result;
	switch (op)
	{
	case '+': return a+b;
		break;
	case '-': return a-b;
		break;
	case '*': return a*b;
		break;
	case '/': return a/b;
		break;
	}
	
}
void main()
{
	SqStack OPTR;
	SqStack OPND;
	char c,temp,a,b;
	InitStack(OPTR); Push(OPTR,'#');
	InitStack(OPND); c=getchar();
	while(c!='#'||GetTop(OPTR,temp)!='#'){
		if(!In(c,op)) {
			c=c-'0';
			Push(OPND,c); c=getchar();
		}
		else{
			switch (Preceed(GetTop(OPTR,temp),c))
			{
			case '<': Push(OPTR,c); c=getchar();
				break;
			case '=': Pop(OPTR,temp); c=getchar();
				break;
			case '>': Pop(OPND,b);Pop(OPND,a);Pop(OPTR,temp);
				Push(OPND,Operate(a,temp,b));
				break;
			}
		}
	}

	char result;GetTop(OPND,result);
	printf("%d\n",int(result));


	DestroyStack(OPND);
	DestroyStack(OPTR);
}
