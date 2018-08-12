#include <stdio.h>
#include <stdlib.h>
#include  <limits.h>
/* Node of a doubly linked list */
struct DNode
{
  int data;
  struct DNode *next; // Pointer to next node in DLL
  struct DNode *prev; // Pointer to previous node in DLL
};

struct Snode
{
    int data;
    struct Snode *next;
};



void InsertNode(struct Snode **head,int key)
{
    struct Snode *curr = *head;
    struct Snode *prev =NULL;
    struct Snode *temp = (struct Snode*)malloc(sizeof(struct Snode));
    temp->data = key;
    temp->next =NULL;
    if (!curr)
    {
        *head =temp;
        return;
    }
    while(curr)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = temp;
}



void InsertCircularNode(struct Snode **head,int key)
{
    struct Snode *curr = *head;
    struct Snode *prev =NULL;
    struct Snode *temp = (struct Snode*)malloc(sizeof(struct Snode));
    temp->data = key;
    temp->next =NULL;
    if (!curr)
    {
        *head =temp;
        temp->next = *head;
        return;
    }
    while(curr->next != *head)
    {
        prev = curr;
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = *head;

}



void printCircularList(struct Snode *head)
{
    struct Snode *curr =head;

    do{
        printf(" %d ",head->data);
        head = head->next;
    } while(head != curr);
    printf("\n");

}

void printCharList(struct Snode *head)
{
    struct Snode *curr =head;

    while(head)
    {
        printf(" %c ",head->data);
        head = head->next;
    }
    printf("\n");

}

void printList(struct Snode *head)
{
    struct Snode *curr =head;

    while(head)
    {
        printf(" %d ",head->data);
        head = head->next;
    }
    printf("\n");

}
void MergeSort(struct Snode **head1,struct Snode **head2,struct Snode **head3)
{
    struct Snode dummy;
    struct Snode *curr =&dummy;
    struct Snode *temp1 = *head1;
    struct Snode *temp2 = *head2;

    while(temp1 && temp2)
    {
        if (temp1->data < temp2->data)
        {
            curr->next = temp1;
            curr = curr->next;
            temp1 = temp1->next;
        }else
        {
            curr->next = temp2;
            curr = curr->next;
            temp2 = temp2->next;
        }
    }

    if(temp1)
    {
        curr->next = temp1;
    }
    if(temp2)
    {
        curr->next = temp2;
    }
    *head1 =NULL;
    *head2 =NULL;
    *head3 =dummy.next;
}


/*Alternating split of a given Singly Linked List | Set 1 */
void alternateSplit(struct Snode **orig,struct Snode **split1,struct Snode **split2)
{
    struct Snode *curr = *orig;
    struct Snode dummy1;
    struct Snode dummy2;
    struct Snode *temp1 = &dummy1;
    struct Snode *temp2 = &dummy2;

    while(curr)
    {
        temp1->next = curr;
        temp1 = temp1->next;
        curr = curr->next;

        if (curr)
        {
            temp2->next = curr;
            temp2 = temp2->next;
            curr = curr->next;
        }
    }
    temp1->next = NULL;
    temp2->next = NULL;
    *split1 = dummy1.next;
    *split2 = dummy2.next;
    *orig = NULL;
}
/*Alternating split of a given Singly Linked List | Set 1 */

/*Intersection of two Sorted Linked Lists */

void IntersectionSortLL(struct Snode **head1,struct Snode **head2,struct Snode **head3)
{
    struct Snode dummy1;
    struct Snode *curr = &dummy1;
    struct Snode *temp1 = *head1;
    struct Snode *temp2 = *head2;
    struct Snode *tnode = NULL;


    while (temp1 && temp2)
    {
        if (temp1->data < temp2->data)
        {
            temp1 =temp1->next;
        }
        else if (temp2->data < temp1->data)
        {
            temp2 =temp2->next;
        }else
        {
            tnode = (struct Snode *)malloc(sizeof(struct Snode));
            tnode->data = temp1->data;
            curr->next = tnode;
            curr = curr->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

    }
    curr->next = NULL;
    *head3 = dummy1.next;

}
/*Intersection of two Sorted Linked Lists */

/*Split a Circular Linked List into two halves*/

void SplitCircularLL(struct Snode *head1,struct Snode **split)
{
    struct Snode *curr = NULL;
    struct Snode *slow = head1;
    struct Snode *fast = head1;
    struct Snode *first = head1;
    struct Snode *prev = NULL;
    if (head1 == NULL)
        return;

    do{
        prev =fast;
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;

    }while ((fast!= first) && (fast->next != first));


    printf("\n key %d \n",slow->data);
    curr = slow->next;
    slow->next = first;
    *split = curr;
    if (fast == first)
        prev->next = curr;
    else
        fast->next = curr;

}

/*Split a Circular Linked List into two halves*/

/*Sorted insert for circular linked list*/

void SortedInsert(struct Snode **head, int data)
{

    struct Snode *curr = *head;
    struct Snode *prev = NULL;

    struct Snode *temp = (struct Snode *)malloc(sizeof(struct Snode));
    temp->data = data;


    while(curr->next != *head)
    {
        if (curr->next->data >= data)
            break;

        prev = curr;
        curr = curr->next;
    }
    /* Node needs to be inserted before head */
    if (prev == NULL)
    {
        temp->next = (*head)->next;
        (*head)->next = temp;
        temp->data = (*head)->data;
        (*head)->data= data;
    }else{
        temp->next  = curr->next;
        curr->next = temp;
    }

}

/*Sorted insert for circular linked list*/


/** Doubly Linked List Insertion **/

void DllInsertNode(struct DNode **head,int key)
{
    struct DNode *curr = *head;
    struct DNode *prev =NULL;
    struct DNode *temp = (struct DNode*)malloc(sizeof(struct DNode));
    temp->data = key;
    temp->next = NULL;
    temp->prev = NULL;

    if (!curr)
    {
        *head =temp;
        return;
    }
    if (curr->data > key)
    {
        temp->next = *head;
        (*head)->prev = temp;
        *head =temp;
        return;
    }

    while(curr->next && curr->data < key)
    {
        curr = curr->next;
    }

    if (curr->next == NULL)
    {
        temp->prev = curr;
        curr->next = temp;
    }else{

        temp->next = curr;
        temp->prev = curr->prev;
        curr->prev = temp;
        curr->prev->next = temp;
    }

}




/** Doubly Linked List Insertion **/


/** Doubly Linked List tail Insertion **/

void DllInsertTailNode(struct DNode **head,int key)
{
    struct DNode *curr = *head;
    struct DNode *prev =NULL;
    struct DNode *temp = (struct DNode*)malloc(sizeof(struct DNode));
    temp->data = key;
    temp->next = NULL;
    temp->prev = NULL;

    if (!curr)
    {
        *head =temp;
        return;
    }

    while(curr->next )
    {
        curr = curr->next;
    }

    if (curr->next == NULL)
    {
        temp->prev = curr;
        curr->next = temp;
    }

}

/** Doubly Linked List tail Insertion **/


void printDllList(struct DNode *node)
{
    struct DNode *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}
/*Reverse a Doubly Linked List*/
void reverseDll(struct DNode **head)
{
    struct DNode *temp =NULL;
    struct DNode *curr = *head;
    struct DNode *previous =NULL;

    if (curr == NULL)
        return;

    while(curr)
    {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        previous = curr;
        curr = temp;
    }
    previous->prev = NULL;
    *head = previous;

}
/*Reverse a Doubly Linked List*/


/*Delete all occurrences of a given key in a doubly linked list*/
void DllDelDuplicateNode(struct DNode **head,int key)
{
    struct DNode *temp =NULL;
    struct DNode *curr = *head;
    struct DNode *previous =NULL;

    if (curr == NULL) return;

    while (curr)
    {
        if (curr->data == key)
        {
            temp = curr->next;

            if (temp)
                temp->prev = curr->prev;

            if (curr->prev)
                curr->prev->next = temp;

            if (*head == curr)
                *head = temp;
            free(curr);
            curr =temp;
        }else{
            curr = curr->next;
        }
    }

}

/*Delete all occurrences of a given key in a doubly linked list*/

/*Remove duplicates from a sorted doubly linked list*/
void RemoveDuplicateNode(struct DNode *head)
{
    struct DNode *temp =NULL;
    struct DNode *curr = head;
    struct DNode *previous =NULL;

    if (curr == NULL) return;

    while(curr && curr->next)
    {
        if (curr->data == curr->next->data)
        {
            temp = curr->next;
            curr->next = temp->next;
            if (temp->next)
                temp->next->prev = curr;
            free(temp);
        }else
        {
            curr = curr->next;
        }
    }

}


/*Remove duplicates from a sorted doubly linked list*/



/** Rotate a singly Linked List **/

void rotateSingleLL(struct Snode **head, int index)
{
    struct Snode *curr =*head;
    struct Snode *temp = NULL;
    int i=1;
    if (!curr)
        return;
printf("\n\n\n");
        while(curr->next && i < index)
        {
            printf(" %d ",curr->data);
            curr = curr->next;
            i++;
        }
        if (curr->next == NULL)
            return;

        temp = curr->next;
        curr->next = NULL;
        curr = temp;

        while(curr->next)
        {
            curr = curr->next;
        }
        curr->next = *head;
        *head = temp;
        printf("\n\n\n");
}

/** Rotate a singly Linked List **/

/** Insertion Sort for Singly Linked List **/
void InsertionSortSingleLL(struct Snode **head)
{
    struct Snode *curr =*head;
    struct Snode *temp = NULL;
    struct Snode dummy;
    struct Snode *start = &dummy;
    struct Snode *iter;
    struct Snode *prev;
    dummy.data = INT_MIN;
    dummy.next = NULL;
    if (!curr)
        return;

    while( curr)
    {
        temp =curr->next;
        iter = start;

        while(iter && (iter->data < curr->data))
        {
            prev = iter;
            iter = iter->next;
        }

        curr->next = prev->next;
        prev->next = curr;
        curr =temp;
    }

    *head = dummy.next;
}

/** Insertion Sort for Singly Linked List **/

/** Partitioning a linked list around a given value  **/

void partition(struct Snode **head , int x)
{
    struct Snode *curr =*head;
    struct Snode dummy;
    struct Snode *start = &dummy;
    struct Snode *end = NULL;
    struct Snode *prev = NULL;
    struct Snode *temp = NULL;

    while(curr)
    {
        temp = curr->next;
        curr->next = NULL;

        if (curr->data < x)
        {
            start->next = curr;
            start = curr;
        }
        else
        {
            curr->next = end;
            end = curr;
        }
        curr =temp;
    }
    start->next = end;

    *head = dummy.next;
}

/** Partitioning a linked list around a given value  **/

/*** Arrange consonants and vowels nodes in a linked list**/

void ConsonantVowels(struct Snode **head)
{
    struct Snode *curr =*head;
    struct Snode dummy;
    struct Snode *vowel = &dummy;
    struct Snode dummy1;
    struct Snode *cons = &dummy1;
    struct Snode *end = NULL;
    struct Snode *prev = NULL;
    struct Snode *temp = NULL;

    if (curr == NULL)
        return;

    while (curr)
    {
        if ((curr->data == 'a') || (curr->data == 'e') || (curr->data == 'i') ||
            (curr->data == 'o') || (curr->data == 'u'))
        {
            vowel->next = curr;
            vowel = curr;

        }else{

            cons->next = curr;
            cons = curr;
        }
        curr = curr->next;
    }
    cons->next = NULL;
    vowel->next = dummy1.next;
    *head = dummy.next;
}

/*** Arrange consonants and vowels nodes in a linked list**/

/*** Remove duplicates from an unsorted linked list **/
void RemoveUnsortedDuplicateNode(struct SNode *head)
{
    struct Snode *curr =head;
    struct Snode *temp = NULL;
    struct Snode *iter;
    struct Snode *prev;
    int item;
    if (curr == NULL) return;

    while(curr->next)
    {
        item = curr->data;
        prev = curr;
        iter = curr->next;
        while (iter)
        {
            if (iter->data == item)
            {
                prev->next = iter->next;
                free(iter);
                iter = prev->next;
            }
            else{
                prev = iter;
                iter = iter->next;
            }
        }
        curr = curr->next;
    }

}
/*** Remove duplicates from an unsorted linked list **/

/**Move all occurrences of an element to end in a linked list***/

void MoveAllOccurenceToEnd(struct SNode **head ,int item)
{
    struct Snode *curr = *head;
    struct Snode *temp = NULL;
    struct Snode dummy1;
       struct Snode dummy;
    struct Snode *iter = &dummy;
    struct Snode *prev = &dummy1;
    if (curr == NULL)
        return;
    dummy1.next = *head;

    while(curr)
    {
        if (curr->data == item)
        {
            temp = curr->next;
            curr->next = NULL;
            iter->next = curr;
            iter = iter->next;
            prev->next = temp;
            curr = temp;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
    prev->next = dummy.next;
    *head = dummy1.next;
}
/**Move all occurrences of an element to end in a linked list***/


/*** Remove all occurrences of duplicates from a sorted Linked List ***/
void RemoveAllduplicates(struct Snode **head)
{
    struct Snode *curr = *head;
    struct Snode dummy;
    struct Snode *prev = &dummy;
    int key;
    dummy.next = curr;

    while(curr && curr->next)
    {
        if (curr->data == curr->next->data)
        {
            key = curr->data;
            while ( curr && (curr->data == key))
            {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        }else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    *head = dummy.next;
}
/*** Remove all occurrences of duplicates from a sorted Linked List ****/

/*** Function to check if a singly linked list is palindrome ***/
int palindromeRecursive(struct Snode **left,struct Snode *right)
{
    struct Snode *curr;
    int Ispalin = 0;

    if (right == NULL)
        return 1;

    Ispalin = palindromeRecursive(left,right->next);
    curr = *left;
    if (!Ispalin)
        return 0;

    if (right->data == curr->data)
    {
        *left = curr->next;
        return 1;
    }
    else
    {
        return 0;
    }
}
/*** Function to check if a singly linked list is palindrome ***/

/*** Rearrange a linked list such that all even and odd positioned nodes are together ***/

int oddEvenArrange(struct Snode *head)
{
    struct Snode *curr = head;
    struct Snode dummy;
    struct Snode *even = &dummy;
    struct Snode *temp = NULL;
    struct Snode dummy1;
    struct Snode *odd = &dummy1;

    dummy.next = NULL;

    if (curr == NULL) return;

    while(curr)
    {
        temp = curr->next;
        odd->next = curr;
        odd = odd->next;
        curr = temp;

        if (curr)
        {
            temp = curr->next;
            even->next = curr;
            even = even->next;
            curr = temp;
        }
    }
    even->next = NULL;
    odd->next = dummy.next;
}


/*** Rearrange a linked list such that all even and odd positioned nodes are together ***/

/**Doubly Circular Linked List | Set 1 (Introduction and Insertion)**/

void DisplayCirculardouble(struct DNode *head)
{

    struct DNode *curr =head;

    if (curr == NULL)
        return;

    do {
        printf(" %d",curr->data);
        curr =curr->next;
    }while(curr != head);
        printf("\n");
}

void insertHead(struct DNode **head ,int item)
{
    struct DNode *curr =*head;
    struct DNode *temp = (struct DNode *)malloc(sizeof(struct DNode));
    struct DNode *last = NULL;

    temp->data = item;


    if (curr)
    {
        last = curr->prev;
        curr->prev = temp;
        last->next = temp;
        temp->next = curr;
        temp->prev = last;
    }else
    {
        temp->next = temp;
        temp->prev = temp;
    }

    *head = temp;
}



void insertTail(struct DNode **head ,int item)
{
    struct DNode *curr =*head;
    struct DNode *temp = (struct DNode *)malloc(sizeof(struct DNode));
    struct DNode *last = NULL;

    temp->data = item;

    if (curr)
    {
        last = curr->prev;
        temp->prev =curr->prev;
        curr->prev =temp;
        temp->next =curr;
        last->next = temp;

    }else
    {
        temp->next = temp;
        temp->prev = temp;
        *head = temp;
    }

}

void insertAfter(struct DNode *head ,int value,int item)
{
    struct DNode *curr =head;
    if (curr == NULL)
        return;

    struct DNode *temp = (struct DNode *)malloc(sizeof(struct DNode));
    struct DNode *last = NULL;
    temp->data = item;

    do
    {
        curr = curr->next;
    }while((curr != head) && (curr->data != value));

    if (curr->data != value)
        return;

    temp->next = curr->next;
    curr->next = temp;
    curr->next->prev = temp;
    temp->prev = curr;
}

void deleteNode(struct DNode **head ,int item)
{
    struct DNode *curr =*head;
    struct DNode *temp =NULL;
    if (curr == NULL)
        return;

    do
    {
        curr = curr->next;
    }while((curr != *head) && (curr->data != item));

    if (curr->data != item)
    {
        printf(" value not found \n");
        return;
    }

    temp = curr->next;
    temp->prev = curr->prev;
    curr->prev->next = temp;

    if ((*head)->data == item)
    {
        if ((*head)->next = *head)
        {
            *head = NULL;
        }else{
            *head =temp;
        }
    }
    free(curr);
    printf(" \n");

}

/**Doubly Circular Linked List | Set 1 (Introduction and Insertion)**/


/***Delete N nodes after M nodes of a linked list***/
#if 1
void deleteNafterMNode(struct Snode *head,int m , int n)
{
    struct Snode *curr =head;
    struct Snode *temp =NULL;
    struct Snode *prev =NULL;
    int i_m = 0;
    int i_n = 0;

    while(curr)
    {
        if (i_m < m)
        {
            i_m++;
            prev = curr;
            curr = curr->next;
        }else
        {

            while(curr && i_n < n)
            {
                temp = curr->next;
                prev->next = temp;
                free(curr);
                curr = temp;
                i_n++;
            }
            if (!curr)
                break;

            i_m=0;
            i_n=0;
        }
    }
}

#endif
/***Delete N nodes after M nodes of a linked list***/



/***In-place Merge two linked lists without changing links of first list***/

void InPlaceMerge(struct Snode *head,struct Snode *head1)
{
    struct Snode *list1 =head;
    struct Snode *list2 =head1;
    struct Snode *temp =NULL;
    struct Snode *prev =NULL;
    int item;
    int swap;

    while(list1 && list2)
    {
        if (list1->data > list2->data)
        {
            item = list1->data;
            list1->data = list2->data;
            list2->data = item;
            list1 = list1->next;

            temp = list2;
            while(temp && temp->next)
            {
                if (temp->data > temp->next->data)
                {
                    swap = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = swap;
                }else{
                    break;
                }
                temp = temp->next;
            }

        }else{
            list1 = list1->next;
        }
    }


}

/***In-place Merge two linked lists without changing links of first list***/


/***Pairwise swap elements of a given linked list by changing links***/
void PairwiseSwapNode(struct Snode **head)
{
    struct Snode *curr =*head;
    struct Snode  dummy;

    struct Snode *temp =&dummy;
    struct Snode *prev =temp;
    struct Snode *NextNode = NULL;

    while(curr && curr->next)
    {
        NextNode = curr->next->next;
        prev->next = curr->next;
        prev->next->next = curr;
        curr->next = NextNode;
        prev = curr;
        curr = NextNode;
    }
    *head = dummy.next;
}


/***Pairwise swap elements of a given linked list by changing links***/

int main()
{
    struct Snode *head =NULL;
    struct Snode *head1 = NULL;
    struct Snode *list1 =NULL;
    struct Snode *list2 = NULL;
    struct Snode *merge =NULL;
    struct Snode *orig = NULL;
    struct Snode *split1 =NULL;
    struct Snode *split2 = NULL;
    struct Snode *head3 = NULL;
    struct Snode *chead = NULL;
    struct Snode *chead1 = NULL;
    struct Snode *sample = NULL;
    struct Dnode *Dllhead =NULL;

    struct Dnode *Circlehead =NULL;

    struct Snode *CharHead =NULL;
    struct Snode *duphead =NULL;
    struct Snode *palin =NULL;
    int isPalinDrome = 0;
    InsertNode(&duphead,1);

    InsertNode(&duphead,2);

    InsertNode(&duphead,3);
    #if 0
    InsertNode(&duphead,4);
    InsertNode(&duphead,5);
    InsertNode(&duphead,6);
    //InsertNode(&duphead,1);
    InsertNode(&duphead,7);
    InsertNode(&duphead,8);
    InsertNode(&duphead,9);
    InsertNode(&duphead,10);
    InsertNode(&duphead,11);
    InsertNode(&duphead,12);
#endif


    InsertNode(&CharHead,'r');
    InsertNode(&CharHead,'a');
    InsertNode(&CharHead,'b');
    InsertNode(&CharHead,'c');
    InsertNode(&CharHead,'e');
    InsertNode(&CharHead,'d');
    InsertNode(&CharHead,'o');
    InsertNode(&CharHead,'x');
    InsertNode(&CharHead,'i');
    InsertNode(&CharHead,'u');
    InsertNode(&CharHead,'y');
    InsertNode(&CharHead,'n');

    InsertNode(&head,1);
    InsertNode(&head,3);
    InsertNode(&head,5);
    InsertNode(&head,7);
    InsertNode(&head,9);
    InsertNode(&head,11);
    InsertNode(&head,13);
    InsertNode(&head,15);
    InsertNode(&head1,0);
    InsertNode(&head1,2);
    InsertNode(&head1,4);
    InsertNode(&head1,6);
    InsertNode(&head1,8);
    InsertNode(&head1,10);

    InsertNode(&sample,1);
    InsertNode(&sample,2);
    InsertNode(&sample,3);
    InsertNode(&sample,4);
    InsertNode(&sample,5);
    InsertNode(&sample,6);
    InsertNode(&sample,7);
    InsertNode(&sample,8);
    InsertNode(&sample,9);
    InsertNode(&sample,10);
    InsertNode(&sample,11);
    InsertNode(&sample,12);
    InsertNode(&sample,13);
    InsertNode(&sample,14);
    InsertNode(&sample,15);
    InsertNode(&sample,16);

    InsertNode(&orig,10);
    InsertNode(&orig,20);
    InsertNode(&orig,30);
    InsertNode(&orig,40);
    InsertNode(&orig,50);
    InsertNode(&orig,6);
    InsertNode(&orig,70);
    InsertNode(&orig,8);
    InsertNode(&orig,85);
    InsertNode(&orig,100);
    InsertNode(&orig,110);
    InsertNode(&orig,120);
    InsertNode(&orig,135);



    printList(head);
    printList(head1);

    //MergeSort(&head,&head1,&merge);
    //printList(merge);
    //printf("\n======================\n");
    //printList(orig);
    //alternateSplit(&orig,&split1,&split2);
   //printList(orig);
    printf("\n<###########################>\n");
    printList(head);
    printList(orig);

    IntersectionSortLL(&head,&orig,&head3);
    printList(head3);
    printf("\n===== PRINT CIRCLULAR LIST ====== \n");
    InsertCircularNode(&chead,100);
    InsertCircularNode(&chead,200);
    InsertCircularNode(&chead,300);
    InsertCircularNode(&chead,400);
    InsertCircularNode(&chead,500);
    InsertCircularNode(&chead,600);
    InsertCircularNode(&chead,700);
    InsertCircularNode(&chead,800);
    InsertCircularNode(&chead,900);
    InsertCircularNode(&chead,1000);
    InsertCircularNode(&chead,1100);


    printCircularList(chead);

    //SplitCircularLL(chead,&chead1);
    printf ("--------");
    //printCircularList(chead); printf("\n\n");
    //printCircularList(chead1);

    SortedInsert(&chead,10);
     SortedInsert(&chead,555);

     SortedInsert(&chead,1200);
    printCircularList(chead);

    DllInsertTailNode(&Dllhead,88);
    DllInsertTailNode(&Dllhead,88);
    DllInsertTailNode(&Dllhead,88);
    DllInsertTailNode(&Dllhead,100);
    DllInsertTailNode(&Dllhead,300);
    DllInsertTailNode(&Dllhead,40);
    DllInsertTailNode(&Dllhead,40);
    DllInsertTailNode(&Dllhead,50);
    DllInsertTailNode(&Dllhead,2);
    DllInsertTailNode(&Dllhead,2000);
    DllInsertTailNode(&Dllhead,200);
    DllInsertTailNode(&Dllhead,90);
    DllInsertTailNode(&Dllhead,11);
    DllInsertTailNode(&Dllhead,11);

    //reverseDll(&Dllhead);
    printDllList(Dllhead);
   // DllDelDuplicateNode(&Dllhead,88);
    RemoveDuplicateNode(Dllhead);
    printDllList(Dllhead);

    printf ("\n^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        printList(orig);
    rotateSingleLL(&orig,4);
        printList(orig);

    printf ("\n^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    //InsertionSortSingleLL(&orig);
        printList(orig);

   // rotateSingleLL(&orig,5);
    InsertNode(&orig,111);
    InsertNode(&orig,21);
    InsertNode(&orig,50);
    InsertNode(&orig,300);
    InsertNode(&orig,40);
    InsertNode(&orig,50);
    InsertNode(&orig,40);
    InsertNode(&orig,80);
    InsertNode(&orig,17);
    InsertNode(&orig,81);
    InsertNode(&orig,81);
    InsertNode(&orig,50);

        InsertNode(&orig,40);
    InsertNode(&orig,818);
    InsertNode(&orig,11);
    InsertNode(&orig,818);
        InsertNode(&orig,40);
    InsertNode(&orig,17);
    InsertNode(&orig,21);

    printList(orig);
    printList(orig);
    printf("\n\n\n\n\n");
    //partition(&orig, 70);
   //printList(orig);
   printCharList(CharHead);

   ConsonantVowels(&CharHead);
    printCharList(CharHead);


 // RemoveUnsortedDuplicateNode(orig);
      printf("\n\n\n\n\n");

   printList(orig);

   MoveAllOccurenceToEnd(&orig,50);
    printList(orig);

    printList(duphead);
//    RemoveAllduplicates(&duphead);
    printList(duphead);
    palin = duphead;
    isPalinDrome = palindromeRecursive(&palin,duphead);
    printf (" palindrome is %d ", isPalinDrome);

    oddEvenArrange(duphead);
    printList(duphead);

    insertTail(&Circlehead,10);
    insertTail(&Circlehead,20);
    insertTail(&Circlehead,30);
    insertTail(&Circlehead,40);
    DisplayCirculardouble(Circlehead);
    insertAfter(Circlehead,30,5);
    insertAfter(Circlehead,10,11);

    DisplayCirculardouble(Circlehead);
    deleteNode(&Circlehead,10);
    DisplayCirculardouble(Circlehead);

    deleteNode(&Circlehead,11);
    deleteNode(&Circlehead,5);
    deleteNode(&Circlehead,20);
    deleteNode(&Circlehead,40);
    DisplayCirculardouble(Circlehead);
    deleteNode(&Circlehead,30);
    DisplayCirculardouble(Circlehead);

    //deleteNafterMNode(2,1);

    printList(sample);
    deleteNafterMNode(sample,2,1);
    printList(sample);


#if 0
    InsertNode(&list1,2);
    InsertNode(&list1,4);
    InsertNode(&list1,7);
    InsertNode(&list1,8);
    InsertNode(&list1,10);

    InsertNode(&list2,1);
    InsertNode(&list2,3);
    InsertNode(&list2,12);
#endif

    InsertNode(&list1,1);
    InsertNode(&list1,2);
    InsertNode(&list1,3);
    InsertNode(&list1,4);
    InsertNode(&list1,5);
    InsertNode(&list1,6);
    InsertNode(&list1,7);
    InsertNode(&list1,8);

    InsertNode(&list2,1);
    InsertNode(&list2,4);
    InsertNode(&list2,9);


#if 0
    printList(list1);
    printList(list2);
    InPlaceMerge(list1,list2);
    printList(list1);
    printList(list2);
#endif // 0
    printList(list1);
    PairwiseSwapNode(&list1);
    printList(list1);
}



