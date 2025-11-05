#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define LEN 50

typedef struct {
    int roll;
    char name[LEN];
    int marks;
} Student;

void merge(Student arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    Student L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].marks <= R[j].marks)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(Student arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    FILE *fp = fopen("students.csv", "r");
    if (!fp) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Student s[MAX];
    int count = 0;
    char line[100];
    fgets(line, sizeof(line), fp); // Skip header

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%d,%[^,],%d", &s[count].roll, s[count].name, &s[count].marks);
        count++;
    }
    fclose(fp);

    mergeSort(s, 0, count - 1);

    printf("\nSorted Student Records (by Marks):\n");
    printf("----------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-10s\t%d\n", s[i].roll, s[i].name, s[i].marks);
    }

    return 0;
}
