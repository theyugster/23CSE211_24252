#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int r){
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}


int kthSmallest(int arr[], int l, int r, int k){
    if (k > 0 && k <= r - l + 1) {
        int index = partition(arr, l, r);
        if (index - l == k - 1)
            return arr[index];
        if (index - l > k - 1) 
            return kthSmallest(arr, l, index - 1, k);
        return kthSmallest(arr, index + 1, r, 
                            k - index + l - 1);
    }
    return INT_MAX;
}
int main() {
    int arr[] = {10,11,23,44,8,15,3,9,12,45,56,45,45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    printf("Kth smallest element is: %d\n", 
           kthSmallest(arr, 0, n - 1, k));
    return 0;
}
/*
Time Complexity: O(n) with worst case being O(n^2)
Space Complexity: O(log(n))due to the recursion stack. If not managed properly it can become O(n)
Iterative  methods will result in a space complexity of O(1)
The quick select algorithm is a selection algorithm based off quicksort, where it uses pivots to 
partition the array, but it only partitions towards the one containing the kth smallest element, unlike
quick sort which will partition for both sides.(As in both parts are usually partitioned again in
quick sort, but this doesn't happen in quickselect).
*/