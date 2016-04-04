#include <stdio.h>


void sortM(int M[],int N[],int msize,int nsize)
{
    int j=msize-1;
    int k =nsize-1;
    int index = msize+nsize -1;

    while(index>0)
    {
        if (M[j] > N[k])
            {
                M[index] = M[j];
                j--;
            }
             else
            {
                M[index] = N[k];
                k--;

             }
            index--;
    }

}

int main()
{
  int M[10] = {2, 8, 13,15, 20,35};
  int N[4] = {5, 7, 9, 25};
int i;
  sortM(M,N,6,4);
  for(i=0;i<10;i++)
  {
      printf("%d ",M[i]);
  }
        printf("\n\n");
}
