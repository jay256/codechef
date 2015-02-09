#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "stack.h"

int newStack(stack *s,int elemSize){
	s->elemSize=elemSize;
	s->allocLength=2;
	s->logLength=1;
	s->elements=(int *)malloc(s->allocLength*sizeof(int));
}
void disposeStack(stack *s){
	free(s);
}
bool isEmpty(const stack *s){
	return (s->logLength==0);
}
int push(stack *s, int *elemAddr){
	if(s->logLength>=3*s->allocLength/4)
		s->allocLength*=2;
	s->elements[s->logLength++]=*elemAddr;
}
int pop(stack *s,int *elemAddr){
	if(s->logLength<s->allocLength/4)
		s->allocLength/=2;
	if(isEmpty(s))
		printf("Stack underflow\n");
	s->elements[s->logLength--]=*elemAddr;
}

int main(int argc,char *argv[]){
	int val;
	stack intStack;
	newStack(&intStack,sizeof(int));
	for(val=0;val<6;val++)
		push(&intStack,&val);
	while(!isEmpty(&intStack)){
		pop(&intStack,&val);
		printf("This just popped: %d\n",val);
	}
	disposeStack(&intStack);
}
