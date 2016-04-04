#include <stdio.h>

void bubble(int arr[],int size)
{
  int temp =0;
  for (int i=1;i < size;i++)
  {
    for (int j=i;j<size;j++)
    {
      if(arr[i-1] < arr[j])
      {
        temp = arr[i-1];
        arr[i-1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main()
{
  int arr[]= {56,67,23,13,19,11,10,0,1,8,8,76,9};
  bubble(arr,sizeof(arr)/sizeof(int));
  for (int i =0; i<13;i++)
  {
    printf (" %d \t",arr[i]);
  }
  
    printf ("\n");
}
