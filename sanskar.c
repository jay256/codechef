#include<stdio.h>

//int count;

void subset_sum(unsigned long long *sans_int, int N, unsigned long long div_int, short *sans_used, int index, unsigned long long sum){
	if(sans_used[index]==0){
		sans_used[index]=1;
		//printf("sanskar intensity:%lld\n",sans_int[index]);
		if(sum+sans_int[index]==div_int){
			//printf("1\n");
			//count++;
			return;
		}
		else if(index+1<N && sum+sans_int[index]<=div_int){
			//printf("2\n");
			subset_sum(sans_int,N,div_int,sans_used,index+1,sum+sans_int[index]);
		}
		if(index+1<N && sum+sans_int[index+1]<=div_int){
			//printf("3\n");
			sans_used[index]=0;
			subset_sum(sans_int,N,div_int,sans_used,index+1,sum);
		}
	}
	else{
		subset_sum(sans_int,N,div_int,sans_used,index+1,sum);
	}	
	return;
}

void check(unsigned long long *sans_int, int N, int div_int, int K){
	short sans_used[N]; 
	int i,count=0;
	for(i=0;i<N;i++){
		sans_used[i]=0;
		if(sans_int[i]==0){
			sans_used[i]=1;
		}
	}
	
	subset_sum(sans_int,N,div_int,sans_used,0,0);
	//printf("count:%d\n",count);	
	for(i=0;i<N;i++){
		if(sans_used[i]==1){
			count++;
		}
	}
	if(count==N){
		printf("yes\n");
	}
	else
		printf("1.no\n");
	return;
}

int main(){
	//count=0;
	int T;
	scanf("%d",&T);
	int N,K,i;
	unsigned long long sans_int[N];
	unsigned long long sum,div_int;
	while(T>0){
		sum=0;
		scanf("%d",&N);
		scanf("%d",&K);
		for(i=0;i<N;i++){
			scanf("%lld",&sans_int[i]);
			sum+=sans_int[i];
		}
		//printf("case:%d sum:%lld\n",T,sum);
		if(sum%K!=0){
			printf("no\n");
		}
		else{
			div_int=sum/K;
			short flag1=0,flag2=0;
			for(i=0;i<N;i++){
				if(sans_int[i]>div_int){
					flag1=1;
					break;
				}
				if(sans_int[i]!=0){
					flag2=1;			
				}
			}
			if(flag1==1){
				printf("no\n");
			}
			else if(flag2==0){
				printf("yes\n");
			}
			else if(flag1!=1 && flag2!=0){
				check(sans_int,N,div_int,K);
			}			
		}
		T--;	
	}
	return 0;
}
