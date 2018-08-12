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

struct node * sort()
{
    struct node *temp =NULL;
    struct node *curr = head;
    struct node *nxt = NULL;
    struct node *sort =NULL;
    struct node *prev =NULL;

    temp = curr;
    curr = curr->next;
    if (temp)
        temp->next = NULL;
    sort = temp;

    while (curr)
    {
        nxt = curr->next;
        curr->next = NULL;

        if (sort == NULL || curr->item < sort->item)
        {
            curr->next = sort;
            sort = curr;
        }
        else
        {
            temp = sort;
            prev = temp;

            while(temp)
            {
                if (curr->item < temp->item)
                {
                    curr->next = temp;
                    prev->next = curr;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
            if (!temp)
                prev->next = curr;
        }

        curr = nxt;

    }
    print_list(sort);
    return sort;
}

void merge (struct node **first,struct node **second)
{
  struct node *head1 = *first;
  struct node *head2 = *second;
struct node dummy;
  struct node *merge =NULL;
  struct node *temp = &dummy;

  while (head1 && head2)
  {

        temp->next = head1;
        head1 = head1->next;
        temp = temp->next;

        temp->next = head2;
        head2 = head2->next;
        temp = temp->next;
  }
   if (head1)
    temp->next = head1;

   if (head2)
    temp->next = head2;

    *first = NULL;
    *second = NULL;

    print_list(dummy.next);

}

  void split_half(struct node *htmp)
  {
      if (!htmp)
            return NULL;

      struct node * slow =htmp;
      struct node * fast =slow->next;

      struct node * first =htmp;
      struct node * second = NULL;

      while(fast)
      {
       fast = fast->next;

           if (fast)
           {
            fast = fast->next;
            slow = slow->next;
           }
        }

       second = slow->next;
       slow->next = NULL;

       reverse(&second);
    print_list(first);
    print_list(second);

    merge(&first,&second);

    printf("##############################\n");

    print_list(first);
    print_list(second);

  }

int main()
{
  struct node *htmp= NULL;
  insert(1);
  insert(2);
  insert(4);
  insert(8);
  insert(7);
  insert(3);
  insert(5);
  insert(6);
insert(16);

  print_list(head);
  htmp= sort();

  split_half(htmp);

  //print_list(head);


}
