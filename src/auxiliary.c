/* Gilca Florian-Vladut */
#include "structures.h"
#include "auxiliary.h"

char *my_strdup(const char *s)
{
    if (!s)
        return NULL;
    size_t len = strlen(s);
    char *p = malloc(len + 1); /* allocate memory for the string */
    if (p)
        strcpy(p, s); /* copy the string */
    return p;
}

int compare_nodes(const Node *a, const Node *b)
{
    if (a->freq != b->freq)
        return a->freq < b->freq; /* compare frequencies first */
    return strcmp(a->label, b->label) < 0; /* tie-break on satellite name */
}

void swap(Node **a, Node **b)
{
    Node *temp = *a;
    *a = *b;
    *b = temp;
}
