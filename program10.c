. #include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100][10];
int top = -1;
int reg = 1;

// Push to stack
void push(char *val) {
    strcpy(stack[++top], val);
}

// Pop from stack
char* pop() {
    return stack[top--];
}

// Generate assembly from postfix
void generateCode(char postfix[]) {
    int i;
    char op1[10], op2[10], temp[10];

    for (i = 0; postfix[i] != '\0'; i++) {
        // If operand → push
        if (isalnum(postfix[i])) {
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(temp);
        }
        // If operator → generate code
        else {
            strcpy(op2, pop());
            strcpy(op1, pop());

            printf("MOV R%d, %s\n", reg, op1);

            switch (postfix[i]) {
                case '+':
                    printf("ADD R%d, %s\n", reg, op2);
                    break;
                case '-':
                    printf("SUB R%d, %s\n", reg, op2);
                    break;
                case '*':
                    printf("MUL R%d, %s\n", reg, op2);
                    break;
                case '/':
                    printf("DIV R%d, %s\n", reg, op2);
                    break;
            }

            // Store result in temp register
            sprintf(temp, "R%d", reg);
            reg++;

            push(temp);
        }
    }
}

int main() {
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    printf("\nGenerated Assembly Code:\n");
    generateCode(postfix);

    return 0;
}
