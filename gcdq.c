#include<stdio.h>
#include<stdlib.h>
     
unsigned int calgcd(unsigned int x, unsigned int y){
    unsigned int wk;
    if(x<y){ 
        wk=x;
        x=y;
        y=wk; 
    }
    while(y){
            wk = x%y;
            x=y;
            y=wk;
        }
    return x;
} 
int gcd_arr(int n, int *a){
    int i,g=a[0];
    for (i = 1; i < n; i++)
        g = calgcd(g, a[i]);
    return g;
}
     
int find_gcd(int *arr, int l, int r, int n){
    int size=n-r+l-1;
    int new_arr[size];
    int i=0,j=r,k=0;
    while(i<l-1){
        new_arr[k]=arr[i];
        k++;
        i++;
    }
    while(j<n){
        new_arr[k]=arr[j];
        k++;
        j++;
    }
        return gcd_arr(size, new_arr);
}
     
int main(){
    int T;
    scanf("%d",&T);
    while(T>0){
        int N,Q;
        scanf("%d %d",&N,&Q);
        int a[N];
        int i;
        for(i=0;i<N;i++){
            scanf("%d",&a[i]);
        }
        while(Q>0){
            int L,R;
            scanf("%d %d", &L, &R);
            int gcd=find_gcd(a,L,R,N);
            printf("%d\n",gcd);
            Q--;
        }
        T--;
    }
    return 0;
} 
