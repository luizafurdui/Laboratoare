#include <stdlib.h>
#include <stdio.h>
#include "arbore.h"

struct Node* createNode(int val)
{
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->val = val; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
}
struct Node * insert(struct Node * p, int val)
{
    struct Node * newNode; 
    if(p == NULL) 
    {
        newNode = createNode(val); 
        return newNode; 
    }
    else
    if(val<p->val)
    {
        p->left = insert(p->left, val); 
    }
    else
    if(val>p->val)
    {
        p->right = insert(p->right, val);
    }
    return p; 
}
void postorder(struct Node * root)
{

    if(root != NULL)
    {
        postorder(root->left); 
        postorder(root->right); 
        printf("%d ", root->val); 
    }
}

void inorder(struct Node * root)
{
    if(root!= NULL)
    {
        inorder(root->left); 
        printf("%d ", root->val); 
        inorder(root->right); 
    }
}

void preorder(struct Node * root)
{
    if(root != NULL)
    {
        printf("%d ", root->val); 
        preorder(root->left); 
        preorder(root->right); 
    }
}

struct Node *  cautare(struct Node * root, int val)
{
    struct Node * p = root; 
    while(p)
    {
        if(p->val == val)
        {
            return p; 
        }
        else if(val<p->val) p = p->left; 
        else
        if(val>p->val) p = p->right; 
    }
    return NULL; 
}
struct Node * minim(struct Node * root)
{
    struct Node * current = root; 
    while(current && current->left != NULL)
    {
        current = current->left; 
    }
    return current; 
}

struct Node * maxim(struct Node * root)
{
    struct Node * current = root; 
    while(current && current ->right != NULL)
    {
        current = current ->right; 
    }
    return current; 
}

struct Node* succesor(struct Node * root, struct Node * p) // cheia dintr un container imediat mai mare decat cheia dintr un nod dat 
{
        if(p->right != NULL) // caz 1: exista un nod in subarborele drept
        {
            return minim(p->right); 
        }
        // caz 2: nu exista nod in subarborele drept
        //caut primul stramos pt care nodul p se afla in subarborele stang 

            struct Node * succ = NULL; 
            struct Node * ancestor = root; 
            while(ancestor)
            {
               if(p->val < ancestor->val)
               {
                succ = ancestor; //am gasit un posibil succesor. 
                ancestor = ancestor->left; 
               }
               else
               if(p->val > ancestor->val)
               {
                   ancestor = ancestor->right; 
               }
               else{
                break; //am gasit nodul 
               }

            }
    return succ; 
}

struct Node * predecesor(struct Node * root, struct Node * p) // cheia dintr un container imediat mai mica decat noduul
{
    if(p->left != NULL )
    {
        return maxim(p->left); 
    }

    //caz 2: nodul nu are subarbore stang, deci caut un parinte care e mai mic decat nodul p
    struct Node * parent = root; 
    struct Node * pred = NULL ;
    while(parent != NULL)
    {     
        if(parent->val<p->val)
        {
            pred = parent; 
            parent = parent->right; 
        }
        else
            parent = parent->left; 

            
    }

     return pred; 

}


struct Node * DeleteNode(struct Node * p, int x) {
    if (p == NULL) 
        return NULL; // Dacă s-a ajuns la un subarbore vid, nu există nimic de șters.

    if (x < p->val) {
        // Se șterge din subarborele stâng
        p->left = DeleteNode(p->left, x);
        return p;
    } 
    else if (x > p->val) {
        // Se șterge din subarborele drept
        p->right = DeleteNode(p->right, x);
        return p;
    } 
    else {
        // Am găsit nodul care trebuie șters
        if (p->left != NULL && p->right != NULL) {
            struct Node * temp = minim(p->right); // Se găsește succesorul minim
            p->val = temp->val; // Se mută cheia minimă în nodul curent
            // Se șterge succesorul din subarborele drept
            p->right = DeleteNode(p->right, temp->val);
            return p;
        } else {
            // Nodul are un singur copil sau este frunză
            struct Node * temp = p;
            struct Node * repl; // Noul nod de înlocuire
            if (p->left == NULL) {
                // Nu există subarbore stâng
                repl = p->right;
            } else {
                // Nu există subarbore drept
                repl = p->left;
            }
            free(temp); // Dealocare spațiu pentru nodul șters
            return repl; // Returnează nodul înlocuitor
        }
    }
}
