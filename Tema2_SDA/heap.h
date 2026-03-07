/*Gîlcă_Florian_Vlăduț_313CA*/
#ifndef HEAP_H
#define HEAP_H
#include "structuri.h"
#include "auxiliary.h"

MinHeap *createMinHeap(int capacity);//Functie de creare a heap-ului
void minHeapify(MinHeap *heap, int index);//Functie de heapify=de respectare a proprietatii heap-ului
void insertHeap(MinHeap *heap, Node *node);//Functie de inserare a unui nod in heap
Node *extractMin(MinHeap *heap);//Functie de extragere a celui mai mic nod din heap=top-ul heap-ului


#endif // HEAP_H