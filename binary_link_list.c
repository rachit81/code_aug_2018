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

void binary(struct node **head)
{
    reverse(head);
    unsigned int shift =0;
    unsigned int num = 0;
    struct node * curr = *head;

     while(curr)
     {
         num = num + curr->item * (1<<shift);
         curr = curr->next;
         shift++;
     }
         reverse(head);

     printf("num %d \n ",num);
}



unsigned int rec_binary(struct node *head,unsigned int * shift)
{
    unsigned int num =0;

    if (head == NULL)
        return 0;
    else
        num = rec_binary(head->next,shift);

    num = num + head->item * (1<<*shift);
    (*shift)++;

    return num;

}






int main()
{
    unsigned int num =0;
    unsigned int shift =0;
  struct node *list1= NULL;
    struct node *list2= NULL;
  insert(1);
  insert(0);
  insert(1);
  insert(1);
  insert(1);
  insert(1);
  insert(0);
  insert(1);
  insert(1);

  print_list(head);
  printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
  binary(&head);

  num = rec_binary(head,&shift);
  printf("%d \n",num);
}
