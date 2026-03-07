/*Gîlcă_Florian_Vlăduț_313CA*/
#include "structuri.h"
#include "auxiliary.h"
#include "heap.h"
#include "tree.h"
#include "binary.h"
#include "task.h"

void task2(Node *root, FILE *in, FILE *out)
{
    int nr_binary;
    if (fscanf(in, "%d\n", &nr_binary) != 1)
    {
        return;
    }

    for (int i = 0; i < nr_binary; ++i)
    {
        char binary[MAX_LINE];
        if (!fgets(binary, MAX_LINE, in))
        {
            return;
        }
        binary[strcspn(binary, "\n")] = 0; // elimina newline
        binary_to_tree(root, binary, out);
    }
}

void task3(binary_node_t *node_array, int nr_nodes, FILE *in, FILE *out)
{
    int n_labels;
    if (fscanf(in, "%d\n", &n_labels) != 1)
    {

        return;
    }

    char *label = (char *)malloc(MAX_LINE);
    for (int i = 0; i < n_labels; ++i)
    {
        if (!fgets(label, MAX_LINE, in))
        {

            return;
        }
        label[strcspn(label, "\n")] = 0; // elimina newline

        for (int j = 0; j < nr_nodes; ++j)
        {
            if (strcmp(node_array[j].label, label) == 0)
            {
                fprintf(out, "%s", node_array[j].binary_codes);
                break;
            }
        }
    }
    free(label);
}

void task4(Node *root, FILE *in, FILE *out)
{
    int n_labels;
    if (fscanf(in, "%d\n", &n_labels) != 1)
    {

        return;
    }

    char *label = malloc(MAX_LINE);
    Node *ancestor = NULL;
    int ok = 1;

    for (int i = 0; i < n_labels; ++i)
    {
        if (!fgets(label, MAX_LINE, in))
        {

            return;
        }
        label[strcspn(label, "\n")] = 0;

        Node *child = findNodeByLabel(root, label);
        if (!child)
        {

            return;
        }

        if (ok)
        {
            ancestor = child;
            ok = 0;
        }
        else
        {
            ancestor = findLCA(root, ancestor, child);
        }
    }

    fprintf(out, "%s\n", ancestor->label);

    free(label);
}



