#include <stdio.h>

void bit_subtract(unsigned char a , unsigned char b)
{
    unsigned char sub=0;
    unsigned char carry =0;

    while (b)
    {
            sub = a ^ b;
            carry = ~a  & b;
            carry <<=1;
            b= carry;
            a = sub;
    }
    printf ("DIFFERNECE IS %d \n ", a);
}


int main()
{
    bit_subtract(178,49);

    return 1;
}
