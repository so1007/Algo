#include<iostream>
using namespace std;

#define In(x,y,z) (x>=y && z>=x)
const int N=101;
int h[N][N];
int f[N][N];
int pos[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int r,c;

int dp(int x,int y);
int dp(int x,int y){
	if(f[x][y]>0) return f[x][y];
	f[x][y]=1;
	for(int i=0;i<4;++i){
		int xx=x+pos[i][0];
		int yy=y+pos[i][1];
		if(In(xx,1,r) && In(yy,1,c) && h[x][y]>h[xx][yy] && f[x][y]<dp(xx,yy)+1 ){
			f[x][y]=f[xx][yy]+1;
		}
	}
	return f[x][y];
}

int main(){
	while(cin>>r>>c){
		memset(h,0,sizeof(h));
		memset(f,-1,sizeof(f));
		for(int i=1;i<=r;++i)
			for(int j=1;j<=c;++j)
				cin>>h[i][j];
		int MaxPath=0;
		for(int i=1;i<=r;++i)
			for(int j=1;j<=c;++j){
				if(MaxPath<dp(i,j)) MaxPath=f[i][j];
			}
		cout<<MaxPath;
	}
	return 0;
}