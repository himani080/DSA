#include <stdio.h>
#include <stdlib.h>

#define V 100
#define E 1000

int parent[V];
int rank[V];

void initialize(int vertices) {
    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int compareEdges(const void* a, const void* b) {
    int* edgeA = (int*)a;
    int* edgeB = (int*)b;
    return edgeA[2] - edgeB[2];
}

void KruskalMST(int edges[E][3], int vertices, int edgesCount) {
    int result[V-1][3];
    int e = 0;
    int i = 0;
    int totalCost = 0;

    qsort(edges, edgesCount, sizeof(edges[0]), compareEdges);

    initialize(vertices);

    while (e < vertices - 1 && i < edgesCount) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        i++;

        int setU = find(u);
        int setV = find(v);

        if (setU != setV) {
            result[e][0] = u;
            result[e][1] = v;
            result[e][2] = w;
            totalCost += w;
            e++;
            unionSets(setU, setV);
        }
    }

    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i][0], result[i][1], result[i][2]);

    printf("Total cost of the Minimum Spanning Tree: %d\n", totalCost);
}

int main() {
    int vertices, edgesCount;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edgesCount);

    int edges[E][3];
    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < edgesCount; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    KruskalMST(edges, vertices, edgesCount);

    return 0;
}
