/* Gilca Florian-Vladut */
#ifndef TREE_H
#define TREE_H

#include "structures.h"
#include "auxiliary.h"
#include "heap.h"

Node *newNode(int freq, const char *label);              /* allocates a new satellite node */
int countNodes(Node *root);                               /* returns the number of nodes in the tree */
void freeTree(Node *root);                                /* frees all memory used by the tree */
Node *findNodeByLabel(Node *root, const char *label);     /* finds a node by satellite name */
Node *findLCA(Node *root, Node *node1, Node *node2);       /* finds the lowest common ancestor of two nodes */
Node *buildTree(Node **leaf, int n);                       /* builds the Huffman-style tree */
void printTreeBFS(Node *root, FILE *out);                  /* prints the tree level by level (BFS) */

#endif /* TREE_H */
