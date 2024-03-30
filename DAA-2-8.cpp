#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n, int i) {
 
    if (n <= 2)
        return (n == 2);
    if (n % i == 0)
        return false;
    if (i * i > n)
        return true;

    return isPrime(n, i + 1);
}

void printPrimesInRange(int start, int end) {

    if (start > end)
        return;

    if (isPrime(start, 2))
        printf("%d ", start);

    printPrimesInRange(start + 1, end);
}

int main() {
    int start, end;

    printf("Enter the range (start end): ");
    scanf("%d %d", &start, &end);

    printf("Prime numbers in the range %d to %d are: ", start, end);
    printPrimesInRange(start, end);
    printf("\n");

    return 0;
}
