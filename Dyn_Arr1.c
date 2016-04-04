#include <stdio.h>

int ** dynamic_alloc(int row,int col)
{
  int ** arr = (int *)malloc(sizeof(int *) * row );
  for ( int i =0; i< row;i++)
  {
      arr[i] = (int *)malloc(sizeof(int ) * col );
  }
  
  return arr;
}

int main()
{
  int **a;
  int row = 3;
  int cnt = 0;
  int col = 4;
  a = dynamic_alloc(3,4);
 
  for (int i =0; i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      a[i][j] =cnt++;
    }
  }


  for (int i =0; i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      printf("%d\t", a[i][j]);
    }
      printf("\n");
  }

   
}

