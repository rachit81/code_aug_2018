
#include <stdio.h>
/*
Flip Bit to Win: You have an integer and you can flip exactly one bit from a O to a 1. Write code to
find the length of the longest sequence of 1 s you could create.
EXAMPLE
Input: 1775 (or: 11011101111)
Output: 8

*/


unsigned int flip_bit(unsigned int n)
{
    unsigned int mask = 0x1;
    unsigned int curr_count =0;
    unsigned int prev_count =0;
    unsigned int max_count =0;

    while(n)
    {
        if (mask & n)
        {
            curr_count++;
        }
        else{
            if (n & 0x2)
            {
                prev_count = curr_count+1;
            }else {
                prev_count = 0;
            }
             curr_count=0;
        }


        if (max_count < (curr_count + prev_count) )
        {
            max_count = curr_count + prev_count;
        }


        n =n>>1;
    }
    return max_count;
}



int main()
{
    unsigned int max =0;
    max = flip_bit(17625);

    printf("max number of bits set %d \n",max);

}
