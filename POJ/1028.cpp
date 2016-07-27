#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main(){
	stack<string> backward,forward;
	string cur="http://www.acm.org/";
	string command;
	string url;
	int flag=0;
	while(cin>>command&&command!="QUIT"){
		if(flag==1) cout<<endl;
		if(command=="VISIT"){
			cin>>url;
			backward.push(cur);
			cur=url;
			while(!forward.empty()) forward.pop();
			cout<<url;
		}
		else if(command=="BACK"){
			if(backward.empty()){
				cout<<"Ignored";
				continue;
			}
			forward.push(cur);
			cur=backward.top();
			cout<<cur;
			backward.pop();
		}
		else if(command=="FORWARD"){
			if(forward.empty()){
				cout<<"Ignored";
				continue;
			}
			backward.push(cur);
			cur=forward.top();
			cout<<cur;
			forward.pop();
		}
		flag=1;
	}

	return 0;
}