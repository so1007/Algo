#include "SqStack.h"
#include<memory>
using namespace std;

int amaze[10][10]={
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
int footprint[10][10]={0};
int mmaze[10][10];
SqStack S;

int MazePath(int maze[10][10] ,PosType start,PosType end);
int Pass(PosType pos);
void FootPrint(PosType pos);
PosType NextPos(SElemType &e);
void MarkPrint(PosType pos);

void main()
{
	memcpy(mmaze,amaze,sizeof(amaze));
	memcpy(footprint,amaze,sizeof(amaze));
	PosType start={1,1};
	PosType end ={8,8};

	MazePath(mmaze,start,end);
	PrintStack(S);
	ClearStack(S);
	DestroyStack(S);

}

int MazePath(int maze[10][10],PosType start,PosType end)
{
	InitStack(S); PosType curpos = start;
	int curstep = 1;
	SElemType e;
	do 
	{
		if (Pass(curpos))
		{
			FootPrint(curpos);
			e.ord=curstep; e.seat=curpos; e.di=1;
			Push(S,e);
			if((curpos.x==end.x)&&(curpos.y==end.y)) return true;
			curstep++;
			curpos=NextPos(e);
			//PrintStack(S);
		} 
		else
		{
			if(!StackEmpty(S)){
				Pop(S,e);
				while (e.di==4&&!StackEmpty(S))
				{
					MarkPrint(e.seat);
					Pop(S,e);
				}
				if(e.di<4){
					e.di++; Push(S,e);
					curpos=NextPos(e);
					//PrintStack(S);
				}
			}
		}
	} while (!StackEmpty(S));
	return false;
}

int Pass(PosType pos)
{
	if( (footprint[pos.x][pos.y])!=1 && (mmaze[pos.x][pos.y]!=1)) return true;
	else return false;
}
void FootPrint(PosType pos)
{
	footprint[pos.x][pos.y]=1;
}
PosType NextPos(SElemType &e)
{
	PosType pos=e.seat;
	switch (e.di)
	{
	case 1: pos.y++;
		break;
	case 2: pos.x++;
		break;
	case 3: pos.y--;
		break;
	case 4: pos.x--;
		break;
	}
	return pos;

}
void MarkPrint(PosType pos)
{
	mmaze[pos.x][pos.y]=1;
}