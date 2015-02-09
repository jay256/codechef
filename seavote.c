#include<stdio.h>
#include<stdlib.h>

void solve(int *B, int N){
	int i,sum1=0,sum2=0;
	for(i=0;i<N;i++){
		sum1+=B[i];
		if(B[i]>0)
			sum2+=(B[i]-1);
	}
	int cmp=100;
	if(cmp<sum1 && cmp>sum2)
		printf("YES\n");
	else
		printf("NO\n");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T>0){
		int N,zcount=0;
		scanf("%d",&N);
		int *B=(int *)malloc(sizeof(int)*N);
		int i,sum=0,flag=0;
		for(i=0;i<N;i++){
			scanf("%d",&B[i]);
			if(B[i]>=101){
				flag=1;
				break;
			}
			sum+=B[i];
		}
		if(flag==1){
			printf("NO\n");
			T--;
			continue;
		}
		else if(sum==100){
			printf("YES\n");
			T--;
			continue;
		}
		else if(sum<100){
			printf("NO\n");
			T--;
			continue;
		}
		else if(sum>100){
			solve(B,N);
			T--;
			continue;
		}
	}
	return 0;
}
