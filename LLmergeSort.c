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

void mergesort(struct node **a, struct node **b)
{
struct node *list1 = *a;
struct node *list2 = *b;
struct node dummy;
struct node *temp = &dummy;
  if (list1 == NULL)
  {
    *a = *b;
    *b=NULL;
    return;
  }
  if (list2 == NULL)
  {
    return;
  }

  while (list1 != NULL && list2 != NULL)
  {

    if(list1->item < list2->item)
    {
     temp->next = list1;
     temp= temp->next;
     list1=list1->next;
     temp->next=NULL;
    }else
    {

     temp->next = list2;
     temp= temp->next;
     list2=list2->next;
     temp->next=NULL;
    }

  }

  if (list1 == NULL)
  {
    temp->next = list2;
    *b =NULL;
    *a = dummy.next;
    return;
  }

  if (list2 == NULL)
  {
    temp->next = list1;
    *a =NULL;
    *a = dummy.next;
    return;
  }
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
  sort(&head);

  print_list(head);


  insert(345,&htmp);
  insert(87,&htmp);
  insert(23,&htmp);
  insert(5,&htmp);
  insert(7,&htmp);
  insert(12,&htmp);
  insert(0,&htmp);
 insert(34,&htmp);


  sort(&htmp);

  print_list(htmp);

  mergesort(&head,&htmp);

  print_list(head);

}

