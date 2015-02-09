#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int N,X,Y;
	scanf("%d %d %d",&N,&X,&Y);
	int A[N],B[N];
	int i;	
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		scanf("%d",&B[i]);
	}
	int ordera=0,orderb=0,maxtip=0;
	i=0;
	int equal_index[N];
	memset(equal_index,0,sizeof(equal_index));
	while(i<N){
		if(ordera<=X && orderb<=Y){
			if(A[i]>B[i]){
				maxtip+=A[i];
				ordera++;
			}
			else if(A[i]<B[i]){
				maxtip+=B[i];
				orderb++;
			}
			else if(A[i]==B[i]){
				//int j=i;
				equal_index[i]=1;
				//printf("%d  %d\n",maxtip,equal_index[i]);
				i++;
				continue;
			}
		}
		else if(ordera<=X && orderb==Y){
			maxtip+=A[i];
			ordera++;
		}
		else if(ordera==Y && orderb<=Y){
			maxtip+=B[i];
			orderb++;
		}
		//printf("%d  %d\n",maxtip,equal_index[i]);
		i++;
	}
	for(i=0;i<N;i++){
		if(equal_index[i]==1)
			maxtip+=A[i];
	}
	printf("%d\n",maxtip);
	return 0;
}
