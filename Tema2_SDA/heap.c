/*Gîlcă_Florian_Vlăduț_313CA*/
#include "structuri.h"
#include "auxiliary.h"
#include "heap.h"


MinHeap *createMinHeap(int capacity)
{
    MinHeap *heap = malloc(sizeof(*heap));// alocare memorie pentru heap
    if (!heap)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    heap->arr = malloc(sizeof(Node *) * capacity);// alocare memorie pentru vectorul de noduri
    if (!heap->arr)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(heap);
        exit(EXIT_FAILURE);
    }
    heap->size = 0;// initializare dimensiune heap
    heap->capacity = capacity;// initializare capacitate heap
    return heap;
}

void minHeapify(MinHeap *heap, int index)
{
    int smallest = index;// indexul celui mai mic nod
    int left = 2 * index + 1; //copil stang
    int right = 2 * index + 2; //copil drept


    if (left < heap->size && compare_nodes(heap->arr[left], heap->arr[smallest]))
        smallest = left;// comparare nod stang cu cel mai mic nod
    if (right < heap->size && compare_nodes(heap->arr[right], heap->arr[smallest]))
        smallest = right;// comparare nod drept cu cel mai mic nod

    if (smallest != index)
    {
        swap(&heap->arr[index], &heap->arr[smallest]);
        minHeapify(heap, smallest);// apel recursiv pentru a respecta proprietatea heap-ului
    }
}

void insertHeap(MinHeap *heap, Node *node)
{
    if (heap->size == heap->capacity)
    {
        fprintf(stderr, "Heap full\n");
        exit(1);
    }// verificare daca heap-ul este plin

    int i = heap->size++;
    heap->arr[i] = node;// adaugare nod in vectorul de noduri


    // Plasare nod in pozitia corecta
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
    Node *root = heap->arr[0];//minimul este root-ul heap-ului
    heap->arr[0] = heap->arr[--heap->size];
    minHeapify(heap, 0);
    return root;//extragere root
}