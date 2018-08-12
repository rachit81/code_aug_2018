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
void sort(struct node **head)
{
    struct node *curr = *head;

    while(curr)
    {

    }

}


void alt_sort(struct node **head)
{
    struct node *curr = *head;

    struct node head1;
    struct node head2;
    struct node *list1 = &head1;
    struct node *list2 = &head2;

    while(curr)
    {
        if (curr->item & 0x1)
        {
            odd->next = curr;
            curr= curr->next;
            odd = odd->next;
            odd->next = NULL;


        }else
        {
            even->next = curr;
            curr= curr->next;
            even = even->next;
            even->next = NULL;
        }

    }
    even->next = head1.next;
    *head = head2.next;
    return;
}


int main()
{
  struct node *list1= NULL;
    struct node *list2= NULL;
# if 1
  insert(19);
  insert(0);
  insert(17);
  insert(12);
  insert(14);
  insert(89);
  insert(97);
  insert(56);
  insert(1);
#endif // 0
  print_list(head);
  printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
  alt_sort(&head);
  print_list(head);


}
