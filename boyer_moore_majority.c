#include <stdio.h>

int majority(int arr[],int size)
{
    int cnt=0;
    int cand;
    int i=0;
    for (i=0;i<size;i++)
    {
        if (cnt ==0 )
        {
            cand =arr[i];
            cnt++;
        }else{
            if (cand == arr[i])
                cnt++;
            else
                cnt--;
        }
    }
    cnt =0;
    for (i=0;i<size;i++)
    {
        if (cand == arr[i])
        {
            cnt++;
            printf(" i %d  cnt %d \n",i,cnt);
        }
    }
    //printf("cnt %d size %d \n", cnt,size);
    if (cnt >= (size+1)/2)
    return cand;
    else
    return -1;
}
int main()
{
    #if 0
    int arr[] = {1,2,1,3,1,2,1,4,1,2,1,1,1,1,2,2,2,2,3,2,2,2,2,3};
    #endif // 0

    int arr[] = {1,2,1,3,1,2,1,2,1,3,1,1};

    int major;
    major = majority(arr,sizeof(arr)/sizeof(int));
    printf("major element is %d \n", major);
    return 0;
}
