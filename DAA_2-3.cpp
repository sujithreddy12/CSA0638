#include <stdio.h>

void reverseString(char *str) {
    if (*str == '\0') {
        return;
    }
    reverseString(str + 1);
    putchar(*str);
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    printf("Reversed String: ");
    reverseString(inputString);

    return 0;
}
