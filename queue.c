#include<stdio.h>
#define MAX 5
typedef struct qnode{
  int queue[MAX];
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

void enqueue(int num)
{
  if (Qnode->size == MAX)
  {
    printf(" queue full \n");
    return;
  }
  Qnode->queue[Qnode->rear] = num;
  Qnode->rear = (Qnode->rear+1)%MAX;
  Qnode->size++;
  //  printf("rear %d size %d \n",Qnode->rear,Qnode->size);
}
int dequeue()
{
  int num =0;

//  printf(" <======= Front %d size %d ======> \n",Qnode->front,Qnode->size);
  
//  if (Qnode->rear == Qnode->front)
  if (Qnode->size == 0)
  {
    printf("queue empty\n");
    return -1 ;
  }
  num = Qnode->queue[Qnode->front];
  Qnode->front = (Qnode->front+1)%MAX;
  Qnode->size--;
  // printf(" <------- Front %d size %d ------> \n",Qnode->front,Qnode->size);
  return num;
}
int main()
{
Qinit();

enqueue(111);
enqueue(222);
enqueue(333);
enqueue(444);
enqueue(555);
enqueue(666);
enqueue(777);
enqueue(888);

 printf(" ----- rear %d size %d \n",Qnode->rear,Qnode->size);

printf("Num is  %d \n",dequeue());
printf("Num is  %d \n",dequeue());
printf("Num is  %d \n",dequeue());
printf("Num is  %d \n",dequeue());
printf("Num is  %d \n",dequeue());
printf("Num is  %d \n",dequeue());
printf("Num is  %d \n",dequeue());
printf("Num is  %d \n",dequeue());
 printf(" ----- rear %d size %d \n",Qnode->rear,Qnode->size);
printf(" ######################### \n");
printf(" ######################### \n");



printf(" ######################### \n");

printf(" $$$$$$$$$$$$$$$$$$$$$$$$ \n");

}


