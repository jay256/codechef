#include<stdio.h>
#include<stdlib.h>

/*void merge_sort(unsigned long long *arr, unsigned long long l, unsigned long long r){
	if(l<r){
		mid=(l+r)/2;
		merge_sort(arr,l,mid);
		merge_sort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

void merge(unsigned long long *arr, unsigned long long l, unsigned long long mid, unsigned long long r){
	unsigned long long size=r-l+1;
	unsigned long long buff[size];
	unsigned long long i=l;k=mid+1,j=0;
	while(i<=mid && k<=r){
		if(arr[i]<arr[k]){
			buff[j]=arr[i];
			i++;
			j++;
		}
		else if(arr[i]>arr[k]){
			buff[j]=arr[k];
			k++;
			j++;
		}
	}
	while(i<=mid){
		buff[j]=arr[i];
		i++;
		j++;
	}
	while(k<=r){
		buff[j]=arr[k];
		k++;
		j++;
	}
	k=0;
	for(j=l;j<r;j++){
		arr[j]=buff[k];
		k++;
	}
}*/

int main(){
	int T;
	scanf("%d",&T);
	while(T>0){
		unsigned long long N,K,i;
		scanf("%lld %lld", &N, &K);
		unsigned long long arr[N];
		i=0;
		while(i<N){
			scanf("%lld",&arr[i]);
			i++;
		}
		i=0;
		while(i<N){
			unsigned long long in;
			scanf("%lld",&in);
			arr[i] = (K/arr[i])*in;
			i++;
		}
		unsigned long long max=arr[0];
		for(i=1;i<N;i++){
			if(arr[i]>max)
				max=arr[i];
		}
		printf("%lld\n",max);
		T--;
	}
	return 0;
}
