
#include <stdlib.h>
#include <stdio.h>
struct Node{
    int val; 
    struct Node * next; 
    struct Node * prev; 
}; 

struct List{
    struct Node * head; 
    struct Node* tail; 
};

struct Node * createNode(int val)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node)); 
    newNode->val = val; 
    newNode -> next = NULL; 
    newNode->prev = NULL; 
    return newNode; 

}
struct List * createList()
{
    struct List * newList = (struct List*)malloc(sizeof(struct List)); 
    newList -> head = NULL;
    newList->tail = NULL; 
    return newList; 

}
void adaugaInainte(struct List * list, struct Node * p, int val)
{
    struct Node * newNode = createNode(val); 
    //daca se adauga inaintea primului nod
    if(p == list->head)
    {
        //adaug inainte de head
        newNode->next = list->head; 
        //p este sigur diferit de null prin preconditie 
        list->head->prev = newNode; 
        //actualizez head ul
        list->head = newNode;  
    }
    else{ //se aduaga intre [p].prec si p

    newNode->next = p;
    p->prev->next = newNode; 
    newNode->prev = p->prev; 
    p->prev = newNode; 


    }
}

void adauga_la_inceput_sfarsit(struct List* list, struct Node * head, int val)
{
    struct Node * newNode = createNode(val); 

    if(head == NULL) // lista e goala
    {
        list->head = newNode; 
        list->tail = newNode; 
    }
    else //lista nu e goala, adaug la sfarsit
    {
        list->tail->next = newNode; 
        newNode->prev = list->tail; 
        list->tail= newNode; 

    }
}

void printList(struct Node * head)
{
    struct Node * current = head; 
    while(current!= NULL )
    {
        printf("%d ", current->val); 
        current = current -> next; 
    }

}
struct Node * cautaNod( struct Node* head, int val) //caut nodul inainte de val 
{

    struct Node* current= head; 
    while(current!=NULL)
    {
        if(current->val == val) return current; 
         current=current->next; 
    }

    return 0; 
}

void stergere(struct List* list, struct Node* p) {
    if (p == NULL) return; // Dacă nodul este NULL, nu facem nimic

    // Dacă nodul este primul nod din listă
    if (p == list->head) {
        list->head = p->next; // actualizez head
        if (list->head != NULL) {
            list->head->prev = NULL; // Eliminăm legătura către nodul șters
        } else {
            list->tail = NULL; // Dacă lista devine goală
        }
    } 
    // Dacă nodul este ultimul nod din listă
    else if (p == list->tail) {
        list->tail = p->prev; // Mutăm tail la nodul precedent
        if (list->tail != NULL) {
            list->tail->next = NULL; // Eliminăm legătura către nodul șters
        } else {
            list->head = NULL; // Dacă lista devine goală
        }
    } 
    // Dacă nodul este în mijlocul listei
    else {
        p->prev->next = p->next; // Nodul anterior îl leagă de nodul următor
        p->next->prev = p->prev; // Nodul următor îl leagă de nodul anterior
    }

    free(p); // Eliberăm memoria alocată nodului șters
}

int main()
{

    struct List * list = createList(); 
   // struct Node * predecesor = cautaPredecesor(head, 4);

   adauga_la_inceput_sfarsit(list, list->head, 5);  
   adauga_la_inceput_sfarsit(list, list->head, 7); 

   struct Node * nodCautat = cautaNod(list->head, 7);
   if(nodCautat!=NULL)
   {
    adaugaInainte(list, nodCautat, 9);
   }  
   printList(list->head); 

    return 0; 
}