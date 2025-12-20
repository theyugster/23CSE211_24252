#include<stdio.h>
#include<stdlib.h>

int *adj;
int *visited;
int v;

void bfs(int start){
    int *queue;
    int front = 0, rear = 0;

    queue = (int *)malloc(v * sizeof(int));

    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear){
        int current = queue[front++];
        printf("%d ", current);

        for(int i = 0; i < v; ++i){
            if(adj[current * v + i] == 1 && visited[i] == 0){
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    free(queue);
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

    printf("BFS traversal\n");
    bfs(start);

    free(adj);
    free(visited);
}
