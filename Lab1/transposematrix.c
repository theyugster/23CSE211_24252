#include<stdio.h>

int main(){
    int matrix[3][3];
    int res[3][3];
    printf("Enter matrix elements\n");
    for(int i = 0;i<3;++i){
        for(int j = 0;j<3;++j){
            scanf("%d",&matrix[i][j]);
        }
    }
    for(int i = 0;i<3;++i){
        for(int j = 0;j<3;++j){
            res[i][j]=matrix[j][i];
            printf("%d\t",res[i][j]);
        }
        printf("\n");
    }
}
/*
Time Complexity:O(c) constant time
Space Complexity:O(c) constant space
*/