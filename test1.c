#include<stdio.h>
#include<stdlib.h>

struct query{
	char c;
	long d;
};

int main(){
	long N,M;
	scanf("%ld",&N);
	scanf("%ld",&M);
	long long *array;
	array=(long long *)(malloc(sizeof(long long)*N));
	long i;
	for(i=0;i<N;i++)
		scanf("%lld",array+i);
	//for(i=0;i<N;i++)
	//	printf("%lld	",array[i]);
	//printf("\n");
	char tmp;
	scanf("%c",&tmp);
	struct query query1[M];
	for(i=0;i<M;i++){
		scanf("%c",&query1[i].c);
		scanf("%ld",&query1[i].d);
		scanf("%c",&tmp);
	}
	//for(i=0;i<M;i++){
	//	printf("%c	",query1[i].c);
	//	printf("%ld	\n",query1[i].d);
	//}
	return 0;
}
