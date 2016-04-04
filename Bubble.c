#include <stdio.h>

void bubble(int arr[],int size)
{
  int temp =0;
  int i,j;

  for (i = size-1; i > 0; i--)
  {
    for (j=0; j < i; j++)
    {
      if(arr[j] > arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main()
{
  int i;
  int arr[]= {56,67,23,13,19,11,10,0,1,8,8,76,9};
  bubble(arr,sizeof(arr)/sizeof(int));
  for (i =0; i<13;i++)
  {
    printf (" %d \t",arr[i]);
  }
  
    printf ("\n");
}
