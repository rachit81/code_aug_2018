#include <stdio.h>

typedef struct Tnode
{
  int data;
  struct Tnode *left;
  struct Tnode *right;
}Tnode;

Tnode *head =NULL;
 
#define MAX 50
typedef struct qnode{
  struct Tnode* queue[MAX];
  int rear;
  int front;
  int size;
}QNODE;
QNODE *Qnode =NULL;
QNODE * Qinit()
{
  Qnode = (QNODE *)malloc(sizeof(QNODE));
  Qnode->rear =0;
  Qnode->front =0;
  Qnode->size =0;
  return Qnode;
}

void enqueue(struct Tnode *node)
{
  if (Qnode->size == MAX)
  {
    printf(" queue full \n");
    return;
  }
  Qnode->queue[Qnode->rear] = node;
  Qnode->rear = (Qnode->rear+1)%MAX;
  Qnode->size++;
//   printf("rear %d size %d \n",Qnode->rear,Qnode->size);
}
struct node* dequeue()
{
  struct Tnode *node;

//  printf(" <======= Front %d size %d ======> \n",Qnode->front,Qnode->size);
  
//  if (Qnode->rear == Qnode->front)
  if (Qnode->size == 0)
  {
    printf("queue empty\n");
    return -1 ;
  }

  node = Qnode->queue[Qnode->front];
  Qnode->front = (Qnode->front+1)%MAX;
  Qnode->size--;
  // printf(" <------- Front %d size %d ------> \n",Qnode->front,Qnode->size);
  return node;
}


int Qempty()
{
  if (Qnode->size == 0)
  {
    printf("queue empty\n");
    return 1 ;
  }
  return 0;
}


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


void levelorder(struct Tnode *root)
{
  struct Tnode *curr =NULL;
  int level =0;

  if (root == NULL)
  return;

      printf("\n");
      printf("\n");

  enqueue(root);
  enqueue(NULL);

  while(!Qempty())
  {
   curr = dequeue();
   if (curr != NULL)
    {
      printf("%d \t",curr->data);
      if(curr->left)
      {
        enqueue(curr->left);
      }
      if(curr->right)
      {
        enqueue(curr->right);
      }
    }else
    { 
      level++;
      printf("\n");
      if (!Qempty())
      {
        enqueue(NULL);
      }
    }   
  }  
}

int main()
{
  struct Tnode *head = NULL;
  Qinit();
  
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
  levelorder(head);
  printf("\n");
}

