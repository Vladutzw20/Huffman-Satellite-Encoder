/* Gilca Florian-Vladut */
#ifndef AUXILIARY_H
#define AUXILIARY_H
#include "structures.h"

char *my_strdup(const char *s);                  /* allocates memory and copies a string */
int compare_nodes(const Node *a, const Node *b);  /* compares two nodes (used by the heap) */
void swap(Node **a, Node **b);                    /* swaps two node pointers */

#endif /* AUXILIARY_H */
