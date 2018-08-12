#include<stdio.h>

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

void print_list ( struct node *hdr)
{
  while(hdr !=NULL)
  {
   printf (" %d --->",hdr->item);
   hdr = hdr->next;
  }
   printf (" NULL \n ");
}
void alt_split(struct node **head, struct node **a, struct node **b)
{
    struct node *curr = *head;

     struct node head1;
      struct node head2;
          struct node *temp1 = &head1;
    struct node *temp2 = &head2;
    while(curr)
    {
        temp1->next =curr;
        curr = curr->next;
        temp1 = temp1->next;
            temp1->next = NULL;

        if(curr)
        {
            temp2->next =curr;
            curr = curr->next;
            temp2= temp2->next;
            temp2->next = NULL;
        }

    }
    *a = head1.next;
    *b = head2.next;
    *head = NULL;
    return;
}
int main()
{
  struct node *list1= NULL;
    struct node *list2= NULL;
# if 1
  insert(1);
  insert(0);
  insert(1);
  insert(0);
  insert(1);
  insert(0);
  insert(1);
  insert(0);
  insert(1);
#endif // 0
  print_list(head);
  printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
  alt_split(&head, &list1, &list2);
  print_list(head);
  print_list(list1);
  print_list(list2);

}
