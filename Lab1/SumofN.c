#include<stdio.h>
int sumN(int n){
    return n*(n+1)/2;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("Sum:%d\n",sumN(n));
}
/*

The sum of the first n natural numbers is given by n*(n+1)/2
Space Complexity:O(c)constant space because constant number of variables.
Time Complexity: O(c)constant time because the formulaic calculation doesn't scale with 
input
*/