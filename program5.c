#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    char op;

    printf("Enter expression (e.g., 3 + 5): ");
    scanf("%d %c %d", &num1, &op, &num2);

    switch(op) {
        case '+':
            printf("Result = %d\n", num1 + num2);
            break;
        case '-':
            printf("Result = %d\n", num1 - num2);
            break;
        case '*':
            printf("Result = %d\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("Result = %d\n", num1 / num2);
            else
                printf("Error: Division by zero\n");
            break;
        default:
            printf("Invalid operator\n");
    }

    return 0;
}
