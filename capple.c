#include<stdio.h>
#include<stdlib.h>

long deduplicate(long *arr, long size){
	long i,j,k,newsize=size;
	for (i = 0; i < newsize; i++) {
      for (j = i + 1; j < newsize;) {
         if (arr[j] == arr[i]) {
            for (k = j; k < newsize; k++) {
               arr[k] = arr[k + 1];
            }
            newsize--;
         } else
            j++;
      }
   }
  return newsize;
}

int main(){
	int T;
	scanf("%d",&T);
	long N,i,newsize;
	long *A;
	while(T>0){
		scanf("%ld",&N);
		A=malloc(N*sizeof(long));
		for(i=0;i<N;i++){
			scanf("%ld",(A+i));
		}
		newsize=deduplicate(A,N);
		printf("%ld\n",newsize);
		free(A);
		T--;
	}
	return 0;
}
