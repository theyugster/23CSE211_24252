#include<stdio.h>

int factorial(int num){
    if(num==0){
        return 1;
    }
    return num*(factorial(num-1));
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",factorial(n));
}
/*
Time Complexity:O(n) linear time beacuse only one function call
Space Complexity:O(n) linear space beacuse of the recursion calling

This is done using recursion with a base case that returns 2(becuse 2! is 2).
Each time the function calls it self, it decrements num by 1, so the base case
is always reached. 
After that it will perform the multiplication, which then gives the answer.

*/
