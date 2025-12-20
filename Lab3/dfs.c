#include<stdio.h>
#include<stdlib.h>

int *adj;
int *visited;
int v;

void dfs(int start){
    printf("%d ", start);
    visited[start] = 1;

    for(int i = 0; i < v; ++i){
        if(adj[start * v + i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }
}

int main(){
    int start;

    printf("Enter number of vertices\n");
    scanf("%d", &v);

    adj = (int *)malloc(v * v * sizeof(int));
    visited = (int *)malloc(v * sizeof(int));

    printf("Enter adjacency matrix\n");
    for(int i = 0; i < v; ++i){
        for(int j = 0; j < v; ++j){
            scanf("%d", &adj[i * v + j]);
        }
    }

    printf("Enter starting vertex\n");
    scanf("%d", &start);

    for(int i = 0; i < v; ++i){
        visited[i] = 0;
    }

    printf("DFS traversal\n");
    dfs(start);

    free(adj);
    free(visited);
}
