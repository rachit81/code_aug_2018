#include <stdio.h>
#include <limits.h>

typedef struct heap{
  int size;
  int capacity;
  int *harr;  
} heap;

heap * createheap(int capacity)
{
 heap *mheap = (heap *) malloc( sizeof ( heap));
 mheap->capacity = capacity;
 mheap->size = 0;
 mheap->harr = (int *) malloc(sizeof(int)* capacity);
 mheap->harr[0] = INT_MIN;
 return mheap; 

} 
void insert( heap *mheap, int num)
{
  int index =0;
  mheap->size++;
  index =  mheap->size;
  while ( num < mheap->harr[index/2])
  {
     mheap->harr[index] = mheap->harr[index/2];
     index = index/2;
  }
   
  mheap->harr[index] = num;
}

int delete( heap *mheap)
{
  int num;
  int index = 1;
  int nindex ;
  num = mheap->harr[index];
  while( index  <= mheap->size)
  {
    
    nindex = index *2;
 
   if ((nindex > mheap->size) || ((nindex +1) > mheap->size))
      break;

    if ((mheap->harr[nindex] > mheap->harr[nindex+1]))       { 
      nindex++;
    }
    mheap->harr[index] = mheap->harr[nindex];
    index = nindex;
  } 
  mheap->harr[index] = mheap->harr[mheap->size];
  mheap->size--;
  return num;
}

int main()
{
  int i;
  int arr[]= {56,67,23,13,19,11,10,0,1,8,8,76,9,4,89,66};
  heap *mheap = createheap(50);  
     
  for (i =0; i < sizeof(arr)/sizeof(int) ; i++)
  {
    insert(mheap,arr[i]);
  }


  for (i =0; i < sizeof(arr)/sizeof(int) ; i++)
  {
    printf (" %d \t",mheap->harr[i]);
  }

    printf ("############################################# \n\t");
  for (i =0; i < sizeof(arr)/sizeof(int) ; i++)
  {
    printf (" %d \t",delete(mheap));
  }

    printf ("============================================= \n\t");
  for (i =0; i < sizeof(arr)/sizeof(int) ; i++)
  {
    printf (" %d \t",arr[i]);
  }
  
    printf ("\n");
}
