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
    int i =0;

  while(hdr !=NULL)
  {
   printf (" %d --->",hdr->item);
   hdr = hdr->next;
   i++;
   if (i > 20) break;
  }
   printf (" NULL \n ");
}

void make_loop(struct node *head)
{
    struct node *current = head;
    struct node *temp = NULL;
    struct node *last =NULL;

    while(current)
    {
        if (current->item == 3)
        {
            temp = current;
        }
        last = current;
        current = current->next;
    }

    last->next = temp;
    // last->next = head;


}

void detect_loop(struct node * head)
{
    struct node * slow = head;

    if (slow == NULL)
        return;

    struct node * fast = head;
    struct node *curr =head;
    struct node *temp =NULL;

    while(fast && fast->next)
    {
     slow = slow->next;
     fast = fast->next;
     fast = fast->next;

     if (slow == fast)
     {
         temp = slow;
         printf("POINT OF matching found %d \n",slow->item);
         break;
     }

    }

    slow =head;

    while(slow)
    {
       if (slow == temp)
       {
        printf("POINT OF INTERSECTION FOIUND  %d \n",slow->item);
        break;
       }

       slow = slow->next;
       temp= temp->next;
    }


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

#endif // 0
  print_list(head);
  printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
  make_loop(head);
  print_list(head);
  detect_loop(head);
  //print_list(list1);
  //print_list(list2);

}
