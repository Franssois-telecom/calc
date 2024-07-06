#include <stdlib.h>
#include "expression.h"

expr_t * parse(char * s) {
    if (!s) return NULL; // TODO rm lmao
    expr_t * root = malloc(sizeof(expr_t));
    root->k = ERR;
    return root;
}

void free(expr_t * e) {
    if (!e) return;
    if (e->l) expr_free(e->l);
    if (e->r) expr_free(e->r);
    free(e);
}
