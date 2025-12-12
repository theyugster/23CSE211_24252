#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b){
  int c = *a;
  *a = *b;
  *b = c;
}
void heapify(int* arr, int n, int i){
  int largest = i;
  int l = 2*i+1;
  int r = 2*i+2;
  if(l<n && arr[l]>arr[largest]){
    largest = l;
  }
  if(r<n && arr[r]>arr[largest]){
    largest = r;
  }
  if(largest!=i){
    swap(&arr[i],&arr[largest]);
    heapify(arr,n,largest);
  }
}
void heapsort(int* arr, int n){
  for(int i = n/2 -1;i>=0;i--){
    heapify(arr,n,i);
  }
  for(int i = n-1;i>0;i--){
    swap(&arr[0],&arr[i]);
    heapify(arr,i,0);
  }
}
int main(){
  int b;
  printf("Enter the number of no. to enter:");
  scanf("%d",&b);
  printf("Enter the numbers:");
  int* arr = (int*)malloc(b*sizeof(int));
  for(int i=0;i<b;i++){
    scanf("%d",&arr[i]);
  }
  heapsort(arr,b);
  for(int i=0;i<b;i++){
    printf("%d,",arr[i]);
  }
  free(arr);
}