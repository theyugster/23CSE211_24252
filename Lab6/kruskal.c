#include <stdio.h>
#include <stdlib.h>

#define V 5

int comparator(const void *p1, const void *p2){
    int *e1 = (int*)p1;
    int *e2 = (int*)p2;
    return e1[2] - e2[2];
}

void makeSet(int parent[], int rank[], int n){
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component){
    if (parent[component] == component){
        return component;
    }
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[]){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}


int kruskalAlgo(int numEdges, int edge[numEdges][3]){

    qsort(edge, numEdges, sizeof(edge[0]), comparator);

    int parent[V];
    int rank[V];
    makeSet(parent, rank, V);
    
    int minCost = 0;
    int edgesCount = 0;

    for (int i = 0; i < numEdges; i++) {
        int v1 = findParent(parent, edge[i][0]);
        int v2 = findParent(parent, edge[i][1]);
        int wt = edge[i][2];

        if (v1 != v2) {
            unionSet(v1, v2, parent, rank);
            minCost += wt;
            edgesCount++;
            printf("Edge included: %d - %d Weight: %d\n", edge[i][0], edge[i][1], wt);
        }
        
        if(edgesCount == V - 1) break;
    }

    return minCost;
}

int main(){
    int graph[V][V] = { { 2, 5, 7, 0, 8 },
                        { 9, 3, 8, 2, 1 },
                        { 5, 7, 1, 3, 0 },
                        { 7, 9, 6, 4, 2 },
                        { 0, 8, 5, 9, 3 } };

    int edgeList[V*V][3]; 
    int edgeCount = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) { 
            if (graph[i][j] != 0) {
                edgeList[edgeCount][0] = i;
                edgeList[edgeCount][1] = j;
                edgeList[edgeCount][2] = graph[i][j];
                edgeCount++;
            }
        }
    }

    printf("Minimum Cost of MST: %d\n", kruskalAlgo(edgeCount, edgeList));

    return 0;
}
/*
Time Complexity: O(ElogE) due to sorting the edge list
Space Complexity:O(E+V) E is number of edges, V is number of vertices
This is a greedy algorithm that always adds the minimum weighted edge to the existing MST, however
adding that edge should not create a cycle.It must be checked for each edge.
So this algorithm can be used to detect cycles in a graph as well.
This algorithm does not work for an directed graph, as it assumes each edge is bidirectional.
*/