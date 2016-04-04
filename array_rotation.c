#include <stdio.h>

void reverse(int arr[],int start, int end)
{
    int temp;
    int i,j;
    i = start;
    j = end;
    while(i<j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void rotate_left(int arr[],int size,int rot_cnt)
{
    reverse(arr,0,size-1);
    reverse(arr,0,size-rot_cnt-1);
    reverse(arr,size-rot_cnt,size-1);
}

void rotate_right(int arr[],int size,int rot_cnt)
{
    reverse(arr,0,size-1);
    reverse(arr,0,rot_cnt-1);
    reverse(arr,rot_cnt,size-1);
}

int main()
{
    int arr[] =  {1,2,3,4,5,6,7,8,9,10,11,12};
    int arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int size = sizeof(arr)/sizeof(int);
    int i;

    rotate_right(arr,size,3);
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf(" \n");
    printf("*************************************** \n");
    printf("####################################### \n");
    rotate_left(arr1,size,3);
    for(i=0;i<size;i++)
    {
        printf("%d ",arr1[i]);
    }
    printf(" \n");

}
