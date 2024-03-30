#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define MAX_SUBSETS 100

int set[MAX_SIZE];
int subset[MAX_SIZE];
int count = 0; 
int n; // Define 'n' for the number of elements in the set

void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

void findSubsets(int index, int sum, int target) {
    if (sum == target) {
        printSubset(subset, index);
        count++;
        return;
    }
    for (int i = index; i < n; i++) { // 'n' is the number of elements in the set
        if (sum + set[i] <= target) {
            subset[index] = set[i];
            findSubsets(i + 1, sum + set[i], target);
        }
    }
}

void sumOfSubsets(int target) {
    printf("Subsets with sum equal to %d:\n", target);
    findSubsets(0, 0, target);

    if (count == 0) {
        printf("No subsets found with the given sum.\n");
    }
}

int main() {
    int target;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n); // Read the number of elements in the set
    printf("Enter %d elements of the set:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target);
    sumOfSubsets(target);
    return 0;
}
