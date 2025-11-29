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
Space Complexity:O(c)constant space
Time Complexity: O(c)constant time
*/