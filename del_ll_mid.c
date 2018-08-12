#include<stdio.h>

/*Sort linked list which is already sorted on absolute values*/

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

void del_mid(struct node **head)
{
    struct node *curr = *head;
    struct node *prev = NULL;
    struct node *slow = *head;

    struct node *fast = slow;
    if (fast == NULL)
        return;
    if (fast->next==NULL)
    {
        free(fast);
        *head=NULL;
    }


    while(fast)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;

        if (fast)
            fast = fast->next;

    }

    prev->next = slow->next;
    free(slow);

}


int main()
{
  unsigned int num =0;
  unsigned int shift =0;
  struct node *list1= NULL;
  struct node *list2= NULL;

  insert(19);
  insert(17);
  insert(14);
  insert(13);
  insert(11);
  insert(10);
  insert(8);
  insert(4);
insert(3);
  insert(2);
  insert(1);
 // insert(0);

  print_list(head);
  printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
  del_mid(&head);
  print_list(head);
  return 0;
}
