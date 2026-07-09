/* Gilca Florian-Vladut */
#include "structures.h"
#include "auxiliary.h"
#include "heap.h"
#include "tree.h"
#include "binary.h"

void binary_to_tree(Node *root, const char *binary, FILE *out)
{
    Node *current = root;
    for (int i = 0; binary[i]; ++i)
    {
        if (binary[i] == '0')
            current = current->left;
        else
            current = current->right;
        if (!current)
            return;

        if (!current->left && !current->right)
        {
            fprintf(out, "%s ", current->label);
            current = root; /* start over for the next code in the string */
        }
    }
    fprintf(out, "\n");
}

binary_node_t *create_node_array(Node *root, int *out_size)
{
    if (!root)
    {
        *out_size = 0;
        return NULL;
    }

    int total_nodes = countNodes(root);
    *out_size = total_nodes;

    binary_node_t *node_array = malloc(sizeof(binary_node_t) * total_nodes);
    int index = 0;

    build_codes(root, "", node_array, &index);

    return node_array;
}

void build_codes(Node *node, char *path, binary_node_t *node_array, int *index)
{
    if (!node)
        return;

    node_array[*index].label = my_strdup(node->label);
    node_array[*index].binary_codes = my_strdup(path);
    (*index)++;

    if (node->left)
    {
        char *left_path = malloc(strlen(path) + 2);
        strcpy(left_path, path);
        strcat(left_path, "0");
        build_codes(node->left, left_path, node_array, index);
        free(left_path);
    }

    if (node->right)
    {
        char *right_path = malloc(strlen(path) + 2);
        strcpy(right_path, path);
        strcat(right_path, "1");
        build_codes(node->right, right_path, node_array, index);
        free(right_path);
    }
}
