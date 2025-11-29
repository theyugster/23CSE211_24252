#include<stdio.h>

int factorial(int num){
    if(num==2){
        return 2;
    }
    return num*(factorial(num-1));
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",factorial(n));
}
/*
Time Complexity:O(n) linear time
Space Complexity:O(n) linear space
*/