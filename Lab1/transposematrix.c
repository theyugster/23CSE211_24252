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
2 nested for loops get the input
The other 2 nested for loops are responsible for transposing(A(transpose)ij=Aji).
Time Complexity:O(c) constant time because the time taken to transpose a 3x3 matrix doesn't
depend on the elements of the matrix itself.
Space Complexity:O(c) constant space because it's always a 3x3 matrix, and the elements of
the matrix have no effect on transposing.
*/