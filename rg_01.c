#include<stdio.h>
#include<string.h>

void setbestscore(int V, int E, unsigned long long **weight_matrix, unsigned long long **best_score){
	int i;
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if(i==j)
				best_score[i][j]=0;
			else{
				
			}
		}
	}
}

int main(){
	int V,E;
	scanf("%d",&V);
	scanf("%d",&E);
	unsigned long long weight_matrix[V][V];
	int i,j,u,v;
	memset(weight_matrix,0,sizeof(weight_matrix));
	for(i=0;i<V;i++){
		scanf("%d",&u);
		scanf("%d",&v);
		scanf("%lld",&weight_matrix[u][v]);
		weight_matrix[v][u]=weight_matrix[u][v];
	}

	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			printf("%lld	",weight_matrix[i][j]);
		}
		printf("\n");
	}

	unsigned long long best_score[V][V];
	memset(best_score,0,sizeof(best_score));
	setbestscore(V,E,weight_matrix,best_score);
	return 0;
}
