/*Gîlcă_Florian_Vlăduț_313CA*/
#ifndef STRUCTURI_H
#define STRUCTURI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

typedef struct Node
{
    int freq;//frecventa satelitului
    char *label;//numele satelitului
    struct Node *left, *right;
} Node; //structura pentru nodul arborelui 

typedef struct
{
    Node **arr;//vector de noduri
    int size, capacity;//dimensiunea si capacitatea heap-ului
} MinHeap;//structura pentru MinHeap

typedef struct binary_node_t
{
    char *label;//numele satelitului dupa care se face codificarea
    char *binary_codes;//codificarea binara a nodului
} binary_node_t; //structura pentru noduriel care retin codificarea binara a nodurilor arborelui original

#endif // STRUCTURI_H