#include <stdio.h>

int main()
{
int arr[] = {0,4,0,1,4,5,3,3,3}; 
int i=0;
int temp=0;
  
  for (i=0;i<9;i++)
  {
    if (arr[i] != i &&  arr[i] == arr[arr[i]])
    printf ( "duplicate number found index  %d  number %d \n",i,arr[i]);
    else
    {
      temp = arr[i];
      arr[i] = arr[temp];
      arr[temp] =temp;

    }
  } 
  
}

