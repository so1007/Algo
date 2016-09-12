/*
	【问题描述】
	有一个m*n格的迷宫(表示有m行、n列)，其中有可走的也有不可走的，如果用1表示可以走，0表示不可以走，文件读入这m*n个数据和起始点、结束点(起始点和结束点都是用两个数据来描述的，分别表示这个点的行号和列号)。现在要你分别编程4个程序解决以下4个问题。
	问题1：找出所有可行的道路，要求所走的路中没有重复的点，走时只能是上下左右四个方向。如果一条路都不可行，则输出相应信息(用-l表示无路)。  
	【输入】
	第一行是两个数m，n(1<m，n<15)，接下来是m行n列由1和0组成的数据，最后两行是起始点和结束点。
	【输出】
	问题1：所有可行的路径，描述一个点时用(x，y)的形式，除开始点外，其他的都要用“一>”表示方向。如果没有一条可行的路则输出-1。
	……
	【样例】
	5 6
	1 0 0 1 0 1     
	1 1 1 1 1 1
	0 0 1 1 1 0
	1 1 1 1 1 0
	1 1 1 0 1 1
	1 1
	5 6

	【输出样例】
	(1,1)->(2,1)->(2,2)->(2,3)->(2,4)->(2,5)->(3,5)->(3,4)->(3,3)->(4,3)->(4,4)->(4,5)->(5,5)->(5,6)
	(1,1)->(2,1)->(2,2)->(2,3)->(2,4)->(2,5)->(3,5)->(3,4)->(4,4)->(4,5)->(5,5)->(5,6)
	(1,1)->(2,1)->(2,2)->(2,3)->(2,4)->(2,5)->(3,5)->(4,5)->(5,5)->(5,6)
	(1,1)->(2,1)->(2,2)->(2,3)->(2,4)->(3,4)->(3,3)->(4,3)->(4,4)->(4,5)->(5,5)->(5,6)
	(1,1)->(2,1)->(2,2)->(2,3)->(2,4)->(3,4)->(3,5)->(4,5)->(5,5)->(5,6)
	(1,1)->(2,1)->(2,2)->(2,3)->(2,4)->(3,4)->(4,4)->(4,5)->(5,5)->(5,6)
	(1,1)->(2,1)->(2,2)->(2,3)->(3,3)->(3,4)->(2,4)->(2,5)->(3,5)->(4,5)->(5,5)->(5,6)
	(1,1)->(2,1)->(2,2)->(2,3)->(3,3)->(3,4)->(3,5)->(4,5)->(5,5)->(5,6)
	(1,1)->(2,1)->(2,2)->(2,3)->(3,3)->(3,4)->(4,4)->(4,5)->(5,5)->(5,6)
	(1,1)->(2,1)->(2,2)->(2,3)->(3,3)->(4,3)->(4,4)->(3,4)->(2,4)->(2,5)->(3,5)->(4,5)->(5,5)->(5,6)
	(1,1)->(2,1)->(2,2)->(2,3)->(3,3)->(4,3)->(4,4)->(3,4)->(3,5)->(4,5)->(5,5)->(5,6)
	(1,1)->(2,1)->(2,2)->(2,3)->(3,3)->(4,3)->(4,4)->(4,5)->(5,5)->(5,6)
*/

#include<iostream>
#include<vector>
using namespace std;

const int N=17;
int maze[N][N]={0};
bool marked[N][N]={false};

struct Point{
	int x;
	int y;
	Point(int X=0,int Y=0):x(X),y(Y){}
	friend istream& operator>>(istream& is,Point &p){
		is>>p.x>>p.y;
		return is;
	}
	bool operator==(Point &p) const {
		return (x==p.x)&&(y==p.y);
	}
	void Move(int xx,int yy){
		x+=xx; y+=yy;
	}
	Point nextPoint(int i){
		Point p; p.x=this->x; p.y=this->y;
		switch(i){
		case 0: p.Move(0,1); break;
		case 1: p.Move(1,0); break;
		case 2: p.Move(0,-1); break;
		case 3: p.Move(-1,0); break;
		}

		return p;
	}
};


void dfs(vector<Point>& path,Point& start, Point& end){
	if(start==end){
		// print Path
		for(vector<Point>::iterator it=path.begin();it!=path.end();++it){
			cout<<"("<<(*it).x<<","<<(*it).y<<")";
		}
		cout<<endl;
	}
	for(int i=0;i<4;++i){
		Point next=start.nextPoint(i);
		if ((maze[next.x][next.y]!=0)&&!marked[next.x][next.y]){
			marked[next.x][next.y]=true;
			path.push_back(next);
			dfs(path,next,end);
			path.pop_back();
			marked[next.x][next.y]=false;
		}
	}

}
int main(){
	vector<Point> path;
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j)
			cin>>maze[i][j];
	}
	Point start,end;
	cin>>start>>end;

	marked[start.x][start.y]=true;
	path.push_back(start);
	dfs(path,start,end);
	
	system("pause");
	return 0;
}