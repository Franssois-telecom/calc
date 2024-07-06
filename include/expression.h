#ifndef EXPRESSION_H
#define EXPRESSION_H

typedef enum {
    ERR = -1,
    NUM = 0,
    ADD,
    SUB,
    MUL,
    DIV,
} expr_kind;

typedef struct  expr_t {
    struct expr_t * l;  // left sub-expression
    struct expr_t * r;  // right sub-expression
    expr_kind k; // expression kind
} expr_t;

/**buils the corresponding expression tree out of a given string*/
expr_t * expr_parse(char * s);

/**frees the allocated memory used to store the expression */
void expr_free(expr_t * root);

#endif
