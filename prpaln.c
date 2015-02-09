#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T>0){
		char *str=malloc(100000*sizeof(char));
		scanf("%s[^\n]",str);
		long len=strlen(str);
		long head=0,tail=len-1;
		long count=0;
		while(head<tail){
			if(str[head]==str[tail]){
				head++;
				tail--;
				continue;
			}
			else if(str[head+1]==str[tail]){				
				count++;
				head++;
				continue;
			}
			else if(str[head]==str[tail-1]){
				count++;
				tail--;
				continue;
			}			
			else{
				count=2;
				break;			
			}	
		}
		if(count>1)
			printf("NO\n");
		else
			printf("YES\n");
		T--;	
	}
	return 0;
}
