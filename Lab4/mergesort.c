
#include<stdio.h>
#include<stdlib.h>
void merge_sorted_arrays(int arr[],int l,int m,int r){
    int left_length = m-l+1;
    int right_length = r-m;

    int temp_left[left_length];
    int temp_right[right_length];
    for(int i = 0;i<left_length;++i){
        temp_left[i] = arr[i+l];
    }
    for(int i = 0;i<right_length;++i){
        temp_right[i] = arr[m+1+i];
    }
    int i =0 ;
    int j = 0;
    for(int k=l;k<r;++k){
        if((i<left_length) && (j<right_length || temp_left[i]<temp_right[j])){
            arr[k] = temp_left[i];
            i++;
        }else{
            arr[k] = temp_right[j];
            j++;
        }
    }
}
void merge_sort_recursion(int arr[],int l, int r){
    
    if(l<r){
        int m = l+(r-l)/2;//getting middle
        merge_sort_recursion(arr,l,m);
        merge_sort_recursion(arr,m+1,r);
        merge_sorted_arrays(arr,l,m,r);
    }
}
void merge_sort(int arr[],int size){
    merge_sort_recursion(arr,0,size-1);
}
int main(){
    int arr[8] = {4,1,5,1,3,52,42,12};
    merge_sort(arr,8);
    for(int i =0;i<8;++i){
        printf("%d ",arr[i]);
    }
}

/*
Time Complexity: O(nlog(n))
Space Complexity: O(n)

This sorting algorithm works on a divide and conquer strategy, by dividing up the arrays(in this
program it is done with recursion). It then merges sorted arrays(the most recent divided array
from the recursion call stack will be merged using merge_sorted_arrays). This works on two principles
:merging sorted arrays are efficient and an array of one element is already technically sorted.

*/