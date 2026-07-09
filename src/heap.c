/* Gilca Florian-Vladut */
#include "structures.h"
#include "auxiliary.h"
#include "heap.h"

MinHeap *createMinHeap(int capacity)
{
    MinHeap *heap = malloc(sizeof(*heap)); /* allocate memory for the heap */
    if (!heap)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    heap->arr = malloc(sizeof(Node *) * capacity); /* allocate memory for the node array */
    if (!heap->arr)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(heap);
        exit(EXIT_FAILURE);
    }
    heap->size = 0;         /* heap starts empty */
    heap->capacity = capacity;
    return heap;
}

void minHeapify(MinHeap *heap, int index)
{
    int smallest = index; /* index of the smallest node */
    int left = 2 * index + 1;  /* left child */
    int right = 2 * index + 2; /* right child */

    if (left < heap->size && compare_nodes(heap->arr[left], heap->arr[smallest]))
        smallest = left; /* compare left child with current smallest */
    if (right < heap->size && compare_nodes(heap->arr[right], heap->arr[smallest]))
        smallest = right; /* compare right child with current smallest */

    if (smallest != index)
    {
        swap(&heap->arr[index], &heap->arr[smallest]);
        minHeapify(heap, smallest); /* recurse to keep the heap property */
    }
}

void insertHeap(MinHeap *heap, Node *node)
{
    if (heap->size == heap->capacity)
    {
        fprintf(stderr, "Heap full\n");
        exit(1);
    } /* check if the heap is full */

    int i = heap->size++;
    heap->arr[i] = node; /* add the node to the array */

    /* bubble the node up to its correct position */
    while (i && compare_nodes(heap->arr[i], heap->arr[(i - 1) / 2]))
    {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node *extractMin(MinHeap *heap)
{
    if (!heap->size)
        return NULL;
    Node *root = heap->arr[0]; /* the minimum is the heap's root */
    heap->arr[0] = heap->arr[--heap->size];
    minHeapify(heap, 0);
    return root; /* return the extracted root */
}
