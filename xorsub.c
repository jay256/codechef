#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	int N,K,i;
	int arr[N];
	while(T>0){
		scanf("%d",&N);
		scanf("%d",&K);
		for(i=0;i<N;i++){
			scanf("%d",&arr[i]);
		}
		T--;
	}
	return 0;
}
