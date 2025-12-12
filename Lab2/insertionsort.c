#include<stdio.h>
#include<stdlib.h>
void insertionsort(int* arr, int n){
  for(int i = 1;i<n;++i){
    int key = arr[i];
    int j = i-1;
    while(j>0 && arr[j]>=key){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
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
  insertionsort(arr,b);
  for(int i=0;i<b;i++){
    printf("%d,",arr[i]);
  }
}