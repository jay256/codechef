#include<stdio.h>
#include<stdlib.h>

unsigned long long fn(unsigned long long N);
unsigned long long expn(unsigned long long N);

unsigned long long modInverse(unsigned long long a, unsigned long long m){    
	unsigned long long x; 	
	a %= m;
	for(x = 1; x < m; x++){
		if((a*x) % m == 1) 
			return x;
	}
}

unsigned long long expn(unsigned long long N){
	unsigned long long i,res=1;
	for(i=1;i<=N;i++){
		res*=N;
	}
	return res;
}

unsigned long long fn(unsigned long long N){	
	if(N==1)
		return 1;
	else
		return expn(N)*fn(N-1);
}

int main(){
	int T;
	scanf("%d",&T);
	unsigned long N,Q,r;
	unsigned long long M,result=0;
	while(T>0){
		scanf("%ld",&N);
		scanf("%lld",&M);
		scanf("%ld",&Q);	
		while(Q>0){
			scanf("%ld",&r);
			result=fn(N)*modInverse(fn(r),M)*modInverse(fn(N-r),M);
			printf("%lld\n",result);
			Q--;
		}
		T--;
	}
	return 0;
}
