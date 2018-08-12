#ifndef BIN_TREE_H_INCLUDED
#define BIN_TREE_H_INCLUDED

typedef struct Tnode
{
  int data;
  struct Tnode *left;
  struct Tnode *right;
  struct Tnode *next; // Only for inorder traversal
}Tnode;


#endif // BIN_TREE_H_INCLUDED
