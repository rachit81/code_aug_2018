#include<stdio.h>
#include<limits.h>
#define MAX 8

typedef struct qnode{
  int queue[MAX];
  int front;
  int rear;
  int size;
}QNODE;

QNODE *Qnode =NULL;

void Qinit()
{
  Qnode = (QNODE *)malloc(sizeof(QNODE));
  Qnode->rear =-1;
  Qnode->front =0;
  Qnode->size =0;
}
void Qreset()
{
  Qnode->rear =-1;
  Qnode->front =0;
  Qnode->size =0;
}


void enqueueHead(int num)
{
//  if (Qnode->size == MAX)
  if (Qnode->rear == Qnode->front)
  {
    printf(" queue full \n");
    return;
  }
  Qnode->queue[Qnode->front] = num;
  Qnode->front = (Qnode->rear+1)%MAX;
  Qnode->size++;
}

void enqueueTail(int num)
{
  if (Qnode->size == MAX)
  {
    printf(" queue full \n");
    return;
  }
  Qnode->queue[Qnode->rear] = num;
  Qnode->rear = (Qnode->rear+1)%MAX;
  Qnode->size++;
}


int isQempty()
{
  if (Qnode->size == 0)
  {
    return 1 ;
  }
  return 0;
}

Tnode * dequeue()
{
  Tnode * num =0;

  if (Qnode->size == 0)
  {
    printf("queue empty\n");
    return -1 ;
  }
  num = Qnode->queue[Qnode->front];
  Qnode->front = (Qnode->front+1)%MAX;
  Qnode->size--;
  return num;
}
