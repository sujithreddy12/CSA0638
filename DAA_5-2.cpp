#include <stdio.h>

void generate_factors(int n, int start, int cur_factor) {
    if (cur_factor > n) {
        return;
    }
    if (n % cur_factor == 0) {
        printf("%d ", cur_factor);
        generate_factors(n, start, n / cur_factor);
    }
    else {
        generate_factors(n, start, cur_factor + 1);
    }
}

void print_factors(int n) {
    printf("Factors of %d: ", n);
    generate_factors(n, 1, 1);
    printf("\n");
}

int main() {
    int n;

    // Read input
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Print the factors
    print_factors(n);

    return 0;
}