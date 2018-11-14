#include <stdio.h>


void printArr(int arr[],int num)
{
    int i=0;
    for (i=0;i<num;i++)
        printf("%d ",arr[i]);
    printf("\n\n\n");
}


int getMinRotateArr(int arr[],int num)
{
	int mid=0,low=0,high=num-1;
	int min;
	if ((arr[low] < arr[high]) || (num == 1))
		return low;

	while (low < high)
	{
		mid = (low + high)/2;
		min = arr[mid];
		if (((min < arr[mid+1]) && (min < arr[mid-1])) || (low == high))
		{
			break;
		}
		 		
		
		if (arr[low] > arr[mid])
		{
			high = mid;
		}else if (arr[mid] > arr[high])
		{
			low = mid;
		}
	

	}
	return min;
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


/***Rearrange an array such that arr[i] = i ***/

int rearrange(int arr[],int num)
{
	int i =0;
	int j=0;
	int temp;
	int val;
	while (i <num)
	{
		if ((arr[i] == -1) || (arr[i] == i))
			i++;

		j=i;
		while (j< num)
		{
			if ((arr[j] == -1) || (arr[j] == j))
				break;

			temp = arr[j];
			val = arr[temp];
			arr[temp] = temp;
			arr[j] = val;				
		

		}

	}


}

/***Rearrange an array such that arr[i] = i ***/



/*****Segregate even and odd numbers *****/

int sepOddEven(int arr[],int num)
{
	int i =0 ,j=0;
	int temp;
    while(i< num)
	{
		if ((arr[i] % 2) == 0)
		{
			i++;
		}else
		{
			j= i+1;
			while(j<num)
			{
				if ((arr[j] % 2) == 0)
					break;
				j++;
			}
			if (j >= num)
				break;
			temp =arr[i];
			arr[i] = arr[j];
			arr[j]= temp;
			i++;
		}		
		
	}		


}


/*****Segregate even and odd numbers *****/

/*****Move all zeroes to end of array (Using single traversal)****/

void movezeroend(int arr[],int num)
{

	int i =0 , j=0;
	int temp =0;
	while (j < num)
	{
		if (arr[j] != 0)
		{
			temp = arr[j];		
			arr[j] = arr[i];		
			arr[i] = temp;
			i++;	
		}
		j++;

	}

}

/*****Move all zeroes to end of array (Using single traversal)****/
/*****Reorder an array according to given indexes******/

void reorderArrIdx(int arr[],int index[],int num)
{

	int i=0,j=0,temp,tmp_idx1,tmp_idx2;
	for (i=0;i<num;i++)
	{
		while(index[i] != i)
		{
			tmp_idx1 = index[i];	
			tmp_idx2 = index[tmp_idx1];	
			index[i] = tmp_idx2;	
			index[tmp_idx1] = tmp_idx1;	

			temp = arr[i];
			arr[i] = arr[tmp_idx1]; 
			arr[tmp_idx1] = temp; 

		}
		

	}	



}

/*****Reorder an array according to given indexes******/

/***** Print left rotation of array in O(n) time and O(1) space******/

void printLeftRot(int arr[],int num, int rot)
{
	int i=0;
	int start = rot%num;	

	for (i=0;i<num;i++)
	{
		
		printf("%d ",arr[start]);
		start++;
		if (start >=num)
			start = 0;

	}

	printf ("\n========\n");

}


/***** Print left rotation of array in O(n) time and O(1) space******/

/**** Find the minimum element in a sorted and rotated array****/ 

void minSortedRotatedArr(int arr[],int num)
{
	int mid,l=0,r=num;
	if (arr[0] < arr[num-1])
	{  
		printf("base case  minimum %d index %d",arr[mid],mid);
		return;	
	 }

   while (l<=r) 
   {

	mid = (l + r)/2;
	
	if (arr[mid] < arr[mid-1])
	 {
	   printf("minimum %d index %d",arr[mid],mid);
		return;	
	 }
	 if (arr[l] > arr[mid])
	 	r = mid;
	 else
		l = mid;
	
	}


}



/**** Find the minimum element in a sorted and rotated array****/ 

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int min;
	int array[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    cyclicRotateOne(arr,15);
    cyclicRotateOne(arr,15);
    cyclicRotateOne(arr,15);
    cyclicRotateOne(arr,15);
    int arr1[] = { 2,3,1};
    int aoddEve[] = { 1, 3, 2, 4, 7, 6, 9, 10 }; 
	int zero[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};

    int minarr[] =  {5, 6, 7, 8, 9, 10, 1, 2, 3, 4}; 
    int minarr1[] =  {0, 5 , 6, 7, 8 ,9, 10, -5}; 


    int order[] = {50, 40, 70, 60, 90}; 
    int index[] = {3,  0,  4,  1,  2};
	int rot[] = {1, 3, 5, 7, 9};
 	
//	min = getMinRotateArr(arr1,3);
	printf("\n minimum in the array --> %d \n",min);

	rearrange(array,10);
    printArr(array,10);
	sepOddEven(aoddEve,8);
    printArr(aoddEve,8);
    movezeroend(zero,13);
    printArr(zero,13);


	reorderArrIdx(order,index,5);

    printArr(order,5);
	printLeftRot(rot,5,6);

	minSortedRotatedArr(minarr1,8);
}
