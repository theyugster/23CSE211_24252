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
The formula for the sum of the squares is given by n*(n+1)*(2*n+1)/6
Space Complexity O(c) constant space because there is a constant number of variables
Time Complexity O(c) constant time because the formulaic calculation doesn't scale with 
input.
*/