#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX 100

// Function to find the city with minimum key value
int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// Function to print the final Minimum Spanning Tree
void printMST(int parent[], int graph[MAX][MAX], char cities[][10], int n) {
    int totalCost = 0;
    printf("\nOptimal Fiber Connections:\n");
    printf("----------------------------------------\n");
    printf("Connection\tDistance (km)\n");
    printf("----------------------------------------\n");

    for (int i = 1; i < n; i++) {
        printf("%s - %s\t\t%d\n", cities[parent[i]], cities[i], graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }

    printf("----------------------------------------\n");
    printf("Total Fiber Length Needed: %d km\n", totalCost);
    printf("----------------------------------------\n");
}

// Prim's algorithm implementation
void primMST(int graph[MAX][MAX], char cities[][10], int n) {
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, cities, n);
}

// Load adjacency matrix from CSV
int loadGraphFromCSV(char *filename, int graph[MAX][MAX], char cities[][10]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening CSV file.\n");
        return -1;
    }

    char line[256];
    int n = 0;

    fgets(line, sizeof(line), fp); // read header row
    char *token = strtok(line, ",");
    token = strtok(NULL, ",");
    while (token != NULL) {
        strcpy(cities[n++], token);
        token = strtok(NULL, ",");
    }

    rewind(fp);
    fgets(line, sizeof(line), fp);

    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        int j = 0;
        token = strtok(line, ",");
        token = strtok(NULL, ",");
        while (token != NULL) {
            graph[i][j++] = atoi(token);
            token = strtok(NULL, ",");
        }
        i++;
    }

    fclose(fp);
    return n;
}

int main() {
    int graph[MAX][MAX];
    char cities[MAX][10];
    int n = loadGraphFromCSV("city_network.csv", graph, cities);

    if (n > 0)
        primMST(graph, cities, n);
    else
        printf("No data loaded.\n");

    return 0;
}
