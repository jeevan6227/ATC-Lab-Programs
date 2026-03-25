#include <stdio.h>

int main() {
    char str[] =
        "#include<stdio.h>\n"
        "// This is a comment\n"
        "int main(){\n"
        "   /* multi line comment */\n"
        "   printf(\"Hello World\");\n"
        "}";
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '/' && str[i+1] == '/') {
            while (str[i] != '\n') i++;
        }
        else if (str[i] == '/' && str[i+1] == '*') {
            i += 2;
            while (!(str[i] == '*' && str[i+1] == '/')) i++;
            i++;
        }
        else {
            printf("%c", str[i]);
        }
        i++;
    }
    return 0;
}
