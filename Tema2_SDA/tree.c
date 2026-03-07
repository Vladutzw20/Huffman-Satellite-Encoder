/*Gîlcă_Florian_Vlăduț_313CA*/
#include "structuri.h"
#include "auxiliary.h"
#include "heap.h"
#include "tree.h"


Node *newNode(int freq, const char *label)
{
    Node *node = (Node*)malloc(sizeof(*node));// alocare memorie pentru nod
    if (!node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    node->freq = freq;// initializare frecventa

    node->label = my_strdup(label);// initializare nume satelit
    if (!node->label)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(node);
        exit(EXIT_FAILURE);
    }


    node->left = node->right = NULL;// initializare copii
    return node;
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);// numaram recursiv nodurile din arbore
}

void freeTree(Node *root)
{
    if (!root)
        return;
    freeTree(root->left);// eliberam memoria ocupata de subarborele stang
    freeTree(root->right);// eliberam memoria ocupata de subarborele drept
    free(root->label);// eliberam memoria ocupata de numele satelitului
    free(root);
}

Node *findNodeByLabel(Node *root, const char *label)
{
    if (root == NULL)
        return NULL;
    if (strcmp(root->label, label) == 0)
        return root;

    Node *left_result = findNodeByLabel(root->left, label);// cautam in subarborele stang
    if (left_result != NULL)
        return left_result;

    return findNodeByLabel(root->right, label);// cautam in subarborele drept
}

Node *findLCA(Node *root, Node *node1, Node *node2)
{
    if (root == NULL)
        return NULL;
    if (root == node1 || root == node2)//conditia de oprire
        return root;

    Node *left_lca = findLCA(root->left, node1, node2);// cautam in subarborele stang
    Node *right_lca = findLCA(root->right, node1, node2);// cautam in subarborele drept

    if (left_lca && right_lca)
        return root;// daca am gasit nodurile in subarbori diferiti, returnam radacina

    if (left_lca != NULL)
        return left_lca;// daca am gasit nodurile in subarborele stang, returnam subarborele stang
    else
        return right_lca;// altfel, returnam subarborele drept
}

Node *buildTree(Node **leaf, int n)
{
    MinHeap *heap = createMinHeap(2 * n);// creem heap-ul cu dimensiunea 2*n


    for (int i = 0; i < n; ++i)
        insertHeap(heap, leaf[i]);// inseram nodurile in heap

    while (heap->size > 1)// cat timp mai sunt noduri in heap,ultimul nod va fi radacina arborelui
    {

        // Extragem cele doua noduri cu frecventa minima
        Node *left = extractMin(heap);
        Node *right = extractMin(heap);

        int sum = left->freq + right->freq;// calculam suma frecventelor

        char *comb = malloc(strlen(left->label) + strlen(right->label) + 1);//alocam pentru numele nodului de legatura

        strcpy(comb, left->label);
        strcat(comb, right->label);

        Node *link = newNode(sum, comb);// creem nodul de legatura
        free(comb);
        link->left = left;
        link->right = right;
        insertHeap(heap, link);// inseram nodul de legatura in heap
    }

    Node *root = extractMin(heap);//extragem ultimul nod

    // eliberam memoria ocupata de heap
    free(heap->arr);
    free(heap);

    return root;// returnam radacina arborelui
}


void printTreeBFS(Node *root, FILE *out)
{
    if (!root)
        return;

    // Alocăm o coadă pentru parcurgerea în lățime (BFS)
    Node **queue = malloc(sizeof(Node *) * 1024); // presupunem că arborele nu are mai mult de 1024 de noduri
    if (!queue)
    {
        return;
    }

    int front = 0;        // indexul nodului curent din coadă
    int rear = 0;         // poziția unde adăugăm următorul nod
    int nodesThisLevel = 1; // câte noduri avem de procesat pe nivelul curent
    int nodesNextLevel = 0; // câte noduri vor fi procesate pe nivelul următor

    // Adăugăm rădăcina în coadă
    queue[rear++] = root;

    while (front < rear)
    {
        Node *currentNode = queue[front++];

        // Afișăm frecvența și eticheta nodului
        fprintf(out, "%d-%s ", currentNode->freq, currentNode->label);

        // Dacă există copil stâng, îl adăugăm în coadă
        if (currentNode->left)
        {
            queue[rear++] = currentNode->left;
            ++nodesNextLevel;
        }

        // Dacă există copil drept, îl adăugăm în coadă
        if (currentNode->right)
        {
            queue[rear++] = currentNode->right;
            ++nodesNextLevel;
        }

        // Trecem la un nou rând (nivel) când am terminat de afișat toate nodurile de pe nivelul curent
        if (--nodesThisLevel == 0)
        {
            fprintf(out, "\n");
            nodesThisLevel = nodesNextLevel;
            nodesNextLevel = 0;
        }
    }

    // Eliberăm memoria alocată pentru coadă
    free(queue);
}
