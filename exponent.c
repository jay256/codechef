#include<stdio.h>

unsigned long long power(int x, unsigned long long n){
	if(n==1){
		return x;
	}
	else
		return x*power(x,n-1);
}

int main(){
	int t;
	scanf("%d",&t);
	int x;
	unsigned long long n,result;
	while(t>0){
		scanf("%d %lld",&x,&n);
		if(x==0){
			printf("0\n");
			t--;
			continue;
		}
		if(x==1){
			printf("1\n");
			t--;
			continue;
		}			
		result=power(x,n);
		printf("%lld\n",result);
		t--;
	}
	return 0;
}
