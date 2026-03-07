Gîlcă Florian-Vlăduț 
313CA

                                    TEMA2-Structuri de date si algoritmi
                                                Arbori

I.Structuri.h
    În cadrul acestei biblioteci , avem definite următoarele structuri de date:
a)o structura Node pentru nodurile arborelui nostru de sateliti:un int pentru frecventa satelitului , un string alocat dinamic pentru retinerea numelui satelitului si pointeri Node* pentru copiii fiecarui nod , drept si stang.
b)o structura MinHeap pentru implementarea Minheap-ului care ne ajuta la obtineea directa a celor mai mici doua elemente din arbore
: un array pentru noduri(Node**),dimensiunea si capacitatea de stocare a heap-ului(int).
c)o structura binary_node_t care retine numele/label-ul satelitilor si codificarea lor binara-binary_codes (char*).Acesta structura este folositoare pentru task-ul 3 unde trebuie sa afisam codificarea binara a unor noduri identificand label-ul lor.
d)de asemenea , avem si un macro MAX_LINE 1024 pentru stocarea eficienta si lipsita de erori a numelor satelitilor , utila atunci cand obtinem nodurile de legatura si trebuie sa concatenam nume de dimensiune mare.

II)Auxiliary.h/Auxiliary.c
    Aceasta biblioteca contine functii ajutatoare,generale precum :
a)char *my_strdup(const char *s)=aloca memorie pentru un string si retine in el valoarea unui string constant.Returneaza string-ul obtinut.Este necesar pentru evitarea accesarilor gresite de memorie in cazul folosirii directe a unui strcpy.
b)int compare_nodes(const Node *a, const Node *b)=returneaza rezultatul compararii campurilor a doua noduri - mai inati , frecventele , in caz de egalitate intoarce rezulattul functiei strcmp pentru numele celor doi sateliti.Necesara in implementarea MinHeap-ului.
c)void swap(Node **a, Node **b)=interschimba continutul a doua noduri

III)Heap.h/Heap.c
    Aceasta biblioteca contine functii necesare pentru implementarea MinHeap-ului cum ar fi :
a)MinHeap *createMinHeap(int capacity)=functie de crearea a unui heap cu o anumita capacitate.Alocam dinamic memorie pentru heap si pentru vectorul de noduuri. Initializam dimensiunea heap-ului cu 0(heap gol), capacitatea cu prametrul primit si returnam heap-ul nostru.
b)Node *extractMin(MinHeap *heap)=functie de extragere a minimului din heap sau mai exact functie care intoarce radacina heap-ului , o scoate din heap(pop), apoi rearanjeaza heap-ul in forma canonica .
c)void insertHeap(MinHeap *heap, Node *node)= functie de inserare a unui nod in heap pe pozitia corecta . Aceasta functie este necesara pentru construirea arborelui Huffman cand adaugam nodul de legatura format din cele mai mici 2 elemente din heap.
d)void minHeapify(MinHeap *heap, int index)-functiile de heapify sunt functii care ajuta la mentinerea si construirea heap-ului.
Compară nodul de la poziția index cu copiii săi stâng (2 * index + 1) și drept (2 * index + 2).Găsește cel mai mic dintre ele folosind funcția compare_nodes.Dacă unul dintre copii are o valoare mai mică decât nodul curent, se face swap și se apelează recursiv minHeapify pe poziția nouă.Această funcție este folosită pentru:
-corectarea unui heap după ce un element a fost mutat sau șters;
-asigurarea faptului că subarborele pornind de la index respectă regula unui min-heap: fiecare nod trebuie să fie mai mic sau egal decât copiii săi;

IV)Tree.h/Tree.c
a)Node *newNode(int freq, const char *label)=aloca memorie pentru un nod din arbore si pentru numele acestuia.Le atribuie campurilor frecventa(freq) si nume(label) valori citite din fisierul de intrare . Returneaza nodul obtinut.
b)int countNodes(Node *root)=functie care intaorce numarul de noduri dintr-un arbore , numara nodurile din subarborele stang si din cel drept pornind de la nodul radacina.
c)void freeTree(Node *root)=functie de eliberare a memoriei pentru arborele nostru. Elibereaza memoria alocata pentru noduri si pentru numele satelitilor :subarborii stanga si dreapta si apoi radacina .
d)Node *findNodeByLabel(Node *root, const char *label)=functie care cauta un nod in arborele nostru dupa un label dat si intoarce nodul care are acest label.Foloseste o implementare recursiva . Verifica radacina fiecarui subarbore , dupa care cauta in cei doi subarbori:stanga si dreapta.
e)Node *findLCA(Node *root, Node *node1, Node *node2)=functie care intoarce stramosul comun (lowest common ancestor) a doua noduri. Aceasta functie e esentiala pentru indeplinirea task-ului 4 cand trebuie sa aflam stramosul comun a mai multe noduri. Folosim un fel de implementare ca pentru aflarea cmmdc-ului a mai multe numere.
f)Node *buildTree(Node **leaf, int n)=functie de construire a arborelui nostru tip Huffman . Aceasta functie este cea care sta la baza executiei in parametri buni a programului nostru pentru ca intoarce radacina arborelui construit pe care se fac prelucrarile cerute.Initializam heap-ul si inseram in acesta nodurile initiale ale arborelui.Extragem cele mai mici doua elemente din heap , in locul lor urmand sa punem nodul de legatura obtinut prin insumarea frecventelor si concatenarea numelor celor doi sateliti . Facem legatura acestui nod cu cele doua noduri extrase si il inseram in heap-ul nostru . Efectuam aceste operatii pana cand heap-ul ramane cu un singur element , iar acela va fi radacina arborelui nostru Huffman .
Surse de informare:https://www.geeksforgeeks.org/huffman-coding-in-c/
g)void printTreeBFS(Node *root, FILE *out)=functie de parcurgere si afisare in latime a unui arbore binar . Aceasta functie reprezinta cheia rezolvarii primului task.Funcția printTreeBFS parcurge un arbore binar folosind algoritmul BFS (Breadth-First Search), adică în lățime, nivel cu nivel, începând de la rădăcină. La fiecare pas, salvează nodurile curente într-o coadă și le afișează în fișierul dat ca parametru, în formatul frecvență-etichetă . Odată ce toate nodurile de pe un nivel au fost afișate, se trece automat la linia următoare pentru a afișa nodurile nivelului următor. Se folosește o coadă implementată cu un vector alocat dinamic pentru a gestiona ordinea de procesare a nodurilor, iar la final se eliberează memoria folosită. Funcția este utilă pentru vizualizarea clară a structurii unui arbore Huffman sau a oricărui arbore binar, pe nivelele arborelui binar (0->hmax).

V)Binary.h/Binary.c
a)void binary_to_tree(Node *root, const char *binary, FILE *out)=functie care "transforma" codificarile binare in noduri de arbore . Primim un string binar ca parametru si parcurgem arborele de la radacina conform directiilor date : 0-mergem pe ramura stanga , 1 mergem pe ramura dreapta. Facem aceasta parcurgere pana cand gasim un nod care nu mai are copil stang sau drept si ii afisam label-ul , insemannd ca nodul cu acel label reprezinta acel fragment de informatie binara al string-ului nsotru. Aceasta functie reprezinta cheia rezolvarii task-ului 2.
b)void build_codes(Node *node, char *path, binary_node_t *node_array, int *index)=functia construieste codificarea binara a unui nod prin parcurgerea recursiva a arborelui de la radacina in mod recursiv in ambele directii pana cand gasim nodul cu index-ul cerut . In timpul parcurgerii se obtine string-ul path care ne ofera drumul de la radacina la nodul cerut .Acest path se obtine prin concatenarea la path-ul trecut a caracterelor numerice '0' sau '1' in functie de calea aleasa(left_path || right_path).
c)binary_node_t *create_node_array(Node *root, int *out_size)=functie de creare a vectorului care retine codificare binara a fiecarui nod si numele acestuia . Alocam memorie pentru n binary_nodes , dupa care apelam pentru fiecare nod functia build_codes care construieste pentru fiecare nod codificarea binara.
Ultimele doua functii sunt esentiale pentru rezolvarea task-ului 3.

VI)Task.h/Task.c

Aceasta biblioteca contine implementarile pentru task-urile 2,3&4 in sensul citirilor de date pentru se face prelucrarea si apelurile esentiale de functii care asigura prelucrarea corecta a datelor avand un rol de modularizare al programului.
void task2(Node *root, FILE *in, FILE *out);
void task3(binary_node_t *node_array, int nr_nodes, FILE *in, FILE *out);
void task4(Node *root, FILE *in, FILE *out)=abordarea pentru rezolvarea aceste functii este asemantoare gasirii cmmdc a mai multe numere , dar in acest caz vorbim de stramosul comun a mai multe noduuri . Folosim o variabila flag ok pentru a vedea daca au mai citite alte noduri inainte sau ancestor trebuie initializat cu primul nod citit . Stramosul comun se obtine cu ajutorul functiei << Node *findLCA(Node *root, Node *node1, Node *node2)>> , node1 fiind nodul curent citit si node2 fostul stramos din iteratia anterioara.


