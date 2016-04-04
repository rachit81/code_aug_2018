#include <stdio.h>

void max_sum(int arr[],int size)
{
  int max =0;
  int total =0;
  for (int i=0;i < size;i++)
  {
    total+= arr[i];
    if( total <0)
      total =0;
    if (total > max)
    {
    
      max = total;
      printf ("MAX sum is %d  %d %d \n",max,i,arr[i]);
    }
  }
    printf ("======= MAX sum is %d \n\n\n",max);
}

int main()
{
  int arr[]= {-56,67,23,-23,-11,11,-19,-48,1,8,8,76,-9};
  max_sum(arr,sizeof(arr)/sizeof(int));
  for (int i =0; i<13;i++)
  {
    printf (" %d \t",arr[i]);
  }
  
    printf ("\n");
}
