#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

void perm_gen(int a[], int k, int n){
	if(k==n-1){
		for(int i=0;i<n;i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
	else{
		for(int i=k;i<n;i++){
			//cout << "1. " << a[i] << " " << a[k] << endl;
			int t=a[k]; a[k]=a[i]; a[i]=t;
			perm_gen(a,k+1,n);
			//cout << "2. " << a[i] << " " << a[k] << endl;
			t=a[k]; a[k]=a[i]; a[i]=t;
		}
	}
}

int main(){
	int a[]={1,2,3,4};
	perm_gen(a,0,4);
	return 0;
}
