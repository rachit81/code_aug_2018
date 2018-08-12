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

void sort(struct node **start)
{
    struct node *curr = *start;
    struct node head;
    head.next = NULL;
    struct node *list1;
    struct node *prev;
    struct node *temp;

    while(curr)
    {
        temp = curr->next;

        prev = &head;
         list1 = prev->next;

        while(list1)
        {
            if(curr->item < list1->item)
                break;

            prev = list1;
            list1 = list1->next;
        }
        curr->next =  prev->next;
        prev->next = curr;

        curr = temp;

    }
    *start = head.next;
}

void reverse(struct node ** head)
{
    struct node *curr = *head;
    struct node *prev =NULL;
    struct node *nxt;

    while(curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    *head = prev;

}
void sort_merge (struct node *list1,struct node *list2,struct node **head)
{
    struct node head1;
    struct node *merge = &head1;

    while(list1 && list2)
    {
        merge->next = list1;
        merge = merge->next;
        list1 = list1->next;

        merge->next = list2;
        merge = merge->next;
        list2= list2->next;
    }
      print_list(merge);


    if (list1)
        merge->next = list1;
    else if (list2)
        merge->next =list2;

    *head = head1.next;
}


void alt_sort(struct node **head)
{
    if (*head ==NULL)
        return;

    struct node *mid = *head;
    struct node *curr=NULL;
    if (mid)
     curr = mid->next;

    struct node head1;
    struct node head2;
    struct node *list1 = &head1;
    struct node *list2 = &head2;

    while(curr)
    {
        mid = mid->next;

        curr = curr->next;
        if(curr)
            curr = curr->next;
    }

    list2->next = mid->next;
    mid->next =NULL;
    list1->next = *head;

    reverse(&list2->next);
  print_list(list1->next);
  print_list(list2->next);

    sort_merge(list1->next,list2->next,head);
  print_list(*head);

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
  sort(&head);
    print_list(head);

    printf("####################################\n");
 alt_sort(&head);


}
