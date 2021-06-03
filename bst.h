#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef struct node
{
    int *data;
    struct node *left;
    struct node *right;
}BST;

BST *Newnode(int *);
BST *insertbst(BST *, int *);
BST *searchbst(BST *, int *);
void inorder(BST *);

#endif // BST_H_INCLUDED
