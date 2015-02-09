#include<stdio.h>

long unitsofgrass;

struct villages{
	long population;
	char occupant;
};

int searchlr(struct villages *village, int n){
	int index,i;
	for(i=0;i<n;i++){
		if(village[i].occupant=='D'&&village[i].population>0){
			index=i;
			break;
		}
	}
	return index;
}

void update(struct villages *village, int n, int index){
	int d;
	for(d=1;;d++){
		if(village[index].population==0)
			break;
		else if(village[index].population>0){
			if((index-d)>=0&&village[index-d].occupant=='H'&&village[index].population>0){
				if(village[index].population>=village[index-d].population){
					village[index].population=village[index].population-village[index-d].population;
					unitsofgrass=unitsofgrass+village[index-d].population*d;
					village[index-d].population=0;				
				}
				else{
					village[index-d].population=village[index-d].population-village[index].population;
					unitsofgrass=unitsofgrass+village[index].population*d;
					village[index].population=0;
				}
			}
			if((index+d)<n&&village[index+d].occupant=='H'&&village[index].population>0){
				if(village[index].population>=village[index+d].population){
					village[index].population=village[index].population-village[index+d].population;
					unitsofgrass=unitsofgrass+village[index+d].population*d;
					village[index+d].population=0;
				}
				else{
					village[index+d].population=village[index+d].population-village[index].population;
					unitsofgrass=unitsofgrass+village[index].population*d;
					village[index].population=0;
				}
			}
		}
	}
	return;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T>0){
		unitsofgrass=0;
		int n;
		scanf("%d",&n);
		long D[n],i,countD=0;
		struct villages village[n]; 
		for(i=0;i<n;i++){
			scanf("%ld",&D[i]);
			if(D[i]>=0){
				village[i].population=D[i];
				village[i].occupant='H';
			}
			else if(D[i]<0){
				village[i].population=-D[i];
				village[i].occupant='D';
				countD++;
			}		
		}
		for(i=0;i<countD;i++){
			int index=searchlr(village,n);
			update(village,n,index);
		}
		printf("%ld\n",unitsofgrass);
		T--;
	}
	return 0;
}
