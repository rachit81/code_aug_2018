#include <stdio.h>
unsigned int g_arr[100];

void print_arr(unsigned int *g_bit_arr,unsigned int index)
{
    unsigned int i=0;
    for (i=0;i<index;i++)
    {
        printf("%u ", g_bit_arr[i]);
    }
    printf("\n");
}

void bit_permutation(unsigned int start, unsigned int end, unsigned int* g_bit_arr )
{
    if (start == end){
        print_arr(g_bit_arr,end);
        return;
    }
    g_bit_arr[start] =0;
    bit_permutation(start+1,end,g_arr);

    g_bit_arr[start] =1;
    bit_permutation(start+1,end,g_arr);

}

int main()
{
    bit_permutation(0,3,g_arr);
}
