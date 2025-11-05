#include <stdio.h>
#include <stdlib.h>

struct Item {
    char id[10];
    float weight, profit, ratio;
};

void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *file = fopen("cargo.csv", "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Item items[50];
    int count = 0;
    char line[100];
    fgets(line, sizeof(line), file); // skip header

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%f,%f", items[count].id, &items[count].weight, &items[count].profit);
        items[count].ratio = items[count].profit / items[count].weight;
        count++;
    }
    fclose(file);

    float capacity;
    printf("Enter truck capacity (in kg): ");
    scanf("%f", &capacity);

    sortItems(items, count);

    float totalProfit = 0.0, remaining = capacity;

    printf("\nItems selected for loading:\n");
    printf("%-10s %-10s %-10s %-10s\n", "ID", "Weight", "Profit", "Fraction");

    for (int i = 0; i < count; i++) {
        if (items[i].weight <= remaining) {
            remaining -= items[i].weight;
            totalProfit += items[i].profit;
            printf("%-10s %-10.2f %-10.2f %-10.2f\n", items[i].id, items[i].weight, items[i].profit, 1.0);
        } else {
            float fraction = remaining / items[i].weight;
            totalProfit += items[i].profit * fraction;
            printf("%-10s %-10.2f %-10.2f %-10.2f\n", items[i].id, items[i].weight, items[i].profit, fraction);
            break;
        }
    }

    printf("\nMaximum Profit: %.2f\n", totalProfit);
    return 0;
}
