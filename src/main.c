#include <stdio.h>
#include <stdlib.h>

char * setup_string(int, char**);

int main(int argc, char** argv) {

    char * expr = setup_string(argc, argv);
    printf("%s\n", expr);

    return 0;
}

char * setup_string(int argc, char** argv) {

    int expr_size = 0;
    for (int i = 1; i<argc; i++) {
        char * w = argv[i];
        while (*w != '\0') if (*(w++) != ' ') expr_size++;
    }

    char * expr;
    if (!expr_size) { printf("no given expression\n"); return NULL; }
    if (!(expr = (char *) malloc(sizeof(char) * expr_size)))
                    { printf("out of memory\n");       return NULL; }
    expr[expr_size - 1] = '\0';

    // copy into new expression
    int expr_idx = 0;
    for (int i = 1; i<argc; i++) {
        char * w = argv[i];
        while (*w != '\0') {
            if (*w != ' ') expr[expr_idx++] = *w;
            w++;
        }
    }

    printf("%s\n", expr);
    return expr;
}
