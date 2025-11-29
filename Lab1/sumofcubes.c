#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    printf("Sum:%d\n",(n*(n+1)/2)*(n*(n+1)/2));
}
/*
The formula for the sum of the first n natural cubes is the square of the sum of the 
first n natural numbers
Space Complexity: O(c) constant space becuase constant number of variables
Time Complexity O(c) constant time beacuse the formulaic calcuation time doesn't
scale with input.
*/