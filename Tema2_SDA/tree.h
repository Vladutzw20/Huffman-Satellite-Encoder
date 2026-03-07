/*Gîlcă_Florian_Vlăduț_313CA*/
#ifndef TREE_H
#define TREE_H

#include "structuri.h"
#include "auxiliary.h"
#include "heap.h"

Node *newNode(int freq, const char *label);//functie care aloca memorie pentru un nod-satelit
int countNodes(Node *root);//functie care intoarce numarul nodurile din arbore
void freeTree(Node *root);//functie care elibereaza memoria ocupata de arbore
Node *findNodeByLabel(Node *root, const char *label);//functie care cauta un nod dupa numele satelitului
Node *findLCA(Node *root, Node *node1, Node *node2);//functie care cauta the lowest common ancestor al doua noduri
Node *buildTree(Node **leaf, int n);//functie care construieste arborele nostru cu o abordare Huffman
void printTreeBFS(Node *root, FILE *out);//functie care afiseaza arborele in BFS,pe nivele


#endif // TREE_H