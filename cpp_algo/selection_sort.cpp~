#include<iostream>

void selection_sort(int a[], int n){
  //Sort the array a[1:n] into nondecreasing order
  for(int i=0;i<n;i++){
    int j=i;
    for(int k=i+1;k<n;k++){
      if(a[k]<a[j])
	j=k;
    }
    int t = a[i]; a[i] = a[j]; a[j] = t;
  }
}

int main(){
  int a[]={100,38,20,65,42,34,57,92};
  int n=8;
  selection_sort(a,n);
  for(int i=0;i<n;i++){
    printf("%d-->",a[i]);
  }
  printf("\n");
  return 0;
}
