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

void normal_sort(struct node **head)
{
    struct node *curr = *head;
    struct node head1;
    struct node *pos = &head1;
    struct node *neg=NULL ;
    struct node *temp;
    struct node *prev;

    while(curr)
    {
        temp = curr->next;

        if (curr->item < 0)
        {
            curr->next =neg;
            neg =curr;
        }else{
            pos->next =curr;
            pos = curr;
        }

        curr = temp;
    }
    pos->next =NULL;
    temp=neg;

    while(neg)
    {
        prev = neg;
        neg = neg->next;
    }
    if (prev)
        prev->next = head1.next;

    if (temp)
        *head = temp;
    else
        *head = head1.next;
}


int main()
{
  unsigned int num =0;
  unsigned int shift =0;
  struct node *list1= NULL;
  struct node *list2= NULL;

  insert(-19);
  insert(17);
  insert(-14);

  insert(13);
  insert(11);
  insert(-10);
  insert(-8);
  insert(-4);
   insert(3);
  insert(-2);
  insert(-1);
 // insert(0);

  print_list(head);
  printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
  normal_sort(&head);
  print_list(head);

  printf("%d \n",num);
}
