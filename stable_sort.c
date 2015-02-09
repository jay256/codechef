#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int N;
	scanf("%d",&N);
	char *str[N];
	int i,j;	
	for(i=0;i<N;i++){
		str[i]=(char *)malloc(10000);
	}
	for(i=0;i<N;i++){
		scanf("%s[^\n]",str[i]);
	}
	//printf("HELLO\n");
	char *tmp=(char *)malloc(10000);
	/*for(i=0;i<N-1;i++){
		for(j=0;j<N-i-1;j++){
			if(strlen(str[j])>strlen(str[j+1])){
				tmp=str[j];
				str[j]=str[j+1];
				str[j+1]=tmp;
			}
		}
	}*/
	merge_sort();
	for(i=0;i<N;i++){
		printf("%s\n",str[i]);
	}
	return 0;
}
