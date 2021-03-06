#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct hash_row{
	char *key;
};

struct hash_table{
	struct hash_row hrow[101];
	int elements;
};

struct hash_table *newhashtable(){
	struct hash_table *new_ht=(struct hash_table *)malloc(sizeof(struct hash_table));
	int i=0;
	new_ht->elements=0;
	for(i=0;i<101;i++){
		new_ht->hrow[i].key=(char *)malloc(sizeof(char)*16);
		new_ht->hrow[i].key=NULL;
	}
	return new_ht;
}

int dohash(char *key){
	int i=strlen(key),hash=0;
	for(i=0;i<strlen(key);i++){
		hash+=(int)key[i]*(i+1);
	}
	return (19*hash)%101;
}

void addht(struct hash_table *ht, char *query){
	char *key;
	key=query+4;
	int hash=dohash(key),i,index;
	if(ht->hrow[hash].key==NULL){
		ht->hrow[hash].key=key;
		printf("%d:%s\n",hash,ht->hrow[hash].key);
		ht->elements++;
	}
	else if(memcmp(ht->hrow[hash].key,key,strlen(key))){
		for(i=1;i<=19;i++){
			index=(hash+i*i+23*i)%101;
			if(ht->hrow[index].key==NULL){
				ht->hrow[index].key=key;
				ht->elements++;
				break;
			}
		}
	}
}

void delht(struct hash_table *ht, char *query){
	char *key;
	key=query+4;
	int hash=dohash(key),i,index;
	if(ht->hrow[hash].key==NULL){
		return;
	}
	if(!memcmp(ht->hrow[hash].key,key,strlen(key))){
		ht->hrow[hash].key=NULL;
		ht->elements--;
	}
	else if(memcmp(ht->hrow[hash].key,key,strlen(key))){
		for(i=1;i<=19;i++){
			index=(hash+i*i+23*i)%101;
			if(!memcmp(ht->hrow[index].key,key,strlen(key))){
				ht->hrow[index].key=NULL;
				ht->elements--;
				break;
			}
		}
	}
}

void display(struct hash_table *ht){
	int i;
	printf("%d\n",ht->elements);
	for(i=0;i<101;i++){
		if(ht->hrow[i].key!=NULL){
			printf("%d:%s\n",i,ht->hrow[i].key);
		}
	}
}

int main(){
	int t,n;
	scanf("%d",&t);
	char *query=(char *)malloc(sizeof(char)*20);
	while(t>0){
		scanf("%d",&n);
		struct hash_table *new_ht=newhashtable();	
		while(n>0){
			scanf("%s[^\n]",query);
			if(strstr(query,"ADD")!=NULL){
					addht(new_ht,query);
					//display(new_ht);
			}
			else if(strstr(query,"DEL")!=NULL){
				delht(new_ht,query);
			}			
			n--;
		}
		//display(new_ht);
		t--;
	}
	return 0;
}
