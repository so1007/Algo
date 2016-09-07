#include"ugraph.h"
#include<iostream>
using namespace std;
void main(){
	ugraph G(13);
	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(0,6);
	G.addEdge(0,5);
	G.addEdge(5,3);
	G.addEdge(5,4);
	G.addEdge(3,4);
	G.addEdge(6,4);
	G.addEdge(7,8);
	G.addEdge(9,10);
	G.addEdge(9,12);
	G.addEdge(9,11);
	G.addEdge(11,12);
	
	Paths paths(G,0);
	paths.DepthFirstSearch(G,0);
	auto w=paths.pathTo(4);

	const int a = 10; 
	int * p = (int *)(&a); 
	*p = 20; 
	std::cout<<"a = "<<a<<", *p = "<<*p<<std::endl; 
	system("pause");
}