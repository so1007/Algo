#include <iostream>
using namespace std;

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

void print(int arr[], int len){
	for(int i=0;i<len;++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main(){
	int array[50];
	int length;
	while(cin>>length&&length!=EOF){
		for(int i=0;i<length;++i)
			cin>>array[i];
		//BubbleSort(array,length);
		//InsertSort(array,length);
		QSort(array,0,length-1);
		print(array,length);
	}
	
	system("pause");
	return 0;
}
