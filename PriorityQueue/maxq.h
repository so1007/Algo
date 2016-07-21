#ifndef _MAXQ_H
#define  _MAXQ_H

class MaxQueue{
public:
	int N;
	int q[30];
	int capacity;
	void sink(int k){
		while(2*k<=N){
			int j=2*k;
			if(q[j]<q[j+1]) ++j;
			if(q[k]<q[j]) exch(k,j);
			else break;
			k=j;
		}
	}
	void swim(int k){
		while(k>1){
			int j=k/2;
			if(q[j]<q[k]) exch(j,k);
			else break;
			k=j;
		}
	}
	void exch(int i, int j){
		int temp=q[i];
		q[i]=q[j];
		q[j]=temp;
	}
public:
	MaxQueue(int n=30):N(0),capacity(n){
		
	}
	~MaxQueue()
	{
		N=0;
	}
	int GetMax(){
		if(IsEmpty()) return 0;
		return q[1];
	}
	void DeleteMax(){
		if(~IsEmpty()){
			exch(1,N);
			q[N--]=0;
			sink(1);
		}
	}
	void Insert(int k){
		if(N<capacity){
			q[++N]=k;
			swim(N);
		}
	}
	int IsEmpty(){
		return (N==0);
	}

}


#endif