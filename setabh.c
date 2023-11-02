#include <stdio.h>
void printSet(int set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d", set[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}
void setUnion(int set1[], int size1, int set2[], int size2, int result[], int *resultSize) {
    for (int i = 0; i < size1; i++) {
        result[*resultSize] = set1[i];
        (*resultSize)++;
    }
    for (int i = 0; i < size2; i++) {
        int found = 0;
        for (int j = 0; j < *resultSize; j++) {
            if (set2[i] == result[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[(*resultSize)++] = set2[i];
        }
    }
}
void setIntersection(int set1[], int size1, int set2[], int size2, int result[], int *resultSize) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                int alreadyInResult = 0;
                for (int k = 0; k < *resultSize; k++) {
                    if (set1[i] == result[k]) {
                        alreadyInResult = 1;
                        break;
                    }
                }
                if (!alreadyInResult) {
                    result[(*resultSize)++] = set1[i];
                }
                break;
            }
        }
    }
}
void setDifference(int set1[], int size1, int set2[], int size2, int result[], int *resultSize) {
    for (int i = 0; i < size1; i++) {
        int found = 0;
        for (int j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[(*resultSize)++] = set1[i];
        }
    }
}
int main() {
    int size1, size2;
    printf("Enter the size of Set 1: ");
    scanf("%d", &size1);
    int set1[size1];
    printf("Enter the elements of Set 1: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &set1[i]);
    }
    printf("Enter the size of Set 2: ");
    scanf("%d", &size2);
    int set2[size2];
    printf("Enter the elements of Set 2: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &set2[i]);
    }
    int result[size1 + size2];
    int resultSize = 0;
    printf("Set 1: ");
    printSet(set1, size1);
    printf("Set 2: ");
    printSet(set2, size2);
    printf("Union: ");
    setUnion(set1, size1, set2, size2, result, &resultSize);
    printSet(result, resultSize);
    resultSize = 0; // Reset result array and size for the next operation
    printf("Intersection: ");
    setIntersection(set1, size1, set2, size2, result, &resultSize);
    printSet(result, resultSize);
    resultSize = 0; // Reset result array and size for the next operation
    printf("Difference (Set1 - Set2): ");
    setDifference(set1, size1, set2, size2, result, &resultSize);
    printSet(result, resultSize);
    resultSize = 0; // Reset result array and size for the next operation
    printf("Difference (Set2 - Set1): ");
    setDifference(set2, size2, set1, size1, result, &resultSize);
    printSet(result, resultSize);
    return 0;
}
