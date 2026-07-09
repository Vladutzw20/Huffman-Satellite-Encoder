/* Gilca Florian-Vladut */
#ifndef HEAP_H
#define HEAP_H
#include "structures.h"
#include "auxiliary.h"

MinHeap *createMinHeap(int capacity);   /* creates a heap with the given capacity */
void minHeapify(MinHeap *heap, int index); /* restores the min-heap property */
void insertHeap(MinHeap *heap, Node *node); /* inserts a node into the heap */
Node *extractMin(MinHeap *heap);        /* extracts and returns the smallest node */

#endif /* HEAP_H */
