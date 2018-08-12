#include <stdio.h>


void printArr(int arr[],int num)
{
    int i=0;
    for (i=0;i<num;i++)
        printf("%d ",arr[i]);
}
/****Program to cyclically rotate an array by one****/

void cyclicRotateOne(int arr[],int num)
{
    int temp = arr[0];
    int index = 1;
    while(index <= num-1)
    {
        arr[index-1] = arr[index];
        index++;
    }
    arr[num-1] = temp;
    printArr(arr,num);
}


/****Program to cyclically rotate an array by one****/

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    cyclicRotateOne(arr,15);
 cyclicRotateOne(arr,15);

}
