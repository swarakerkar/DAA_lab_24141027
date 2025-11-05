#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Patient {
    char name[50];
    int age;
    char admission_date[15];
};

void swap(struct Patient *a, struct Patient *b) {
    struct Patient temp = *a;
    *a = *b;
    *b = temp;
}

int compareDates(char *d1, char *d2) {
    int y1, m1, day1;
    int y2, m2, day2;
    sscanf(d1, "%d-%d-%d", &y1, &m1, &day1);
    sscanf(d2, "%d-%d-%d", &y2, &m2, &day2);
    if (y1 != y2) return y1 - y2;
    if (m1 != m2) return m1 - m2;
    return day1 - day2;
}

int partition(struct Patient arr[], int low, int high) {
    char pivot[15];
    strcpy(pivot, arr[high].admission_date);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compareDates(arr[j].admission_date, pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(struct Patient arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    FILE *file = fopen("patients.csv", "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Patient patients[MAX];
    int count = 0;
    char line[100];

    fgets(line, sizeof(line), file);  // Skip header
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%d,%s", patients[count].name, &patients[count].age, patients[count].admission_date);
        count++;
    }
    fclose(file);

    quickSort(patients, 0, count - 1);

    printf("\nPatients sorted by Admission Date:\n");
    printf("%-15s %-10s %-15s\n", "Name", "Age", "Admission Date");
    for (int i = 0; i < count; i++)
        printf("%-15s %-10d %-15s\n", patients[i].name, patients[i].age, patients[i].admission_date);

    return 0;
}
