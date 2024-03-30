#include <stdio.h>
unsigned long long factorial(int num)
{
    unsigned long long fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    int number;
    unsigned long long result;

    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    if (number < 0)
    {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 1;
    }

    result = factorial(number);

    printf("Factorial of %d = %llu\n", number, result);

    return 0;
}
