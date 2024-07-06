#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char * setup_string(int, char**);

int main(int argc, char** argv) {

    char * expr = setup_string(argc, argv);
    printf("%s\n", expr);
    free(expr);

    return 0;
}

/**Parses the given string array, turning it into a single string without
 * any spaces. The returned string is allocated and must be freed;
 */
char * setup_string(int argc, char** argv) {

    // find out concatenated size (+1 for '\0)
    int expr_size = 1;
    for (int i = 1; i<argc; i++) {
        char * w = argv[i];
        while (*w != '\0') if (*(w++) != ' ') expr_size++;
    }

    // error checks
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

    return expr;
}
