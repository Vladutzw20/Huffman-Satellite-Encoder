/* Gilca Florian-Vladut */
#ifndef BINARY_H
#define BINARY_H
#include "structures.h"
#include "auxiliary.h"
#include "heap.h"
#include "tree.h"

void binary_to_tree(Node *root, const char *binary, FILE *out);          /* decodes a binary string into a satellite name */
binary_node_t *create_node_array(Node *root, int *out_size);             /* builds the array of binary codes for all nodes */
void build_codes(Node *node, char *path, binary_node_t *node_array, int *index); /* recursively builds the binary code for each node */

#endif /* BINARY_H */
