#include<stdio.h>

long max(long a, long b){
  if(a>b)
    return a;
  else
    return b;
}

long max_len(int *a, long n){
  long i=0;
  if(n==1 && a[i]==0)
    return 0;
  if(n==1 && a[i]==1)
    return 1;
  printf("%ld\t",i);
  while(a[i]!=0 && i!=n){
    i++;
    printf("%ld\t",i);
  }
  if(i==n)
    return n;
  else
    return max(max_len(a,i),max_len(a+i,n-i));
}

int main(){
  long n;
  scanf("%ld",&n);
  int a[n];
  long i;
  for(i=0;i<n;i++)
    scanf("%d",a+i);
  long res;
  res=max_len(a,n);
  printf("%ld\n",res);
  return 0;
}