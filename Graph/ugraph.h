#ifndef UGRAPH_H
#define UGRAPH_H
#include<set>
#include<istream>
#include<stack>


class ugraph{
public:
	ugraph(int v):V(v){
		adj=new std::set<int>[v]();
	}
	~ugraph(){
		if(adj!=nullptr) delete[] adj;
	}
	void addEdge(int v,int w){
		adj[v].insert(w);
		adj[w].insert(v);
	}
	 std::set<int>& Adj(int v){
		return adj[v];
	}
	 int vexNum() const{
		 return V;
	 }
private:
	int V;
	std::set<int> *adj;

};

class Paths{
public:
	Paths(const ugraph& G,int s):vetex(s){
		marked=new bool[G.vexNum()];
		memset(marked,false,G.vexNum());
		edgeTo=new int[G.vexNum()];
		memset(edgeTo,-1,G.vexNum()*sizeof(int));
	}
	~Paths(){
		delete[] marked;
		delete[] edgeTo;
	}
	void DepthFirstSearch(ugraph& G,int s){
		dfs(G,s);
	}
	bool hasPathTo(int v){
		return marked[v];
	}
	std::stack<int> pathTo(int v){
		std::stack<int> path;
		if(!marked[v]) return path;
		int w=v;
		while(edgeTo[w]!=vetex){
			path.push(edgeTo[w]);
			w=edgeTo[w];
		}
		path.push(vetex);
		return path;
	}
private:
	void dfs(ugraph& G, int v){
		marked[v]=true;
		for(auto& w:G.Adj(v)){
			if(!marked[w]){
				dfs(G,w);
				edgeTo[w]=v;
			}
		}
	}
	int vetex;
	bool *marked;
	int *edgeTo;
};




#endif