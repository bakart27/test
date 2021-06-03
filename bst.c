#include "main.h"
#include "bst.h"

BST *Newnode(int *line)
{
    BST *node=malloc(sizeof(BST));
    node->left=NULL;
    node->right=NULL;
    node->data=line;
    return node;
}

BST *insertbst(BST *root, int *line)
{
    if(root==NULL)  return Newnode(line);
    if(root->data < line)
        root->right=insertbst(root->right,line);
    else
        root->left=insertbst(root->left,line);
    return root;
}

BST *searchbst(BST *root, int *target)
{
	BST *node=root;
	while(node)
	{
		if(target>node->data)
			node=node->right;
		else if(target<node->data)
			node=node->left;
		else	break;
	}
	return node;
}

void inorder(BST *root)
{
    if(root==NULL)  return;
    inorder(root->left);
    //printf("%s\n", root->data);
    inorder(root->right);
}
