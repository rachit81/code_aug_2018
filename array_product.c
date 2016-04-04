#include<stdio.h>

int * arr_product(int arr[],int size)
{
    int * prod = malloc((sizeof (int)) * size);
    int i;
    int temp=1;
    for(i=0;i<size;i++)
    {
        prod[i] =temp;
        temp = temp * arr[i];
    }

    temp=1;
    for(i=size-1;i>=0;i--)
    {
        prod[i] = prod[i] *temp;
        temp = temp * arr[i];
    }
    return prod;
}

int main()
{
    int arr[] = {10, 3, 5, 6, 2};
    int size = sizeof(arr)/sizeof (int);
    int *prod;
    int i=0;

    prod = arr_product(arr,size);
    for(i=0;i<size;i++)
    {
        printf("%d ",prod[i]);
    }
    printf(" \n");
    printf("*************************************** \n");
    printf("####################################### \n");


}
