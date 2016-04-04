#include <stdio.h>

void insert(int arr[],int size)
{
  int temp =0;
  int i,j,index,min;

  for (i=1; i < size; i++)
  {
    j = i;
    temp = arr[j];

    while((j > 0) && ( temp < arr[j-1]) )
    {
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] =temp;
  }
}

int main()
{
  int i;
  int arr[]= {56,67,23,13,19,11,10,0,1,8,8,76,9};
  insert(arr,sizeof(arr)/sizeof(int));
  for (i =0; i<13;i++)
  {
    printf (" %d \t",arr[i]);
  }
  
    printf ("\n");
}
