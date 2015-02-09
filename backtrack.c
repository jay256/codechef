#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
 
typedef struct {
	int price_per_kg, likeness;
}item_t;
 
#define n_items (sizeof(item)/sizeof(item_t))
 
typedef struct {
	short bits[100]; 
	int value;
}solution;

void optimal(int weight, int idx, solution *s,item_t *item){
	solution v1, v2;
	if (idx < 0 || weight < 0) {
		memset(s->bits,0,sizeof(s->bits));
		s->value = 0;
		return;
	}
	if (weight < item[idx].price_per_kg) {
		optimal(weight, idx - 1, s,item);
		return;
        }
	optimal(weight, idx - 1, &v1,item);
	optimal(weight - item[idx].price_per_kg, idx - 1, &v2,item);
	v2.value += item[idx].likeness;
	v2.bits[idx]=1;
	*s = (v1.value >= v2.value) ? v1 : v2;
}
 
int main(void){
	int i = 0, C=0,N,w=0;
	scanf("%d %d",&C,&N);	
	solution s = {{0}, 0};
	item_t item[N];
	for(i=0;i<N;i++){	
		scanf("%d %d",&item[i].price_per_kg,&item[i].likeness);	
	}		
	optimal(C, n_items - 1, &s,item);
	for (i = 0; i < n_items; i++) {
		if (s.bits[i]==1) {
			w += item[i].price_per_kg;
		}
	}
	//printf("%d %d\n", w,s.value);
	printf("%d\n",s.value);
	return 0;
}
