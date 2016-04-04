#include <stdio.h>
#include <limits.h>

typedef struct Tnode
{
  int data;
  struct Tnode *left;
  struct Tnode *right;
}Tnode;

Tnode *head =NULL;
 


struct Tnode * insertNode(struct Tnode *root, int num)
{
  if (root == NULL)
  {
    Tnode *node = (Tnode *) malloc(sizeof(Tnode));
    node->data = num;
    node->left = NULL; 
    node->right = NULL;
    return node;
  }
  if(root->data > num )
  { 
    root->left = insertNode(root->left,num);
  }
  else
  {
    root->right = insertNode(root->right,num);
  }
  return root; 
}
void inorder (struct Tnode *head)
{
  if (head == NULL)
    return;
  inorder(head->left);
  printf(" %d \t",head->data);
  inorder(head->right);

}

int IsBST( struct Tnode *head, int max,int min)
{
  if (head == NULL)
    return 1;
  
  if ( head->data > max)    
    return 0;
  
  if (head->data < min)    
    return 0;

  return( IsBST(head->left,min,head->data) || IsBST(head->right,head->data,max));

}



int main()
{
  struct Tnode *head = NULL;
  
  head = insertNode(head,18);  
  head = insertNode(head,29);  
  head = insertNode(head,23);  
  head = insertNode(head,2);  
  head = insertNode(head,19);  
  head = insertNode(head,30);  
  head = insertNode(head,20);  
  head = insertNode(head,8);  
  head = insertNode(head,7);  
  head = insertNode(head,17);  
  head = insertNode(head,22);  
  inorder(head);
  
  printf( " is BST %d \n\n ",IsBST(head,INT_MIN,INT_MAX));  

  printf("\n");
}

