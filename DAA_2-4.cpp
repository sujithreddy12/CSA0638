#include <stdio.h>

void findMinMaxSequence(int arr[], int size) {
    if (size == 0) {
        printf("The list is empty.\n");
        return;
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
        printf("For element %d: Minimum value so far: %d, Maximum value so far: %d\n", arr[i], min, max);
    }

    printf("\nFinal results:\n");
    printf("Minimum value in the list: %d\n", min);
    printf("Maximum value in the list: %d\n", max);
}

int main() {
    int arr[] = {7, 2, 9, 4, 1, 6, 3, 8, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    findMinMaxSequence(arr, size);

    return 0;
}
