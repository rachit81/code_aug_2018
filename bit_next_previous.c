/*Next Number: Given a positive integer, print the next smallest and the next largest number that
have the same number of 1 bits in their binary representation.*/

#include <stdio.h>

unsigned int count(unsigned int num)
{
  unsigned int cnt =0;
  while( num !=0)
  {
    if(num & 0x1)
    {
      cnt++;
    }
    num>>=1;
  }
  return cnt;
}

void bitPrint(unsigned int num)
{
  unsigned int mask =0;
  mask = ~((~mask)>>1);
  while(mask !=0)
  {
    if (mask & num)
    {
      printf("1");
    }else{
      printf("0");
    }
    mask =mask>>1;
  }
      printf("\n\n");
}


unsigned int brute_force(unsigned int n)
{
    unsigned int cnt =0;
    unsigned int temp = n;
    cnt = count(n);
    bitPrint(n);

    temp++;
    while (cnt != count(temp))
        temp++;

    bitPrint(temp);
#if 0
printf("===============================\n");
    temp = n;
    temp--;
    while (cnt != count(temp))
        temp--;

    bitPrint(temp);
 #endif // 0

    printf("temp %d \n",temp);


    return temp;
}

int bitGetNxt(unsigned int n)
{
    unsigned int msb = 0;
    unsigned int num =n;
    unsigned int mask =0x3;
    unsigned int count_0 =0;
    unsigned int count_1 =0;
    msb = ~(~0 >>1);
    printf(" bitGetNxt \n");
    if ((msb & n)|| (n == ~0) || (n == 0))
    {
        printf("MSB set in the number or all zero or all 1 \n ");
        return 0;
    }


    while(((num & 0x1) == 0) && (num !=0))
    {
        count_0++;
        num = num >>1;
    }

    while((num & 0x1) == 1)
    {
        count_1++;
        num = num >>1;
    }
    num = n;
    mask = 1 << (count_0 + count_1);


    num = num | mask;

    mask = ~(mask-1);
    num = num & mask;


    if (count_1)
        count_1--;


    mask = ~(~0 << count_1);
    num = num | mask;

    return num;

}



int bitGetPrev(unsigned int n)
{
    unsigned int lsb = 0;
    unsigned int num =n;
    unsigned int mask =0x3;
    unsigned int count_0 =0;
    unsigned int count_1 =0;
    lsb = ~(~0 >>1);
    printf(" bitGetPrev \n");

    if ((n == ~0))
    {
        printf("LSB set in the number  or all 1 or all zero\n ");
        return 0;
    }


    while((num & 0x1) == 1)
    {
        count_1++;
        num = num >>1;
    }
    if (num == 0)
        return 0;

    while(((num & 0x1) == 0) && (num !=0))
    {
        count_0++;
        num = num >>1;
    }

    num = n;
    mask = 1 << (count_0 + count_1);


    num = num & ~mask;

    mask = ~(mask-1);
    num = num & mask;

    count_1++;

    mask = ~(~0 << count_1);
    mask = mask << (count_0 -1);
    num = num | mask;

    return num;

}



int main()
{
    int next =0;
    brute_force(739);
    next = bitGetNxt(739);

    printf(" nxt greatet number is %d \n",next);
}
