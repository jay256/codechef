#include<stdio.h>
#include<stdlib.h>

int main(){		
	unsigned long T,X;
	unsigned long long K,i;
	scanf("%ld",&T);
	while(T>0){
		scanf("%ld",&X);
		scanf("%lld",&K);
		for(i=0;((1<<(i+1))-1)<K;i++);
		unsigned long long lvl=i;
		double num=(double)X;
		double den=(double)(1<<(lvl+1));
		double diff=(double)(num/den);
		unsigned long long node=K-((1<<(lvl))-1);
		double result=(double)((double)(2*node -1)*diff);
		printf("%1.16lf\n",result);		
		T--;
	}
	return 0;
}
