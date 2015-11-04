#include "SqStack.h"
#include<iostream>

void printStack(int *t)
{
	std::cout<<*t<<"  ";
}

void twice(int *t)
{
	*t=*t+*t;
}

void main()
{
	SqStack<int> stack;
	stack.Push(1);

	stack.showLength();

	stack.Push(2);
	stack.Push(3);

	stack.showLength();

	stack.Traverse(printStack);
	std::cout<<std::endl;

	stack.Traverse(twice);

	stack.Traverse(printStack);
	std::cout<<std::endl;

	stack.Clear();
	stack.showLength();

	int d;
	std::cin>>d;
}
