#include <stdio.h>

void qsort(int arr[],int low,int high)
{
  int pivot;
  if (low < high) 
  { 
    pivot = partition(arr,low,high);
    qsort(arr,low,pivot-1);
    qsort(arr,pivot+1,high);
  }
}

int partition(int arr[],int low, int high)
{
  int pivot =0;
  int left,right;
  int temp=0;
  left = low;
  right = high;
  pivot =arr[left];

  while (left < right)
  {
    while ( arr[left] <= pivot )
      left++;   
  
    while ( arr[right] > pivot )
      right--;
    
    if (left < right)
    {
      temp =arr[right];
      arr[right]=arr[left];
      arr[left]=temp;
    }
   
  }
  arr[low] = arr[right];
  arr[right] = pivot;  

  return right;


}
int main()
{
  int i;
  int arr[]= {56,67,23,13,19,11,10,0,1,8,8,76,9,4,89,66,48,980,101};
  qsort(arr,0,(sizeof(arr)/sizeof(int)) - 1 );
  for (i =0; i < sizeof(arr)/sizeof(int) ; i++)
  {
    printf (" %d \t",arr[i]);
  }
  
    printf ("\n");
}
