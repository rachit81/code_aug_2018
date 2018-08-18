#include <stdio.h>

/****Selection Sort****/

void selectionSort(int arr[], int n)
{
    int i=0,j=0;
    int temp;
    int min;
    int idx=0;

    for (i=0; i<n;i++)
    {
        min = arr[i];
        idx = i;
        for(j = i+1;j<n;j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                idx = j;
            }
        }
        temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
  }

  for(i=0;i<n;i++)
  {
      printf("%d ",arr[i]);
  }

}

/****Selection Sort****/

/*****Bubble Sort ****/

int bubbleSort(int arr[],int n)
{
    int i=0,j=0;
    int temp;

    for (i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {

            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

   printf("BUBBLE SORT \n ");

  for(i=0;i<n;i++)
  {
      printf("%d ",arr[i]);
  }
}

/*****Bubble Sort ****/


/*****Insertion Sort ****/

int insertionSort(int a[],int n)
{
    int i=0,j=0;
    int temp;
    for (i=1; i<n ;i++)
    {
        temp = a[i];
        for(j=i-1;j>=0;j--)
        {
            if (temp < a[j])
            {
                a[j+1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1] = temp;

    }
}
/*****Insertion Sort ****/

/***** Merge Sort ********/
int temp1[50];
int temp2[50];

int merge(int arr[],int low1,int high1, int low2,int high2)
{
    int i =0,j=0,k=0;

    for (i=0;i<high1-low1+1;i++)
    {
        temp1[i] = arr[low1+i];
    }
    for (j=0;j<high2-low2+1;j++)
    {
        temp2[j] = arr[low2+j];
    }
    i=0;j=0;k=0;

    while ((i<(high1-low1+1)) && (j < (high2-low2+1)))
    {
        if (temp1[i] < temp2[j])
        {
            arr[low1+k] = temp1[i];
            i++;
        }else
        {
            arr[low1+k] = temp2[j];
            j++;
        }
        k++;
    }
    while (i<(high1-low1+1))
    {
        arr[low1+k] = temp1[i];
        i++;k++;
    }
    while(j < (high2-low2+1))
    {
        arr[low1+k] = temp2[j];
        j++;k++;
    }
}


int MergeSort(int arr[], int low, int high)
{
    int mid = (low + high)/2;

    if (low >= high)
        return;

    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    merge(arr,low,mid,mid+1,high);

}
/***** Merge Sort ********/

/******QuickSort *********/

int partition(int arr[],int low,int high)
{
    int pivot = arr[high];
    int  temp, l, r;
    l= low;r =high-1;
    while ( l < r )
    {
        while (arr[l] < pivot)
            l++;
        if (l>=high)
            break;
        while ((arr[r] >= pivot) && (r>=low))
            r--;
        if (r < low)
            break;

         temp = arr[l];
         arr[l]= arr[r];
         arr[r] = temp;
         l++;r--;
    }
         arr[high]= arr[r];
         arr[r] = pivot;
}


int QuickSort(int arr[], int low, int high)
{

}

/******QuickSort *********/

int main()
{
    int i=0;
    int n=10;
    int arr[] = {64, 25, 12, 22, 11,98,1,6,58,99};
    //selectionSort(arr,10);
    // bubbleSort(arr,10);

  for(i=0;i<n;i++)
  {
      printf("%d ",arr[i]);
  }
  printf("\n Merge sorting...\n");
//     insertionSort(arr,10);
   // MergeSort(arr,0,9);


   partition(arr,0,9);

  for(i=0;i<n;i++)
  {
      printf("%d ",arr[i]);
  }
  //printf("%d \n",n);
}
