/* Gilca Florian-Vladut */

#include "structures.h"
#include "auxiliary.h"
#include "heap.h"
#include "tree.h"
#include "binary.h"
#include "task.h"

int main(int argc, char **argv)
{
    FILE *out = fopen(argv[--argc], "w"); /* open the output file */
    if (!out)
    {
        perror("output file");
        return 1;
    }

    FILE *in = fopen(argv[--argc], "r"); /* open the input file */
    if (!in)
    {
        perror("input file");
        fclose(out);
        return 1;
    }

    int n; /* number of satellites */
    if (fscanf(in, "%d", &n) != 1) /* read the number of satellites */
    {
        fclose(in);
        fclose(out);
        return 1;
    }

    Node **leaf = malloc(sizeof(Node *) * n); /* allocate memory for n leaf nodes */

    for (int i = 0; i < n; ++i)
    {
        int freq;
        char label[16];
        if (fscanf(in, "%d %15s", &freq, label) != 2) /* read n (frequency, label) pairs and create the nodes */
        {
            return 1;
        }
        leaf[i] = newNode(freq, label);
    }

    Node *root = buildTree(leaf, n); /* build the tree */

    if (strcmp(argv[1], "-c1") == 0) /* task 1 */
    {
        printTreeBFS(root, out); /* print the tree level by level (BFS) */
    }

    if (strcmp(argv[1], "-c2") == 0)
    {
        task2(root, in, out); /* task 2 - decode binary strings into satellite names */
    }

    int nr_nodes = 0; /* number of nodes in the tree */

    binary_node_t *node_array = create_node_array(root, &nr_nodes); /* build the array of binary codes */

    if (strcmp(argv[1], "-c3") == 0)
    {
        task3(node_array, nr_nodes, in, out); /* task 3 - print the binary encoding of given nodes */
    }

    if (strcmp(argv[1], "-c4") == 0)
    {
        task4(root, in, out); /* task 4 - find the lowest common ancestor of several nodes */
    }

    /* free the memory used for the binary codes */
    for (int i = 0; i < nr_nodes; ++i)
    {
        free(node_array[i].label);
        free(node_array[i].binary_codes);
    }
    free(node_array);

    freeTree(root); /* free the tree */
    free(leaf);      /* free the leaf array */

    fclose(in);
    fclose(out);
    return 0;
}
