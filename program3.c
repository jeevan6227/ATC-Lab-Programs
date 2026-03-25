#include <stdio.h>
#include <ctype.h>

int main() {
    char str[1000];
    int lines = 0, words = 0, chars = 0;
    int i = 0, inWord = 0;

    printf("Enter text:\n");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        chars++;

        // Count lines
        if (str[i] == '\n')
            lines++;

        // Count words
        if (isspace(str[i])) {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            words++;
        }

        i++;
    }

    // If input doesn't end with newline
    if (chars > 0 && str[i-1] != '\n')
        lines++;

    printf("\nLines: %d", lines);
    printf("\nWords: %d", words);
    printf("\nCharacters: %d\n", chars);

    return 0;
}


