

#include <stdio.h>   // Pentru printf
#include <stdlib.h>  // Pentru malloc, free, exit
#include "arbore.h"
#include "arbore.c"  // Pentru structuri și funcții definite de tine

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    insert(root, 4);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    struct Node* NodCautat = cautare(root, 40);
    if (NodCautat == NULL) {
        printf("Nodul căutat nu există în arbore.\n");
        return 1;
    }

    struct Node* Nodpredecesor = predecesor(root, NodCautat);
    if (Nodpredecesor != NULL) {
        printf("Predecesorul nodului %d este %d\n", NodCautat->val, Nodpredecesor->val);
    } else {
        printf("Nodul %d nu are predecesor\n", NodCautat->val);
    }

    struct Node* NodSuccesor = succesor(root, NodCautat);
    if (NodSuccesor != NULL) {
        printf("Succesorul nodului %d este %d\n", NodCautat->val, NodSuccesor->val);
    } else {
        printf("Nodul %d nu are succesor\n", NodCautat->val);
    }

    printf("\n"); 
   struct Node * deletedNode =  DeleteNode(root, 30); 
   printf("am sters nodul %d : ", deletedNode->val); 
       printf("\n"); 

   inorder(root); 

    return 0;
}
