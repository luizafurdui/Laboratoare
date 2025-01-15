#ifndef ARBORE_H
#define ARBORE_H

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int val);
struct Node* insert(struct Node* root, int val);
struct Node* cautare(struct Node* root, int val);
struct Node* minim(struct Node* root);
struct Node* maxim(struct Node* root);
struct Node * predecesor(struct Node * root, struct Node * p); 
struct Node* succesor(struct Node * root, struct Node * p); 
void inorder(struct Node* root);
void preorder(struct Node* root);
void postorder(struct Node* root);


#endif
