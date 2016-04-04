#include <stdio.h>
typedef struct node
{
int item;
struct node *next;
}node;

//struct node *head = NULL;

void insert ( int num,struct node **hdr)
{
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->item =num;
  temp->next =*hdr;
  *hdr = temp;
}


int main()
{
  struct node *htmp= NULL;
  struct node *head = NULL;
  insert(45,&head);
  insert(90,&head);
  insert(34,&head);
  insert(67,&head);
  insert(0,&head);
  insert(18,&head);
  print_list(head);



  insert(345,&htmp);
  insert(87,&htmp);
  insert(23,&htmp);
  insert(5,&htmp);
  insert(7,&htmp);
  insert(12,&htmp);
  insert(0,&htmp);
 insert(34,&htmp);



  print_list(htmp);



}

