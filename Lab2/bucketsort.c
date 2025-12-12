#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int max_element(int* array, int size) {  
    int max = INT_MIN;  
    for (int i = 0; i < size; ++i)
    {
        if (array[i] > max)  
        max = array[i];  
    }
    return max;  
} 
void bucketsort(int* array, int size){  
    int max = max_element(array, size); 
    int bucket[max+1];
    for (int i = 0; i <= max; i++){  
      bucket[i] = 0;
    }
    for (int i = 0; i < size; i++){  
      bucket[array[i]]++;
    }
    int j=0;
    for (int i = 0; i <= max; i++){ 
        while (bucket[i] > 0){           
            array[j++] = i;  
            bucket[i]--;   
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
  bucketsort(arr,b);
  for(int i=0;i<b;i++){
    printf("%d,",arr[i]);
  }
  free(arr);
}