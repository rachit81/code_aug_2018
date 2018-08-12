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



  void split_half(struct node *htmp,struct node **list1,struct node **list2)
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


    print_list(first);
    reverse(&second);
    print_list(second);

    *list1 = first;
    *list2 = second;

    printf("##############################\n");



  }

 void compare_list(struct node *list1,struct node *list2)
  {

     if ( list1 == NULL  && list2 != NULL)
    {
            printf(":-( NOT a palindrome null list\n");
            return;
    }
     if ( list1 != NULL  && list2 == NULL)
    {
            printf(":-( NOT a palindrome null list\n");
            return;
    }

    while(list1 && list2)
    {
        if (list1->item != list2->item)
        {
            printf(":-( NOT a palindrome list\n");
            return;
        }

        list1 = list1->next;
        list2 = list2->next;

    }
    if ( list1 == NULL  && list2 == NULL)
    {
            printf("palindrome EVEN list\n");
            return;
    }

    if ( list1->next == NULL  && list2 == NULL)
    {
            printf("palindrome ODD list\n");
            return;
    }

  }

int main()
{
  struct node *list1= NULL;
    struct node *list2= NULL;
# if 0
  insert(1);
  insert(2);
  insert(4);
  insert(8);
  insert(7);
  insert(9);
  insert(4);
  insert(2);
  insert(1);
#endif // 0
  print_list(head);
  printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
  split_half(head,&list1,&list2);

  compare_list(list1,list2);
  //print_list(head);


}
