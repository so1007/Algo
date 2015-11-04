#ifndef SQSTACK_H_
#define SQSTACK_H_

#include<memory>
#include <iostream>
const int STACK_INIT_SIZE=100;;
const int STACKINCREMENT=10;



template<class T>
class SqStack
{
private:
	T* base;
	T* top;
	int stacksize;
public:
	SqStack();
	~SqStack();
	void Clear(){top=base;}
	int IsEmpty() const	{
		if(base==top) return true; 
		return false;
	}
	int Push(const T t);
	int Pop(const T t);
	T GetTop() const	{
		return base[top-1]
	};
	void Traverse(void (*foo)(T* elem))
	{
		T* temp=base;
		while(temp<top){
			foo(temp);
			temp++;
		}
	}

	void showLength(){
		std::cout<<(long(top)-long(base))/sizeof(T)<<std::endl;
	}
};


template<class T>
SqStack<T>::SqStack()
{
	base=new T[STACK_INIT_SIZE];
	top=base;
	stacksize=STACK_INIT_SIZE;
}

template <class T>
SqStack<T>::~SqStack()
{
	if(base) delete[] base;
}

template <class T>
int SqStack<T>::Push(const T t)
{
	if( (top-base)>=stacksize){
		T* temp=new T[stacksize+STACKINCREMENT];
		if(!temp) return false;
		memcpy(temp,base,sizeof(stacksize));
		delete[] base;
		base=temp;
		stacksize+=STACKINCREMENT;
	}
	*top++=t;
	return true;

}

template<class T>
int SqStack<T>::Pop(const T t)
{
	if (IsEmpty())
	{
		return false;
	}
	t=*(--top);
	return true;
}

#endif