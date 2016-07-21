#include<iostream>
#include "maxq.h"

;using namespace std;
//Bubble Sort
void BubbleSort(int arr[], int len){
	for(int i=0;i<len-1;++i){
		for(int j=0;j<len-i-1;++j){
			if(arr[j+1]<arr[j]){
				int temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

//Insert Sort
void InsertSort(int arr[], int len){
	int min=0;
	for(int i=0;i<len;++i){
		min=i;
		for(int j=i+1;j<len;++j){
			if(arr[j]<arr[min]) min=j;
		}
		int temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
}

//MergeSort

void Merge(int arr[],int aux[], int low, int high){
	int mid = (low+high)/2;
	if(low>=high) return;
	Merge(arr,aux, low,mid);
	Merge(arr,aux, mid+1,high);
	
	for(int i=low;i<=high;++i) aux[i]=arr[i];
	int left=low, right=mid+1;
	for(int i=low;i<=high;++i){
		if(left>mid) arr[i]=aux[right++];
		else if(right>high) arr[i]=aux[left++];
		else if(aux[left]<=aux[right]) arr[i]=aux[left++];
		else arr[i]=aux[right++];
	}
	return;

}
void MergeSort(int arr[],int len){
	int* aux=new int[len];
	Merge(arr,aux, 0,len-1);
	delete[] aux;
}

//QuickSort
int Partition(int arr[], int low, int high){
	int temp=arr[low];
	while(low<high){
		while(high>low && arr[high]>=temp) high--;
		arr[low]=arr[high];
		while(low<high && arr[low]<=temp) low++;
		arr[high]=arr[low];
	}
	arr[low]=temp;
	return low;
}
void QuickSort(int arr[], int low, int high){
	if(low>=high) return;
	int pivotal=Partition(arr,low,high);
	QuickSort(arr,low,pivotal-1);
	QuickSort(arr,pivotal+1,high);
}

void print(int arr[], int len){
	for(int i=0;i<len;++i){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void main(){
	int n;
	MaxQueue q;
	while(cin>>n){
		switch (n)
		{
		case 1: int m; cin>>m; q.Insert(m); break;
		case 2: cout<<q.GetMax()<<endl; break;
		case 3: q.DeleteMax();
		default:
			break;
		}
		for(int i=1;i<=q.N;++i) cout<<q.q[i]<<" ";
		cout<<endl;
	}

	system("pause");
}