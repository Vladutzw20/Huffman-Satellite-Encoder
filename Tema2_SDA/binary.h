/*Gîlcă_Florian_Vlăduț_313CA*/
#ifndef BINARY_H
#define BINARY_H
#include "structuri.h"
#include "auxiliary.h"
#include "heap.h"
#include "tree.h"

void binary_to_tree(Node *root, const char *binary, FILE *out);//functie care transforma un string binar in arbore
binary_node_t *create_node_array(Node *root, int *out_size);//functie care creeaza un array de noduri binare
void build_codes(Node *node, char *path, binary_node_t *node_array, int *index);
//functie care construieste codurile binare pentru fiecare nod din arbore

#endif // BINARY_H