#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"
#define SUCCESS 1
#define FAILURE 0
struct hashTable *gHashTable =NULL;

void createHashTable(int size)
{
  int i =0;
  gHashTable = (struct hashTable*) malloc(sizeof(struct hashTable));
  if (gHashTable == NULL)
  {
    printf(" MEMORY ALLOCATION FAILURE"); 
    return;
  }
  gHashTable->size = size;
  gHashTable->closeHashTable  = (struct hashNode *)malloc(sizeof(struct hashNode) * size); 
  for(i =0; i < size; i++)
  {
    gHashTable->closeHashTable[i].next = NULL;
    gHashTable->closeHashTable[i].element = -1;
  }   
}

struct hashNode* find(int num)
{

  int key = hash(num);
  struct hashNode *hnode = NULL;
  hnode = gHashTable->closeHashTable[key].next;
  while (hnode != NULL)
  {
    if (hnode->element == num)
    {
      return hnode;
    }
    hnode = hnode->next;
  }
  return NULL;
}

unsigned char insert( int num)
{
  int key = hash(num);
  
  struct hashNode * hnode =NULL;
  hnode = (struct hashNode*) malloc(sizeof(struct hashNode));
  if (hnode == NULL)
    return FAILURE;
  hnode->element = num;
     
  hnode->next = gHashTable->closeHashTable[key].next;
  gHashTable->closeHashTable[key].next = hnode;
  return SUCCESS;
}
unsigned char delete (int num)
{
  int key = hash(num);
  struct hashNode *hnode = NULL;
  struct hashNode *prev = NULL;
  hnode = gHashTable->closeHashTable[key].next;
  prev  = &(gHashTable->closeHashTable[key]);
  
  while (hnode != NULL)
  {
    if (hnode->element == num)
    {
      prev->next = hnode->next;
      free(hnode);
      return SUCCESS;
    }  
    prev =hnode;
    hnode=hnode->next; 
  }    
  return FAILURE;
}

int hash(int num)
{
  int hashKey =0;
  while (num !=0)
  {
    hashKey = hashKey * 47 + ( num%10);
    num = num/10;
    //printf(" hashkey %d num %d \n" , hashKey,num);
  }  
  return (hashKey & 0x1f);
}


void print_hash_table()
{
  int i =0;
  for(i =0; i < gHashTable->size; i++)
  {
    struct hashNode * hnode = gHashTable->closeHashTable[i].next; 
    printf("HASH KEY ---- %d \n",i);
    while(hnode != NULL)
    {
      printf("%d \t",hnode->element);
      hnode = hnode->next;
    }
    printf("\n");
  }
}



int main()
{

  createHashTable(32);
  insert(99899889);
  insert(88);
  insert(123);
  insert(456);
  insert(980);
  insert(0);
  insert(4);
  insert(127);
  insert(128);
  insert(45);
  insert(45006);

  if (find(34))
    {
      printf (" hash key 34 found");
    }else
    { 
      printf (" hash key 34 NOT found .....\n ");
    }
   print_hash_table();

  if (find(45006))
    {
      printf (" hash key 45006 found\n ");
    }else
    {
      printf (" hash key 45006 not  found\n");
    } 

  if (find(99899889))
    {
      printf (" hash key 99899889 found\n ");
    }else
    {
      printf (" hash key 99899889 not  found\n");
    }
    delete(99899889);


  if (find(99899889))
    {
      printf (" hash key 99899889 found\n ");
    }else
    {
      printf (" hash key 99899889 not  found\n");
    }

 
}
