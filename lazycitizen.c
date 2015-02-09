#include<stdio.h>
#include<stdlib.h>

int max(int a, int b){
	return a>=b?a:b;
}

int backtrack(int S, int *size, int *value, int N){
	//printf("%d %d\n",size[N-1],value[N-1]);		
	if(N==0 || S<=0){
		return 0;
	}
	printf("%d %d\n",size[N-1],value[N-1]);		
	if(size[N-1] > S || size[N-1]==0){
		return backtrack(S,size,value,N-1);
	}
	else{
		return max(value[N-1]+backtrack(S-value[N-1],size,value,N-1),backtrack(S,size,value,N-1));		
	}
}

int main(){
	int S,N;
	scanf("%d %d",&S,&N);
	int size[N];
	int value[N];
	int i;
	for(i=0;i<N;i++){
		scanf("%d %d",&size[i],&value[i]);
	}
	int max_value=backtrack(S,size,value,N);
	printf("%d\n",max_value);
	return 0;
}
