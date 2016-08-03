#include<iostream>
#include<string>
using namespace std;

void showIP(char* arr){
	int h[4];
	for(int i=0;i<4;++i){
		int x=0;
		for(int j=i*8+0;j<i*8+8;++j){
			x+=(arr[j]-'0')<<(7-j%8);
		}
		h[i]=x;
	}
	cout<<h[0]<<"."<<h[1]<<"."<<h[2]<<"."<<h[3]<<endl;
}
int main(){
	int n;
	char arr[40];
	cin>>n;
	cin.get();
	for(int i=0;i<n;++i){
		cin.getline(arr,40);
		showIP(arr);
	}

}