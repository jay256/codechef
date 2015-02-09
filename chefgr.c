#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void sort(int *a, int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i;j>0;j--){
            if(a[j-1]<a[j])
                swap(&a[j-1],&a[j]);
        }
    }
}

int sumofdiff(int *a, int n){
    int i, sum=0;
    for(i=1;i<n;i++){
        sum = sum+a[0]-a[i];
    }
    return sum;
}

int main(){
	int T;
    scanf("%d",&T);
    int N,M,i;
    while(T>0){
        scanf("%d",&N);
        scanf("%d",&M);
        int A[N];
        for(i=0;i<N;i++)
            scanf("%d",&A[i]);
        sort(A,N);
        int sum=sumofdiff(A,N);
        M=M-sum;
        if(M>=0){
            if(M%N==0)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
            printf("No\n");
        T--;
    }
	return 0;
}
