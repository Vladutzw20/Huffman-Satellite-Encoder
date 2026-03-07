/*Gîlcă_Florian_Vlăduț_313CA*/

#include "structuri.h"
#include "auxiliary.h"
#include "heap.h"
#include "tree.h"
#include "binary.h"
#include "task.h"


int main(int argc, char **argv)
{
    FILE *out = fopen(argv[--argc], "w");//deschidem fisierul de iesire
    if (!out)
    {
        perror("output file");
        return 1;
    }

    FILE *in = fopen(argv[--argc], "r");// deschidem fisierul de intrare
    if (!in)
    {
        perror("input file");
        fclose(out);
        return 1;
    }

    int n;// numarul de sateliti
    if (fscanf(in, "%d", &n) != 1) // citim numarul de sateliti
    {
        fclose(in);
        fclose(out);
        return 1;
    }

    Node **leaf = malloc(sizeof(Node *) * n);// alocam memorie pentru n noduri

    for (int i = 0; i < n; ++i)
    {
        int freq;
        char label[16];
        if (fscanf(in, "%d %15s", &freq, label) != 2) // citim n perechi frq si label si creem nodurile specifice
        {
            return 1;
        }
        leaf[i] = newNode(freq, label);
    }

    Node *root = buildTree(leaf, n);// construim arborele programului

    if (strcmp(argv[1], "-c1") == 0)//task1
    {
        printTreeBFS(root, out);//afisam arborele in maniera BFS-cautare in latime sau afisare pe nivele
    }

    if (strcmp(argv[1], "-c2") == 0)
    {
        task2(root, in, out);//task2-parcurgere dupa codificarile binare si afisare 

    }


    int nr_nodes = 0;// numarul de noduri dupa ce am creat arborele

    binary_node_t *node_array = create_node_array(root, &nr_nodes);//creem un array pentru codificarea binara a nodurilor arborelui

    if (strcmp(argv[1], "-c3") == 0)
    {
        task3(node_array, nr_nodes, in, out);//task3-afisarea codificarii binare a nodurilor arborelui
    }

    if (strcmp(argv[1], "-c4") == 0)
    {
        task4(root, in, out);//task4-gasirea stramosului comun a mai multor noduri
    }

    //eliberam memoria alocata pentru codificarile binare ale nodurilor arborelui
    for (int i = 0; i < nr_nodes; ++i)
    {
        free(node_array[i].label);
        free(node_array[i].binary_codes);
    }
    free(node_array);


    freeTree(root);//eliberam memoria alocata pentru arbore
    free(leaf);//eliberam memoria alocata pentru nodurile arborelui

    fclose(in);
    fclose(out);
    return 0;
}
