#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX 100
#define INF 9999

int graph[MAX][MAX];
char nodes[MAX];
int n = 0;

// Function to find the index of a node
int getNodeIndex(char node) {
    for (int i = 0; i < n; i++)
        if (nodes[i] == node)
            return i;
    nodes[n++] = node;
    return n - 1;
}

// Read graph data from CSV
void readCSV(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            graph[i][j] = INF;

    char line[100], src, dest;
    int dist;
    fgets(line, sizeof(line), fp); // skip header

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%c,%c,%d", &src, &dest, &dist);
        int u = getNodeIndex(src);
        int v = getNodeIndex(dest);
        graph[u][v] = dist;
        graph[v][u] = dist; // undirected graph
    }

    fclose(fp);
}

// Dijkstra’s algorithm
void dijkstra(int start) {
    int dist[MAX], visited[MAX], parent[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nShortest Routes from %c:\n", nodes[start]);
    printf("------------------------------------\n");
    printf("Destination\tDistance (km)\tPath\n");
    printf("------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (i != start) {
            printf("%c\t\t%d\t\t", nodes[i], dist[i]);
            int path[MAX], count = 0, j = i;
            while (j != -1) {
                path[count++] = j;
                j = parent[j];
            }
            for (int k = count - 1; k >= 0; k--) {
                printf("%c", nodes[path[k]]);
                if (k != 0) printf(" -> ");
            }
            printf("\n");
        }
    }
    printf("------------------------------------\n");
}

int main() {
    readCSV("city_routes.csv");

    printf("Enter starting location (A-F): ");
    char startNode;
    scanf(" %c", &startNode);

    int start = getNodeIndex(startNode);
    dijkstra(start);

    return 0;
}
