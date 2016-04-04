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


void print_list ( struct node *hdr)
{
  while(hdr !=NULL)
  {
   printf (" %d --->",hdr->item);
   hdr = hdr->next; 
  }
   printf (" NULL \n ");
}

void makeloop(struct node **hdr)
{
  struct node *curr = *hdr;
while(curr->next!=NULL)
  curr=curr->next;
curr->next = (*hdr)->next->next;  
return;
}

void mkloop(struct node **hdr)
{
  struct node *curr = *hdr;
while(curr->next!=NULL)
  curr=curr->next;
curr->next = (*hdr);  
return;
}


unsigned char IsLoop(struct node *hdr)
{
  
  struct node *slow=hdr;
  if (slow ==NULL)
    return;

  struct node *fast = slow->next;

  while(fast !=NULL)
  {
    if (fast == slow)
    return 1;
    slow = slow->next;  
    fast = fast->next;
    if (fast !=NULL)
    fast = fast->next;
  }
  return 0;
}

int main()
{
  struct node *htmp= NULL;
  struct node *head = NULL;
  insert(45,&head);
#if 0
  insert(90,&head);
  insert(34,&head);
  insert(67,&head);
  insert(0,&head);
  insert(0,&head);
  insert(18,&head);
#endif
  print_list(head);
//  makeloop(&head);
 mkloop(&head);
printf (" Loop is %u \n",IsLoop(head));
  //print_list(head);


}

