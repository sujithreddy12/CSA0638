#include <stdio.h>
#include <math.h>
int power(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    else
        return base * power(base, exponent - 1);
}
int countDigits(int number)
{
    if (number == 0)
        return 0;
    else
        return 1 + countDigits(number / 10);
}
int isArmstrong(int number, int digits)
{
    if (number == 0)
        return 0;
    else
        return pow(number % 10, digits) + isArmstrong(number / 10, digits);
}

int main()
{
    int number, digits, result;

    printf("Enter a number: ");
    scanf("%d", &number);

    digits = countDigits(number);
    result = isArmstrong(number, digits);

    if (result == number)
        printf("%d is an Armstrong number.\n", number);
    else
        printf("%d is not an Armstrong number.\n", number);

    return 0;
}
