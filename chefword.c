#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long i,j;
double pm[26][26];

int hash(char c){
	if(c=='a')
		return 0;
	else if(c=='b')
		return 1;
	else if(c=='c')
		return 2;
	else if(c=='d')
		return 3;
	else if(c=='e')
		return 4;
	else if(c=='f')
		return 5;
	else if(c=='g')
		return 6;
	else if(c=='h')
		return 7;
	else if(c=='i')
		return 8;
	else if(c=='j')
		return 9;
	else if(c=='k')
		return 10;
	else if(c=='l')
		return 11;
	else if(c=='m')
		return 12;
	else if(c=='n')
		return 13;
	else if(c=='o')
		return 14;
	else if(c=='p')
		return 15;
	else if(c=='q')
		return 16;
	else if(c=='r')
		return 17;
	else if(c=='s')
		return 18;
	else if(c=='t')
		return 19;
	else if(c=='u')
		return 20;
	else if(c=='v')
		return 21;
	else if(c=='w')
		return 22;
	else if(c=='x')
		return 23;
	else if(c=='y')
		return 24;
	else
		return 25;		
}

double findProb(char *str, unsigned long N, unsigned long K, char **chk_str){
	if(K==0)
		return 1;
	else{	
		double res=0,tmp,p1=0,p2=0,p3=0;
		for(i=0;i<N;i++){
			if(str[0]!='\0' && chk_str[i][0]!='\0')
					p1=pm[hash(str[0])][hash(chk_str[i][0])];
			if(str[1]!='\0' && chk_str[i][1]!='\0'){
					p2=pm[hash(str[1])][hash(chk_str[i][1])];
			if(str[2]!='\0' && chk_str[i][2]!='\0'){
					p3=pm[hash(str[2])][hash(chk_str[i][2])];
			tmp=p1*p2*p3*findProb(chk_str[i],N,K-1,chk_str);
			res+=tmp;
		}	
		return res;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T>0){
		unsigned long N,K;
		scanf("%ld",&N);
		scanf("%ld",&K);
		char *str=calloc(3,sizeof(char));
		scanf("%s[^\n]",str);
		for(i=0;i<26;i++){
			for(j=0;j<26;j++){
				scanf("%lf",&pm[i][j]);
			}
		}
		char *chk_str[N];
		for(i=0;i<N;i++)
			chk_str[i]=calloc(3,sizeof(char));
		for(i=0;i<N;i++)
			scanf("%s[^\n]",chk_str[i]);
		double prob=findProb(str,N,K,chk_str);
		printf("%1.16lf\n",prob);
		T--;
	}
	return 0;
}
