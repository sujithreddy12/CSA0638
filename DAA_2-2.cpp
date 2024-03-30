#include <stdio.h>

int binarySearch(int array[], int left, int right, int key) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (array[mid] == key) {
            return mid;
        } else if (array[mid] > key) {
            return binarySearch(array, left, mid - 1, key);
        } else {
            return binarySearch(array, mid + 1, right, key);
        }
    }
    return -1;
}

int main() {
    int array[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(array) / sizeof(array[0]);
    int key = 23;

    int result = binarySearch(array, 0, n - 1, key);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}
