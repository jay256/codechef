#include<stdio.h>

int absolute(int n){
	if(n>=0)
		return n;
	else
		return (-1)*n;
}

int main(){
	int N;
	scanf("%d",&N);
	int S[N],T[N],cumS[N],cumT[N];
	int i,lead,maxLead,winner;
	for(i=0;i<N;i++){
		scanf("%d",&S[i]);
		scanf("%d",&T[i]);	
	}
	cumS[0]=S[0];
	cumT[0]=T[0];
	maxLead=absolute(cumS[0]-cumT[0]);
	if(cumS[i]>cumT[i]){
		winner=1;
	}
	else if(cumS[i]<cumT[i]){
		winner=2;
	}
	for(i=1;i<N;i++){
		cumS[i]=cumS[i-1]+S[i];
		cumT[i]=cumT[i-1]+T[i];
		lead=absolute(cumS[i]-cumT[i]);
		if((cumS[i]>cumT[i])&&(lead>maxLead)){
			maxLead=lead;
			winner=1;
		}
		else if((cumS[i]<cumT[i])&&(lead>maxLead)){
			maxLead=lead;
			winner=2;
		}		
	}
	printf("%d %d\n",winner,maxLead);
	return 0;
}
