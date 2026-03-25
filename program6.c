#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three numbers (for expression a + b * c): ");
    scanf("%d %d %d", &a, &b, &c);

    // Interpretation 1: (a + b) * c
    int result1 = (a + b) * c;

    // Interpretation 2: a + (b * c)
    int result2 = a + (b * c);

    printf("\nFirst interpretation (a + b) * c = %d", result1);
    printf("\nSecond interpretation a + (b * c) = %d", result2);

    if (result1 != result2)
        printf("\n\nGrammar is Ambiguous\n");
    else
        printf("\n\nGrammar is Not Ambiguous\n");

    return 0;
}
