#include <stdio.h>

Tnode *head =NULL;
typedef struct Tnode
{
  int data;
  struct Tnode *left;
  struct Tnode *right;
}Tnode;
 
#define MAX 50
typedef struct qnode{
  struct Tnode* queue[MAX];
  int rear;
  int front;
  int size;
}QNODE;
QNODE *Qnode =NULL;
void Qinit()
{
  Qnode = (QNODE *)malloc(sizeof(QNODE));
  Qnode->rear =0;
  Qnode->front =0;
  Qnode->size =0;
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
  //  printf("rear %d size %d \n",Qnode->rear,Qnode->size);
}
struct node* dequeue()
{
  sruct Tnode *node;

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


void insertNode(int num)
{
  Tnode *node = (Tnode *) malloc(sizeof(Tnode));
  node->data = num;
  node->left = NULL; 
  node->right = NULL;
  if (head == NULL)
  {
    head = node; 
    return;
  }
  
  
}

int main()
{

Qinit();
}

