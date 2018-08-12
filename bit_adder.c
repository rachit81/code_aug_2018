#include <stdio.h>

void bit_add(unsigned char a , unsigned char b)
{
    unsigned char sum=0;
    unsigned char carry =0;

    while (b)
    {
            sum = a ^ b;
            carry = a  & b;
            carry <<=1;
            b= carry;
            a = sum;
    }
    printf ("SUM IS %d \n ", a);
}

void bit_add_signed( char a ,  char b)
{
    char sum=0;
    char carry =0;

    while (b)
    {
            sum = a ^ b;
            carry = a  & b;
            carry <<=1;
            b= carry;
            a = sum;
    }
    printf ("SUM IS %d \n ", a);
}

int main()
{
    bit_add_signed(-178,255);

    return 1;
}
