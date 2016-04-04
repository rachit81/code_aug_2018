#include <stdio.h>

void select(int arr[],int size)
{
  int temp =0;
  int i,j,index,min;

  for (i=0; i < size-1; i++)
  {
    min = arr[i];
    index =i;
    for (j=i+1; j < size; j++)
    {
      if (min > arr[j])
      {
        min = arr[j];
        index = j;
      }
    }
    temp = arr[i];
    arr[i] =arr[index];
    arr[index] = temp; 
  }
}

int main()
{
  int i;
  int arr[]= {56,67,23,13,19,11,10,0,1,8,8,76,9};
  select(arr,sizeof(arr)/sizeof(int));
  for (i =0; i<13;i++)
  {
    printf (" %d \t",arr[i]);
  }
  
    printf ("\n");
}
