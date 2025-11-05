#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int src, dest, cost;
} Edge;

int parent[MAX];

// Find operation for union-find
int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}

// Union operation
void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

// Compare function for sorting edges by cost
int compare(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->cost - e2->cost;
}

// Load edges from CSV file
int loadEdgesFromCSV(char *filename, Edge edges[], char cities[MAX][5]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file.\n");
        return -1;
    }

    char line[256];
    fgets(line, sizeof(line), fp); // Skip header

    int edgeCount = 0;
    while (fgets(line, sizeof(line), fp)) {
        char c1[5], c2[5];
        int cost;
        sscanf(line, "%[^,],%[^,],%d", c1, c2, &cost);
        strcpy(cities[edgeCount * 2], c1);
        strcpy(cities[edgeCount * 2 + 1], c2);
        edges[edgeCount].src = c1[0] - 'A';
        edges[edgeCount].dest = c2[0] - 'A';
        edges[edgeCount].cost = cost;
        edgeCount++;
    }

    fclose(fp);
    return edgeCount;
}

// Kruskal's algorithm
void kruskalMST(Edge edges[], int V, int E, char cities[][5]) {
    Edge result[MAX];
    int e = 0, i = 0, totalCost = 0;

    qsort(edges, E, sizeof(Edge), compare);

    for (int v = 0; v < V; v++)
        parent[v] = v;

    while (e < V - 1 && i < E) {
        Edge next = edges[i++];

        int x = find(next.src);
        int y = find(next.dest);

        if (x != y) {
            result[e++] = next;
            unionSet(x, y);
            totalCost += next.cost;
        }
    }

    printf("\nOptimal Power Grid Connections:\n");
    printf("----------------------------------------\n");
    printf("Connection\tCost (Crores)\n");
    printf("----------------------------------------\n");
    for (int j = 0; j < e; j++) {
        printf("%c - %c\t\t%d\n",
               result[j].src + 'A', result[j].dest + 'A', result[j].cost);
    }
    printf("----------------------------------------\n");
    printf("Total Construction Cost: %d Crores\n", totalCost);
    printf("----------------------------------------\n");
}

int main() {
    Edge edges[MAX];
    char cities[MAX][5];
    int E = loadEdgesFromCSV("power_grid.csv", edges, cities);

    if (E <= 0) {
        printf("No edges found.\n");
        return 1;
    }

    int V = 6; // A-F (6 cities)
    kruskalMST(edges, V, E, cities);

    return 0;
}
