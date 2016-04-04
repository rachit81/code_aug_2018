#include<stdio.h>

#define MAX 100
typedef struct node
{
int data;
struct node *next;
}node;


struct node *head = NULL;

void push(int num)
{
  struct node *curr = NULL;
  curr = (struct node *)malloc(sizeof(struct node));
  curr ->data = num;
  curr->next = head;
  head = curr;
}

int pop()
{
  int data;
  struct node *temp =NULL;
  if(head ==NULL)
  {
    printf (" stack empty \n");
    return -1;
  }
  data = head->data;
  temp = head;
  head = head->next;
  free(temp); 
  return data; 
}


int main()
{
push(3);
push(7);
push(17);
push(19);
push(31);
push(71);

printf(" number is %d \n",pop());
printf(" number is %d \n",pop());
printf(" number is %d \n",pop());
printf(" number is %d \n",pop());
printf(" number is %d \n",pop());
printf(" number is %d \n",pop());
printf(" ######################### \n");
printf(" number is %d \n",pop());

printf(" $$$$$$$$$$$$$$$$$$$$$$$$ \n");
printf(" number is %d \n",pop());

}


