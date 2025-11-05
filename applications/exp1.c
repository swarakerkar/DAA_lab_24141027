#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define LEN 50

typedef struct {
    char name[LEN];
    char number[LEN];
    char date[LEN];
    int duration;
} CallLog;

int binarySearch(CallLog logs[], int n, char key[]) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(logs[mid].name, key);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    FILE *fp = fopen("call_log.csv", "r");
    if (!fp) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    CallLog logs[MAX];
    char line[150];
    int count = 0;

    fgets(line, sizeof(line), fp); // Skip header

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%[^,],%[^,],%d",
               logs[count].name,
               logs[count].number,
               logs[count].date,
               &logs[count].duration);
        count++;
    }
    fclose(fp);

    char key[LEN];
    printf("Enter the contact name to search: ");
    scanf("%s", key);

    int index = binarySearch(logs, count, key);

    if (index != -1) {
        printf("\nContact Found:\n");
        printf("----------------------------\n");
        printf("Name     : %s\n", logs[index].name);
        printf("Number   : %s\n", logs[index].number);
        printf("Date     : %s\n", logs[index].date);
        printf("Duration : %d seconds\n", logs[index].duration);
    } else {
        printf("\nContact not found in call log.\n");
    }

    return 0;
}
