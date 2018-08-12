#include<stdio.h>

/****Median of two sorted arrays of same size*****/

void median(int arr1[],int arr2[],int m)
{
    int i=0,j=0,k=0;
    int median =0;

    for (i=0;i<m-1;i++)
    {
        if (arr1[j] < arr2[k])
        {
            j++;
        }else
        {
            k++;
        }
    }
        if (arr1[j] < arr2[k])
        {
            median = median + arr1[j];
            j++;
        }else
        {
            median = median + arr2[k];
            k++;
        }
        if (arr1[j] < arr2[k])
        {
            median = median + arr1[j];
            j++;
        }else
        {
            median = median + arr2[k];
            k++;
        }

        median = median/2;
    printf("The median is %d \n",median);
}

/****Median of two sorted arrays of same size*****/




/*******Check if there exist two elements in an array whose sum is equal to the sum of rest of the array******/

void sumEqualsRest(int arr[],int n)
{
    int i =0;
    int max = arr[0];
    int sum =0;
    for (i=0;i<n;i++)
    {
        if (arr[i] > max)
            max = arr[i];
        sum = sum+arr[i];
    }
    sum = sum - max;

    for (i=0;i<n;i++)
    {
        if ((max + arr[i]) == (sum -arr[i]))
        {

            break;

        }

    }
    if (i == n)
        printf("SUM IS NOT THERE \n");
    else
         printf("SUM IS THERE %d %d \n",max,arr[i]);

}

/*******Check if there exist two elements in an array whose sum is equal to the sum of rest of the array******/

/*****Count 1’s in a sorted binary array****/

int  count1s(int arr[],int num)
{
    int index, mid,low=0,high=num;

    while(low<high)
    {
        mid = (low+high)/2;
        if ((arr[mid] == 1) && ((mid+1 == num) || (arr[mid+1]  == 0)))
            {
                return mid +1;
            }
        if ((arr[mid] == 0) && ((mid == 0) || (arr[mid-1]  == 1)))
        {
                return mid;
        }
        if (arr[mid] == 0)
        {
            high = mid-1;
        }else
        {
            low = mid+1;
        }

    }
}

/*****Count 1’s in a sorted binary array****/

/*******Ceiling in a sorted array****/

void ceiling (int arr[],int n,int x)
{
    int i=0;
    int low =0;
    int mid;
    int high = n-1;
    if (x < arr[0])
    {
        printf("The ceiling is %d \n ",arr[0]);
        return;
    }
    if (x > arr[n-1])
    {
         printf("NO CELING IN THIS ARRAY \n ");
         return;
    }
    while (low < high)
    {
        mid = (low+high)/2;
        if ((x >arr[mid]) &&  (x < arr[mid+1]))
        {
            printf("The ceiling is %d --\n ",arr[mid+1]);
            return;
        }
        if ((x < arr[mid]) &&  (x > arr[mid-1]))
        {
            printf("The ceiling is %d \n ",arr[mid]);
            return;
        }
        if ((x >arr[mid]) )
        {
            low = mid+1;
        }
        else if ((x < arr[mid]))
        {
            high = mid-1;
        }
    }
}

/*******Ceiling in a sorted array****/


int main()
{
    int num =0;
    int arr[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    //int arr[] = {1,1,1,1,1,1,1,1,1,1,0,0,0,0};
    int arr1[] = {1, 2, 5, 9, 38};
    int arr2[] = {2, 3, 11, 30, 45};
    int arr3[] = {2, 11, 5, 1, 4, 7};
    int arr5[] = {1, 2, 8, 10, 10, 12, 19};


    num = count1s(arr,14);
    printf("count 1s %d \n",num);

    median(arr1,arr2,5);
    sumEqualsRest(arr3,6);
    ceiling(arr5,7,5);
    return 0;
}
