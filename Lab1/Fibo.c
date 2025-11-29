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
Time Complexity:O(n) Linear time because of the for loop.
Space Complexity:O(c) constant space as there is a constant number of variables.
Curr holds the current fibonacci number, and prev holds the previous fibonacci number
that is used to increment curr.
A iterative loop is used to control how many times curr gets updated and printed.
*/