#include<stdio.h>

void fib(int n){
    int prev = 0;
    int curr = 1;
    for(int i = 0;i<n;++i){
        printf("%d\n",curr);
        int temp = curr;
        curr+=prev;
        prev = temp;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    fib(n);
}
/*
Time Complexity:O(n) Linear time
Space Complexity:O(c) constant space
*/