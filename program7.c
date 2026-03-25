#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for AST node
typedef struct node {
    char data;
    struct node *left, *right;
} node;

// Create new node
node* newNode(char data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Stack for nodes
node* stack[100];
int top = -1;

void push(node* n) {
    stack[++top] = n;
}

node* pop() {
    return stack[top--];
}

// Function to check operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Build AST from postfix expression
node* buildAST(char postfix[]) {
    int i = 0;
    while (postfix[i] != '\0') {
        if (isalnum(postfix[i])) {
            push(newNode(postfix[i]));
        }
        else if (isOperator(postfix[i])) {
            node* right = pop();
            node* left = pop();
            node* opNode = newNode(postfix[i]);
            opNode->left = left;
            opNode->right = right;
            push(opNode);
        }
        i++;
    }
    return pop();
}

// Print AST (sideways)
void printTree(node* root, int space) {
    if (root == NULL) return;

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%c\n", root->data);

    printTree(root->left, space);
}

// Main function
int main() {
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    node* root = buildAST(postfix);

    printf("\nAbstract Syntax Tree:\n");
    printTree(root, 0);

    return 0;
}
