#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000000000

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    //printf("jsdjbh\n");
    int N;
    long long index;
    scanf("%d",&N);
    int *arr=(int *)malloc(sizeof(int)*MAX);
    //memset(arr,0,sizeof(int)*MAX);
    //printf("jsdjbh\n");
    int j=N;
    while(j>0){
        scanf("%lld",&index);
        arr[index-1]+=1;
        j--;
    }
    long long i,max=arr[0],max_index;
    for(i=0;i<MAX;i++){
        if(arr[i]>max){
            max=arr[i];
            max_index=i;
        }
    }
    printf("%lld\n",max_index+1);
    return 0;
}
