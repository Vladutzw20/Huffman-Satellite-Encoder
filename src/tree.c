/* Gilca Florian-Vladut */
#include "structures.h"
#include "auxiliary.h"
#include "heap.h"
#include "tree.h"

Node *newNode(int freq, const char *label)
{
    Node *node = (Node *)malloc(sizeof(*node)); /* allocate memory for the node */
    if (!node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    node->freq = freq; /* set frequency */

    node->label = my_strdup(label); /* set satellite name */
    if (!node->label)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(node);
        exit(EXIT_FAILURE);
    }

    node->left = node->right = NULL; /* no children yet */
    return node;
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right); /* count nodes recursively */
}

void freeTree(Node *root)
{
    if (!root)
        return;
    freeTree(root->left);  /* free the left subtree */
    freeTree(root->right); /* free the right subtree */
    free(root->label);     /* free the satellite name */
    free(root);
}

Node *findNodeByLabel(Node *root, const char *label)
{
    if (root == NULL)
        return NULL;
    if (strcmp(root->label, label) == 0)
        return root;

    Node *left_result = findNodeByLabel(root->left, label); /* search the left subtree */
    if (left_result != NULL)
        return left_result;

    return findNodeByLabel(root->right, label); /* search the right subtree */
}

Node *findLCA(Node *root, Node *node1, Node *node2)
{
    if (root == NULL)
        return NULL;
    if (root == node1 || root == node2) /* stopping condition */
        return root;

    Node *left_lca = findLCA(root->left, node1, node2);   /* search the left subtree */
    Node *right_lca = findLCA(root->right, node1, node2); /* search the right subtree */

    if (left_lca && right_lca)
        return root; /* nodes found in different subtrees -> this is the LCA */

    if (left_lca != NULL)
        return left_lca; /* found in the left subtree */
    else
        return right_lca; /* found in the right subtree (or not found at all) */
}

Node *buildTree(Node **leaf, int n)
{
    MinHeap *heap = createMinHeap(2 * n); /* create the heap with capacity 2*n */

    for (int i = 0; i < n; ++i)
        insertHeap(heap, leaf[i]); /* insert all leaf nodes into the heap */

    while (heap->size > 1) /* while more than one node remains, keep merging */
    {
        /* extract the two nodes with the smallest frequency */
        Node *left = extractMin(heap);
        Node *right = extractMin(heap);

        int sum = left->freq + right->freq; /* sum of the two frequencies */

        char *comb = malloc(strlen(left->label) + strlen(right->label) + 1); /* combined label */

        strcpy(comb, left->label);
        strcat(comb, right->label);

        Node *link = newNode(sum, comb); /* create the internal (merge) node */
        free(comb);
        link->left = left;
        link->right = right;
        insertHeap(heap, link); /* insert the merge node back into the heap */
    }

    Node *root = extractMin(heap); /* the last remaining node is the root */

    /* free the heap itself (not the tree nodes) */
    free(heap->arr);
    free(heap);

    return root; /* return the tree root */
}

void printTreeBFS(Node *root, FILE *out)
{
    if (!root)
        return;

    /* allocate a queue for breadth-first traversal */
    Node **queue = malloc(sizeof(Node *) * 1024); /* assume the tree has at most 1024 nodes */
    if (!queue)
    {
        return;
    }

    int front = 0;          /* index of the current node in the queue */
    int rear = 0;            /* position where the next node will be added */
    int nodesThisLevel = 1;  /* nodes left to process on the current level */
    int nodesNextLevel = 0;  /* nodes that will be processed on the next level */

    /* add the root to the queue */
    queue[rear++] = root;

    while (front < rear)
    {
        Node *currentNode = queue[front++];

        /* print the node's frequency and label */
        fprintf(out, "%d-%s ", currentNode->freq, currentNode->label);

        /* enqueue the left child, if any */
        if (currentNode->left)
        {
            queue[rear++] = currentNode->left;
            ++nodesNextLevel;
        }

        /* enqueue the right child, if any */
        if (currentNode->right)
        {
            queue[rear++] = currentNode->right;
            ++nodesNextLevel;
        }

        /* move to a new line once the current level is fully printed */
        if (--nodesThisLevel == 0)
        {
            fprintf(out, "\n");
            nodesThisLevel = nodesNextLevel;
            nodesNextLevel = 0;
        }
    }

    /* free the queue */
    free(queue);
}
