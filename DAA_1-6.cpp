#include <stdio.h>
int isPrime(int n, int divisor)
{
    if (n <= 1)
        return 0;
    else if (divisor == 1)
        return 1;
    else
    {
        if (n % divisor == 0)
            return 0;
        else
            return isPrime(n, divisor - 1);
    }
}

int main()
{
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    if (isPrime(number, number / 2) == 1)
        printf("%d is a prime number.\n", number);
    else
        printf("%d is not a prime number.\n", number);

    return 0;
}
