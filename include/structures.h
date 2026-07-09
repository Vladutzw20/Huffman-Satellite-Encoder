/* Gilca Florian-Vladut */
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

/* Node of the satellite tree: frequency, dynamically allocated name,
 * and pointers to the left/right children. */
typedef struct Node
{
    int freq;           /* satellite frequency */
    char *label;        /* satellite name */
    struct Node *left, *right;
} Node;

/* Min-heap used to repeatedly extract the two smallest-frequency nodes
 * while building the tree. */
typedef struct
{
    Node **arr;         /* array of node pointers */
    int size, capacity; /* current size and allocated capacity */
} MinHeap;

/* Holds a satellite's label together with its binary code (path from
 * the root). Used for task 3, where we print the binary encoding of a
 * given satellite. */
typedef struct binary_node_t
{
    char *label;         /* satellite name */
    char *binary_codes;  /* binary encoding of the node */
} binary_node_t;

#endif /* STRUCTURES_H */
