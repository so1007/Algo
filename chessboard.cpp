//Chessboard problem
//use Divide and conquer

#include<iostream>

const int chessSize=8;

int chess[chessSize][chessSize]={0};

static int ccount=1;

using std::cout;
using std::endl;
using std::cin;


void ChessCover(int row, int col, int specR, int specC,int size){
	if(size==1) return;

	int count=ccount++;
	int ssize=size/2;

	//TOP-Left
	if( (specR<row+ssize) && (specC<col+ssize) ){
		ChessCover(row,col,specR,specC,ssize);
	}else{
		chess[row+ssize-1][col+ssize-1]=count;
		ChessCover(row,col,row+ssize-1,col+ssize-1,ssize);
	}

	//top-right
	if( (specR<row+ssize) && (specC>=col+ssize))
	{
		ChessCover(row,col+ssize,specR,specC,ssize);
	}
	else{
		chess[row+ssize-1][col+ssize]=count;
		ChessCover(row,col+ssize,row+ssize-1,col+ssize,ssize);
	}

	//bottom-left
	if( (specR>=row+ssize) &&(specC<col+ssize) ){
		ChessCover(row+ssize,col,specR,specC,ssize);
	}else{
		chess[row+ssize][col+ssize-1]=count;
		ChessCover(row+ssize,col,row+ssize,col+ssize-1,ssize);
	}

	//bottom-right
	if( (specR>=row+ssize) && (specC>=col+ssize)){
		ChessCover(row+ssize,col+ssize,specR,specC,ssize);
	}else{
		chess[row+ssize][col+ssize]=count;
		ChessCover(row+ssize,col+ssize,row+ssize,col+ssize,ssize);
	}

	count++;
}

void printChess(){
	for(int i=0;i<chessSize;++i){
		if(i==0){
			cout<<"%%"<<'\t';
			for(int k=0;k<chessSize;++k)
				cout<<k+1<<'\t';
			cout<<endl;
		}
		for(int j=0;j<chessSize;++j){
			if(j==0){if(i==0) cout<<endl;cout<<i+1<<'\t';}
			cout<<chess[i][j]<<'\t';
		}
		cout<<endl<<endl;
	}
}
void main()
{
	ChessCover(0,0,0,0,chessSize);
	printChess();

	system("Pause");
}