#include<stdio.h>
#define max 100000

int main(){
	long long n,ai,curr_max;
	long long arr[max]={0};
	long long top=1;
	short bits[max]={0};
	scanf("%lld",&n);
	long long i;
	while(n>0){
		scanf("%lld",&ai);
		if(ai==0){
			if(top==1)
				continue;
			else{
				for(i=n+1;i>=0;i--){
					if(bits[i]==1){
						printf("%lld\n",arr[i]);
						break;
					}
				}
			}
		}
		else if(ai==-1){
			if(top==1)
				continue;
			else{
				arr[top-1]=0;
				bits[top-1]=0;
				top-=1;
			}
		}
		else{
			if(top==1){
				arr[top-1]=ai;
				curr_max=arr[top-1];
				bits[top-1]=1;
				top+=1;
			}
			else{
				if(ai>curr_max){
					curr_max=ai;
					bits[top]=1;
				}
				arr[top]=ai;
				top++;
			}
		}
		n--;
	}
	return 0;
}
