#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void printArr(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
    }
	printf("\n");
}

int partitionFirst(int a[],int low,int high){
	int pivot=a[low];
	int i=low+1;
	int j=high;
	while(i<=j){
		while(i<=high&&a[i]<=pivot){
			i++;
        }
		while(a[j]>pivot){
			j--;
        }    
		if(i<j){
			swap(&a[i],&a[j]);
        }
	}
	swap(&a[low],&a[j]);
	return j;
}

void quickSortFirst(int a[],int low,int high){
	if(low<high){
		int p=partitionFirst(a,low,high);
		quickSortFirst(a,low,p-1);
		quickSortFirst(a,p+1,high);
	}
}
int partitionLast(int a[],int low,int high){
	int pivot=a[high];
	int i=low-1;
	for(int j=low;j<high;j++){
		if(a[j]<=pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return i+1;
}

void quickSortLast(int a[],int low,int high){
	if(low<high){
		int p=partitionLast(a,low,high);
		quickSortLast(a,low,p-1);
		quickSortLast(a,p+1,high);
	}
}

int partitionRandom(int a[],int low,int high){
	int r=low+rand()%(high-low+1);
	swap(&a[r],&a[high]);
	return partitionLast(a,low,high);
}

void quickSortRandom(int a[],int low,int high){
	if(low<high){
		int p=partitionRandom(a,low,high);
		quickSortRandom(a,low,p-1);
		quickSortRandom(a,p+1,high);
	}
}

int main(){
	int a[]={10,11,23,44,8,15,3,9,12,45,56,45,45};
	int n=sizeof(a)/sizeof(a[0]);
	srand(time(0));
	int a1[n],a2[n],a3[n];
	for(int i=0;i<n;i++){
		a1[i]=a[i];
		a2[i]=a[i];
		a3[i]=a[i];
	}
	quickSortFirst(a1,0,n-1);
	quickSortLast(a2,0,n-1);
	quickSortRandom(a3,0,n-1);
	printArr(a1,n);
	printArr(a2,n);
	printArr(a3,n);
	return 0;
}
/*
The above code is quick sort implemented with 3 different pivots, one is random, one is last
and one is first. 
Time Complexity:O(nlogn) on average for all implementations. Worst is case is O(n^2) except for
random pivoting, it has a worst case of O(nlog(n))
Space Complexity: O(log(n)) on average for all implementations. Worst case is O(n) except for random
pivoting which has a worst case of O(log(n))
The reason random is usually better because pivoting is unpredictable so no pattern is bad for it.
Other than that there is no difference between this and normal quicksort.
*/