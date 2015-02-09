#include<stdio.h>
#include<stdlib.h>

void merge_sort(int *A, int left, int right){
	if(left<right){
		int mid=(left+right)/2;
		merge_sort(arr,left,mid);
		merge_sort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}



int main(){
	int N,X,Y;
	scanf("%d %d %d",&N,&X,&Y);
	int AB[2*N];
	int i;	
	for(i=0;i<2N;i++){
		scanf("%d",&AB[i]);
	}
	int maxtip=0;
	merge_sort(AB,0,2*N-1);
	printf("%d\n",maxtip);
	return 0;
}
