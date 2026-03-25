#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i;

    printf("Enter an identifier: ");
    scanf("%s", str);

    // Rule 1: First character must be letter or _
    if (!(isalpha(str[0]) || str[0] == '_')) {
        printf("Invalid Identifier\n");
        return 0;
    }

    // Rule 2: Remaining characters must be letter, digit or _
    for (i = 1; str[i] != '\0'; i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) {
            printf("Invalid Identifier\n");
            return 0;
        }
    }

    printf("Valid Identifier\n");
    return 0;
}
