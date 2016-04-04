#include <stdio.h>
typedef struct node
{
int item;
struct node *next;
}node;

struct node *head = NULL;

void insert ( int num)
{
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->item =num;
  temp->next =head;
  head = temp;
}

void sort(struct node **hdr)
{
  struct node *curr = *hdr;
  struct node *temp = NULL;
  struct node *Ntemp = NULL;
  struct node *itr = NULL;
  struct node *prv = NULL;

  if (curr == NULL)
     return;
  
  temp = curr;
  curr = curr->next;
  temp->next =NULL;
  itr = temp;

  while (curr != NULL)
  {
    Ntemp = curr->next;
    itr = temp;
    prv = NULL;
    while (itr != NULL && itr->item < curr->item)
    {
      prv =itr;
      itr=itr->next;
    }
    if (prv != NULL)
    {
    curr->next = prv->next;
    prv->next = curr;
    }
    else {
    curr->next =temp;
    temp = curr; 
    }
  
    curr= Ntemp;
  }

  *hdr = temp;

}

void print_list ( struct node *hdr)
{
  while(hdr !=NULL)
  {
   printf (" %d --->",hdr->item);
   hdr = hdr->next; 
  }
   printf (" NULL \n ");
}


int main()
{
  struct node *htmp= NULL;
  insert(45);
  insert(90);
  insert(34);
  insert(67);
  insert(0);
  insert(18);
  print_list(head);
  sort(&head);

  print_list(head);

  sort(&htmp);
}

