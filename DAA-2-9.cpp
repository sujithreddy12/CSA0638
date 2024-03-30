#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double ratio_a = ((double)(((struct Item*)a)->value) / ((struct Item*)a)->weight);
    double ratio_b = ((double)(((struct Item*)b)->value) / ((struct Item*)b)->weight);
    return (ratio_b - ratio_a); 
}

double fractionalKnapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(items[0]), compare);
    
    int currentWeight = 0; 
    double finalValue = 0.0; 
    
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        }
        else {
            int remainingWeight = capacity - currentWeight;
            finalValue += (double)items[i].value * ((double)remainingWeight / (double)items[i].weight);
            break; 
        }
    }
    
    return finalValue;
}

int main() {
    int capacity = 50; 
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}}; 
    int n = sizeof(items) / sizeof(items[0]); 
    
    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in knapsack: %.2lf\n", maxValue);
    
    return 0;
}
