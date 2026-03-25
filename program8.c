#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check condition inside ()
int validCondition(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (!(isalnum(str[i]) || str[i]=='>' || str[i]=='<' || str[i]=='=')) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to check assignment like a=a+1;
int validAssignment(char *str) {
    int i = 0;

    // must end with ;
    if (str[strlen(str)-1] != ';')
        return 0;

    // simple check for '='
    int found = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '=') {
            found = 1;
            break;
        }
    }
    return found;
}

// Main parser
int main() {
    char input[100];

    printf("Enter statement:\n");
    fgets(input, sizeof(input), stdin);

    // Remove newline
    input[strcspn(input, "\n")] = '\0';

    // Check IF
    if (strncmp(input, "if(", 3) == 0) {
        char cond[50];
        int i = 3, j = 0;

        // extract condition
        while (input[i] != ')' && input[i] != '\0') {
            cond[j++] = input[i++];
        }
        cond[j] = '\0';

        if (input[i] != ')') {
            printf("Invalid Statement\n");
            return 0;
        }

        if (!validCondition(cond)) {
            printf("Invalid Statement\n");
            return 0;
        }

        printf("Valid IF Statement\n");
    }

    // Check WHILE
    else if (strncmp(input, "while(", 6) == 0) {
        printf("Valid WHILE Statement\n");
    }

    // Check assignment
    else if (validAssignment(input)) {
        printf("Valid Assignment Statement\n");
    }

    else {
        printf("Invalid Statement\n");
    }

    return 0;
}
