#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void swap(int* a, int* b){
  int c = *a;
  *a = *b;
  *b = c;
}
void bubblesort(int* arr, int n){
 int i,j;
 for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    if(arr[j]>=arr[i]){
    swap(&arr[i],&arr[j]);
   }
  }
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
  bubblesort(arr,b);
  for(int i=0;i<b;i++){
    printf("%d,",arr[i]);
  }
}