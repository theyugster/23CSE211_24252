#include<stdio.h>
int sumOfSquares(int n){
    return n*(n+1)*(2*n+1)/6;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("Sum:%d\n",sumOfSquares(n));
}
/*
Space Complexity O(c) constant space
Time Complexity O(c) constant time
*/