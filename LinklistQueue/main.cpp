#include<iostream>
#include<string>
#include "linkQueue.h"
using namespace std;

int main(){
	linkQueue<int> lq1;
	lq1.enqueue(1);
	lq1.enqueue(2);
	lq1.enqueue(3);
	cout<<lq1.dequeue();
	cout<<lq1.dequeue();
	cout<<lq1.dequeue();
	lq1.enqueue(4);
	lq1.enqueue(5);
	cout<<lq1.dequeue();
	cout<<lq1.dequeue()<<endl;
	system("pause");
	return 0;
}
