#include <stdio.h>
#include <stdlib.h>

// Structura pentru un nod
struct Node {
    int val;
    struct Node* next;
};

// Structura pentru lista simplu inlantuita
struct List {
    struct Node* head; // Primul nod
    struct Node* tail; // Ultimul nod
};

// Funcție pentru crearea unui nod
struct Node* creeazaNod(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Funcție pentru crearea unei liste goale
struct List* creeazaLista() {
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Funcție pentru a adăuga un nod la sfârșit
void adaugaSfarsit(struct List* list, int val) {
    struct Node* newNode = creeazaNod(val);
    if (list->head == NULL) { // Lista este goală
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Funcție pentru a afișa lista
void afiseazaLista(struct List* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Funcție pentru a șterge un nod
void sterge(struct List* list, struct Node* p) {
    if (p == list->head) { // Ștergem primul nod
        list->head = list->head->next;
        if (list->head == NULL) { // Lista devine goală
            list->tail = NULL;
        }
        free(p);
    }
    else {
        struct Node* q = list->head;
        while (q->next != p) {
            q = q->next;
        }
        if (p == list->tail) { // Ștergem ultimul nod
            list->tail = q;
            q->next = NULL;
        }
        else { // Ștergem nodul p din mijloc
            q->next = p->next;
        }
        free(p);
    }
}

// Funcție pentru a căuta un nod
struct Node* searchNode(struct List* list, int val) {
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->val == val) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Funcția main
int main() {
    struct List* list = creeazaLista(); // Creăm lista

    adaugaSfarsit(list, 23);
    adaugaSfarsit(list, 34);
    adaugaSfarsit(list, 4);
    adaugaSfarsit(list, 6);

    printf("Lista inițială: ");
    afiseazaLista(list);

    struct Node* nodDeSters = searchNode(list, 6);
    if (nodDeSters != NULL) {
        sterge(list, nodDeSters);
        printf("Lista după ștergerea nodului: ");
        afiseazaLista(list);
    }
    else {
        printf("Nodul cu valoarea 6 nu a fost găsit!\n");
    }

    return 0;
}
