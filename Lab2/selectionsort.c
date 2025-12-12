#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b){
  int c = *a;
  *a = *b;
  *b = c;
}
void selectionsort(int* arr, int n){
  for(int i = 0;i<n;++i){
    int minindex = i;
    for(int j = i+1;j<n;++j){
        if(arr[j]<arr[minindex]){
	  minindex = j;
        }
    }
    swap(&arr[minindex],&arr[i]);
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
  selectionsort(arr,b);
  for(int i=0;i<b;i++){
    printf("%d,",arr[i]);
  }
}