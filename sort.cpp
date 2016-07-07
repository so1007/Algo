#include <iostream>
using namespace std;

// BubbleSort input params: len=length of array
void BubbleSort(int arr[],int len){
	for(int i=0;i<len-1;++i){
		for(int j=1;j<len-i;++j){
			if(arr[j]<arr[j-1]){
				int temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
	}
}

//InsertSort input params: len=length of array
void InsertSort(int arr[], int len){
	for(int i=1;i<len;++i){
		int temp=arr[i];
		int j;
		for(j=i-1;j>=0;--j){
			if(arr[j]>temp){
				arr[j+1]=arr[j];
			}
			else{
				break;
			}
		}
		if(j==0) arr[0]=temp;
		else arr[j+1]=temp;

	}
}

// QuickSort input params: low=0, high=length of array-1
int Partition(int arr[], int low, int high){
	int temp=arr[low];
	while(low<high){
		while(low<high && arr[high]>=temp) high--;
		arr[low]=arr[high];
		while(low<high && arr[low]<=temp) low++;
		arr[high]=arr[low];
	}
	arr[low]=temp;
	return low;
}
void QSort(int arr[],int low, int high){
	if(low>=high) return;
	int pivot=Partition(arr,low,high);
	QSort(arr,low, pivot-1);
	QSort(arr,pivot+1,high);
}

// MergeSort input len: length of array
void merge(int arr[],int aux[], int low, int mid, int high){
	for(int i=low;i<=high;++i){
		aux[i]=arr[i];
	}
	int i=low,j=mid+1;
	for(int k=low;k<=high;++k){
		if(i>mid) arr[k]=aux[j++];
		else if(j>high) arr[k]=aux[i++];
		else if(aux[i]>=aux[j]) arr[k]=aux[j++];
		else arr[k]=aux[i++];
	}
}
void MSort(int arr[], int aux[], int low, int high){
	if(low>=high) return;
	int mid=(low+high)/2;
	MSort(arr,aux,low,mid);
	MSort(arr,aux,mid+1,high);
	merge(arr,aux,low,mid,high);
}
void MergeSort(int arr[], int len){
	int* aux=new int[len];

	MSort(arr,aux,0,len-1);

	delete[] aux;
}
// print array
void print(int arr[], int len){
	for(int i=0;i<len;++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}

//test sort algorithm
int main(){
	int array[50];
	int length;
	while(cin>>length&&length!=EOF){
		for(int i=0;i<length;++i)
			cin>>array[i];
		//BubbleSort(array,length);
		//InsertSort(array,length);
		//QSort(array,0,length-1);
		MergeSort(array,length);
		print(array,length);
	}

	system("pause");
	return 0;
}
