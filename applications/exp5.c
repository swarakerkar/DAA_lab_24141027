#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to find two smallest files
void findTwoSmallest(int arr[], int n, int *min1, int *min2) {
    *min1 = *min2 = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) continue;
        if (*min1 == -1 || arr[i] < arr[*min1]) {
            *min2 = *min1;
            *min1 = i;
        } else if (*min2 == -1 || arr[i] < arr[*min2]) {
            *min2 = i;
        }
    }
}

int main() {
    FILE *fp = fopen("file_sizes.csv", "r");
    if (!fp) {
        printf("Error opening CSV file.\n");
        return 1;
    }

    char line[100], fileName[50];
    int sizes[MAX], n = 0;

    fgets(line, sizeof(line), fp); // Skip header
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%d", fileName, &sizes[n]);
        n++;
    }
    fclose(fp);

    int totalCost = 0;
    int merges = 0;

    printf("\nMerging Process (File Compression Simulation):\n");
    printf("--------------------------------------------\n");

    while (1) {
        int min1, min2;
        findTwoSmallest(sizes, n, &min1, &min2);
        if (min2 == -1) break;

        int cost = sizes[min1] + sizes[min2];
        totalCost += cost;
        merges++;

        printf("Merge %d: Files of sizes %dMB and %dMB → New file: %dMB\n",
               merges, sizes[min1], sizes[min2], cost);

        sizes[min1] = cost;
        sizes[min2] = -1;
    }

    printf("--------------------------------------------\n");
    printf("Total Merge Cost (Time): %d units\n", totalCost);
    printf("Total Merges Performed: %d\n", merges);
    printf("--------------------------------------------\n");

    printf("Optimal merge order achieved — total processing minimized.\n");

    return 0;
}
