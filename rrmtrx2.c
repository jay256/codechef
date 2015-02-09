#include<stdio.h>
#define MOD 10000007

int main(){
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int a[n][m];
	int i,j;	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	return 0;
}
