#include <stdio.h>
#include <string.h>

#define MAX 10

// Structure to store expressions
struct expr {
    char left[10];   // variable (a, b, etc.)
    char op1[10];    // operand1
    char op[5];      // operator
    char op2[10];    // operand2
};

int main() {
    struct expr e[MAX];
    int n, i, j;
    int optimized[MAX] = {0};

    printf("Enter number of expressions: ");
    scanf("%d", &n);

    // Input expressions
    for (i = 0; i < n; i++) {
        printf("Enter expression %d (format: a = b + c): ", i + 1);
        scanf("%s = %s %s %s", e[i].left, e[i].op1, e[i].op, e[i].op2);
    }

    printf("\n--- Optimized Expressions ---\n");

    for (i = 0; i < n; i++) {
        if (optimized[i]) continue;

        // Check for common subexpression
        for (j = i + 1; j < n; j++) {
            if (strcmp(e[i].op1, e[j].op1) == 0 &&
                strcmp(e[i].op2, e[j].op2) == 0 &&
                strcmp(e[i].op, e[j].op) == 0) {

                // Mark duplicate
                optimized[j] = 1;

                // Replace duplicate with first result
                printf("%s = %s %s %s\n", e[i].left, e[i].op1, e[i].op, e[i].op2);
                printf("%s = %s   (reused)\n", e[j].left, e[i].left);
                break;
            }
        }

        if (!optimized[i]) {
            printf("%s = %s %s %s\n", e[i].left, e[i].op1, e[i].op, e[i].op2);
        }
    }

    return 0;
}
