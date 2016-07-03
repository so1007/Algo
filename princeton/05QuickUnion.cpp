#include<iostream>
#include<string>
using namespace std;

class QuickUnion
{
private:
	int* id;	//forest
	int* sz;	//size of trees
	int length;	//length of array, useless here

	// find root of node p
	int root(int p){
		while(p!=id[p]){
			id[p]=id[id[p]];	//connect node p to its grandparent, 
								//shorten the depth of the trees
			p=id[p];
		}
		return p;
	}

public:
	QuickUnion(){
		id=nullptr;
		sz=nullptr;
		length=0;
	}
	QuickUnion(int N){
		id = new int[N];
		sz = new int[N];
		length=N;
		for(int i=0;i<N;++i){
			id[i]=i;
			sz[i]=1;
		}
	}
	~QuickUnion()
	{
		if(id!=nullptr){
			delete[] id;
			delete[] sz;
		}
		id=nullptr;
	}
	
	//Union operator on node p and q
	void Union(int p, int q){
		int pt=root(p);
		int pq=root(q);
		if(pt!=pq){
			// connect according to size of trees
			if(sz[pt]<sz[pq]){
				id[pt]=pq;
				sz[pq]+=sz[pt];
			}
			else{
				id[pq]=pt;
				sz[pt]+=sz[pq];
			}
		}
	}

	// return whether is connected of nodes p and q
	bool IsConnect(int p, int q){
		int pt=root(p);
		int pq=root(q);
		if(pt!=pq) return false;
		else return true;
	}
};

int main(){
	cout<<"Enter Size of set (N):";
	int n;
	cin>>n;
	QuickUnion set(n);
	string s="1.Union\n2.IsConnected\n3.Exit\nChoose one command:";
	string s1="Enter two numbers:";
	cout<<s;
	int choose;
	while(cin>>choose&&choose!=3){
		if(choose==1){
			cout<<s1;
			int p,q;
			cin>>p>>q;
			set.Union(p,q);
		}
		if(choose==2){
			cout<<s1;
			int p,q;
			cin>>p>>q;
			if (set.IsConnect(p,q))
			{
				cout<<p<<" and "<<q<<" are connected.\n";
			}
			else{
				cout<<p<<" and "<<q<<" are not connected.\n";
			}
		}
		cout<<"\n"<<s;
	}

	system("pause");
	return 0;
}
