/*Gîlcă_Florian_Vlăduț_313CA*/
#include "structuri.h"
#include "auxiliary.h"

char *my_strdup(const char *s)
{
    if (!s)
        return NULL;
    size_t len = strlen(s);
    char *p = malloc(len + 1);// alocare memorie pentru string
    if (p)
        strcpy(p, s);// copierea stringului
    return p; 
}

int compare_nodes(const Node *a, const Node *b)
{
    if (a->freq != b->freq)
        return a->freq < b->freq;//intoarcem rezultatul compararii frecventelor
    return strcmp(a->label, b->label) < 0;//intoarcem rezultatul compararii numelui satelitilor
}

void swap(Node **a, Node **b)
{
    Node *temp = *a;
    *a = *b;
    *b = temp;
}
