#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 5
int minweight(int weight[], bool visited[]){
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (visited[v] == false && weight[v] < min) {
            min = weight[v];
            min_index = v;
        }
    }
    return min_index;
}


void printMST(int parent[], int graph[V][V]){
    int totalCost = 0;
    printf("MST for the graph:\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i,
               graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total cost of MST: %d\n", totalCost);
}


void primMST(int graph[V][V]){
    int parent[V];
    int weight[V];
    bool visited[V];
    for (int i = 0; i < V; i++) {
        weight[i] = INT_MAX;
        visited[i] = false;
    }
    weight[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int u = minweight(weight, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && visited[v] == false
                && graph[u][v] < weight[v]) {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}

int main(){
    int graph[V][V] = { { 2, 5, 7, 0, 8 },
                        { 9, 3, 8, 2, 1 },
                        { 5, 7, 1, 3, 0 },
                        { 7, 9, 6, 4, 2 },
                        { 0, 8, 5, 9, 3 } };
    primMST(graph);
    return 0;
}
/*
Time Complexity: O(V^2) due to adjacency matrix, it can be reduced to O(log V) with a priority queue
Space Complexity: O(V) 
This is a greedy algorithm that adds the minimum weighted edge that connects a vertex in the existing
MST to a vertex not in it already it.
There is no chance for a cycle, edges must satisfy the condition 
This algorithm is not meant for a directional graph, as it assumes edges are bidirectional.
It may work sometimes, but generally not reccomended.(It is technically more accurate than kruskals
for directed graphs, but that is not what it was made for).
*/