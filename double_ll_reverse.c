#include<stdio.h>

typedef struct node
{
    int item;
    struct node *next;
    struct node *prev;
}node;

struct node *head = NULL;

void insert ( int num)
{
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->item =num;
  temp->next =head;
  if (head)
    head->prev = temp;

  head = temp;
}

void print_list ( struct node *hdr)
{
  while(hdr !=NULL)
  {
   printf (" %d <--->",hdr->item);
   hdr = hdr->next;
  }
   printf (" NULL \n ");
}



 void dbl_ll_reverse(struct node **head)
 {
    struct node *current =*head;
    struct node *orig_nxt = NULL;
    struct node *swap =NULL;
    struct node *prev =NULL;
    struct node *last =NULL;
    if (!current)
        return;

    while (current)
    {
        orig_nxt = current->next;
        swap = current->next;
        current->next = current->prev;
        current->prev= swap;
        last = current;
        current = orig_nxt;
    }
    *head = last;
  }

int main()
{
  struct node *list1= NULL;
    struct node *list2= NULL;
# if 1
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  insert(5);
  insert(6);
  insert(7);
  insert(8);
  insert(9);
  insert(10);
  insert(11);
  insert(12);
  insert(13);
#endif // 0
  print_list(head);
  printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
  dbl_ll_reverse(&head);
  print_list(head);


}
