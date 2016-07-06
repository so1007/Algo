#pragma once


template<class T>
class node{
public:
	T item;
	node<T>* next;
};


template <class T>
class linkQueue
{
private:
	friend class node<T>;
	node<T>* head;
	node<T>* tail;
public:
	linkQueue(void){
		head=NULL;
		tail=NULL;
	}
	~linkQueue(void){
		while(head!=NULL){
			node<T>* oldHead=head;
			head=head->next;
			delete oldHead;
		}
	}
	int isEmpty(void){
		return (head==NULL);
	}
	void enqueue(T item);
	T dequeue(void);
};

template<class T>
void linkQueue<T>::enqueue(T item){
	node<T>* oldtail=tail;
	tail=new node<T>;
	tail->item=item;
	tail->next=NULL;
	if(!isEmpty()){
		oldtail->next=tail;
	}
	else{
		head=tail;
	}
}

template <class T>
T linkQueue<T>::dequeue(){
	node<T>* oldhead=head;
	head=head->next;
	if(isEmpty()){
		tail=NULL;
	}
	return oldhead->item;
}
