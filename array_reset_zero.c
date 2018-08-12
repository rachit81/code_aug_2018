#include <stdio.h>

int main()
{
    int arr[4][4] ={{1,2,0,4},{0,5,6,7},{8,9,10,11},{12,13,14,15}};
    int i=0,j=0;
    int row[4]={0};
    int col[4] ={0};

    for(i=0;i<4;i++)
    {


        for(j=0;j<4;j++)
        {
            if (arr[i][j] == 0)
            {
                row[i]=1;
                col[j]=1;
            }
            printf("%d ",arr[i][j]);
        }
        printf("\n");
     }

    for (i=0;i<4;i++)
    {


        if(row[i])
    {
           for (j=0;j<4;j++)
            arr[i][j] =0;
    }

    }

        for (i=0;i<4;i++)
    {


        if(col[i])
    {
           for (j=0;j<4;j++)
            arr[j][i] =0;
    }

    }
        printf("\n");
        printf("\n");
        printf("\n");


    for(i=0;i<4;i++)
    {


        for(j=0;j<4;j++)
        {

            printf("%d ",arr[i][j]);
        }
        printf("\n");
     }



}
