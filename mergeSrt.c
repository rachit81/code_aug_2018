#include <stdio.h>

void msort(int arr[],int low,int high)
{
  int mid =0;
  if (low < high)
  {
    mid = (low + high)/2;
    msort(arr,low,mid);
    msort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}


int merge(int arr[],int low,int mid,int high)
{
  int l,h,m;
  int temp[100];
  int index=0;
  l = low;
  m = mid+1;
  h = high; 
  int i;
  while((l<=mid) && (m <= high))
  {
    if (arr[l] <= arr[m])
      {
        temp[index++] = arr[l++];
      }
      else
      {
        temp[index++] = arr[m++];
      }
  }
  
  while(l <= mid)
  {
      temp[index++] = arr[l++];
  }
 

  while(m <= high)
  {
      temp[index++] = arr[m++];
  }

  for (i =0; i< index;i++)
  {
    arr[low+i] = temp[i];
  }



}
int main()
{
  int i;
  int arr[]= {56,67,23,13,19,11,10,0,1,8,8,76,9,4,89,66,48,980,101};
  qisort(arr,0,(sizeof(arr)/sizeof(int)) - 1 );
  for (i =0; i < sizeof(arr)/sizeof(int) ; i++)
  {
    printf (" %d \t",arr[i]);
  }
  
    printf ("\n");
}
