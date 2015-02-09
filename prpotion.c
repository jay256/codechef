#include<stdio.h>

void swap(unsigned long *a, unsigned long b){
	unsigned long long temp;
	temp=*a;
	*a=b;
	b=temp;
}

int findmax(unsigned long *a, int n){
	unsigned long max=a[0];
	int i;
	for(i=0;i<n;i++){
		if(max<a[i]){
			swap(&max,a[i]);
		}
	}
	return max;
}

unsigned long findindex(unsigned long *a, int n){
	unsigned long index=0,max=a[0];
	int i;
	for(i=0;i<n;i++){
		if(max<a[i]){
			swap(&max,a[i]);
			index=i;
		}
	}
	return index;
}

void half(unsigned long *a, int n){
	int i;	
	for(i=0;i<n;i++){
		a[i]=a[i]/2;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T>0){
		int R,G,B,M;
		scanf("%d",&R);
		scanf("%d",&G);
		scanf("%d",&B);
		scanf("%d",&M);
		unsigned long r[R],g[G],b[B];
		int i,index;
		unsigned long max[2],maxAll;
		for(i=0;i<R;i++)
			scanf("%ld",&r[i]);
		for(i=0;i<G;i++)
			scanf("%ld",&g[i]);
		for(i=0;i<B;i++)
			scanf("%ld",&b[i]);		
		for(i=0;i<M;i++){
			max[0]=findmax(r,R);
			max[1]=findmax(g,G);
			max[2]=findmax(b,B);
			maxAll=findmax(max,3);
			index=findindex(max,3);
			if(index==0){
				half(r,R);
			}
			else if(index==1){
				half(g,G);
			}
			else if(index==2){
				half(b,B);
			}
		}
		max[0]=findmax(r,R);
		max[1]=findmax(g,G);
		max[2]=findmax(b,B);
		maxAll=findmax(max,3);
		printf("%ld\n",maxAll);	
		T--;
	}
	return 0;
}
