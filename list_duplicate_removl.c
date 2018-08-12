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



 void remove_dupl_unsort(struct node *head)
  {
    struct node *current =head;
    struct node *temp = NULL;
    struct node *prev =NULL;

    while (current)
    {
        temp= current->next;
        prev=current;

        while(temp)
        {
            if (current->item == temp->item)
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }else{
                prev=temp;
                temp= temp->next;
            }
        }
        current = current->next;
    }


  }

int main()
{
  struct node *list1= NULL;
    struct node *list2= NULL;
# if 1
  insert(1);
    insert(1);
  insert(1);

  insert(2);
  insert(4);
  insert(8);
    insert(2);
  insert(2);
  insert(2);
  insert(7);
  insert(7);
  insert(7);

  insert(7);
  insert(9);
  insert(4);
  insert(2);
  insert(1);
#endif // 0
  print_list(head);
  printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
 remove_dupl_unsort(head);
  print_list(head);


}
