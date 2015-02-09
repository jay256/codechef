#include<stdio.h>
#define MOD 1000000007

unsigned long long longpow(unsigned long base, unsigned long index){
	unsigned long count=0;
	unsigned long long result=1;
	for(count=0;count<index;count++){
		result = (result*base)%MOD;
	}
	return result;
}

unsigned long long min(unsigned long long a, unsigned long long b){
	return (a<b?a:b);
}

int main(){
	int T;
	scanf("%d",&T);
	int N;
	scanf("%d",&N);
	unsigned long A[N];
	int i,j;	
	for(i=0;i<N;i++){
		scanf("%ld",&A[i]);
	}
	unsigned long long power[N][N];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==j)
				continue;
			if(A[i]==1)
				power[i][j]=1;	
			else 
				power[i][j]=longpow(A[i],A[j]);
		}
	}
	unsigned long long sim[N][N];
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			sim[i][j]=min(power[i][j],power[j][i]);
		}
	}
	unsigned long long minmax=MOD;
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			if(i==j || sim[i][j]==1)
				continue;
			if(sim[i][j]<minmax)
				minmax=sim[i][j];
		}
	}
	printf("%lld\n",minmax);
	return 0;
}
