#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *str) {
    char *keywords[] = {"int", "float", "char", "if", "else", "while"};
    for (int i = 0; i < 6; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char str[100];
    printf("Enter a statement: ");
    fgets(str, sizeof(str), stdin);

    char *token = strtok(str, " \t\n");

    while (token != NULL) {
        if (isKeyword(token))
            printf("Keyword: %s\n", token);
        else if (isdigit(token[0]))
            printf("Number: %s\n", token);
        else if (strchr("+-*/=", token[0]))
            printf("Operator: %s\n", token);
        else
            printf("Identifier: %s\n", token);

        token = strtok(NULL, " \t\n");
    }
    return 0;
}

