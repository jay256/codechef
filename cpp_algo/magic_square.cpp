#include<iostream>
#include<iomanip>
#define SIZE 20

using namespace std;

void magic(int n){
	int square[SIZE][SIZE],j,k,l;
	if(!n%2)
		cout << "n is even" << endl;
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				square[i][j]=0;
		}	
		square[0][(n-1)/2]=1;
		int j=(n-1)/2,k,l,i=0;
		//i=j;
		for(int key=2; key<=n*n; key++){
			k = (i) ? (i-1) : (n-1);
			l = (j) ? (j-1) : (n-1);
			if(square[k][l])
				i = (i+1)%n;
			else{
				i=k;
				j=l;
			}
			square[i][j]=key;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				cout << setw(5) << square[i][j];
			cout << endl;	
		}
	} 
}

int main(){
	magic(5);
	return 0;
}
