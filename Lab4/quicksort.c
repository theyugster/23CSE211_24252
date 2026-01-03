#include<stdio.h>
void swap(int* x, int* y);
void quicksort(int array[],int length);
void quicksort_recursion(int array[],int l, int r);
int partition(int array[],int l, int r);

int main(){
    int a[] = {10,11,23,44,8,15,3,9,12,45,56,45,45};
    int length = sizeof(a)/sizeof(int);
    quicksort(a,length);
    for(int i = 0;i<length;++i){
        printf("%d,",a[i]);
    }
    printf("\n");
}

void swap(int* x, int* y){
    int c = *x;
    *x = *y;
    *y = c;
}
void quicksort(int array[],int length){
    quicksort_recursion(array,0,length-1);
}
void quicksort_recursion(int array[],int l,int r){
    if(l<r){
        int pivot_index = partition(array,l,r);
        quicksort_recursion(array,l,pivot_index-1);
        quicksort_recursion(array,pivot_index+1,r);
    }
}
int partition(int array[],int l,int r){
    int pivot_value = array[r];
    int i = l;
    for(int j = l;j<r;++j){
        if(array[j]<=pivot_value){
            swap(&array[i],&array[j]);
            i++;
        }
    }
    swap(&array[i],&array[r]);
    return i;
}
/*
Time Complexity: O(nlogn), worst is O(n^2)
Space Complexity:O(logn), worst is O(n)


This sorting algorithm works on a divide and conquer strategy, by selecting a pivot element 
and partitioning the array around it (in this program it is done with recursion). It then recursively 
sorts the sub-arrays on either side of the pivot. 
This works on two principles: partitioning places the pivot in its correct sorted position, 
and an array of one element is already technically sorted(reaching base cases).
*/