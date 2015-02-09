#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int T;
	scanf("%d",&T);
	int result,len,i,j;	
	char *str=malloc(100000*sizeof(char));	
	while(T>0){
		result=0;
		scanf("%s[^\n]",str);
		len = strlen(str);
		for(i=0;i<len;i++){
			if(str[i]!=0){
				for(j=i+1;j<len;j++){
					if(str[i]==str[j] && str[j]!=0)
						str[j]=0;
				}
				result++;
			}
		}
		printf("%d\n",result);
		T--;
	}
	return 0;
}

