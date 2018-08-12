#include <stdio.h>


void bitPrint(unsigned int num)
{
    unsigned int count =0;
  unsigned int mask =0;
  mask = ~((~mask)>>1);
  //printf( " %lu \n The number is \n",mask);
  while(mask !=0)
  {
    if (mask & num)
    {
      printf("1");
    }else{
      printf("0");
    }
    count++;
    if (count ==4)
    {
        printf("\t");count=0;
    }
    mask =mask>>1;
  }
      printf("\n\n");
}


void bit_swap(unsigned int num, unsigned char pos1, unsigned char pos2, unsigned char n)
{
    bitPrint(num);
    unsigned int mask = ~(~0 << n);
    unsigned int x = num >> (pos1 - n +1);
    unsigned int y = num >> (pos2 - n +1);
    unsigned int xor =0;



    x = x & mask;
    y = y & mask;

    bitPrint(x);
    bitPrint(y);

    xor = x ^ y;
  bitPrint(xor);
    num = num ^ (xor<<pos1-n+1);
    num = num ^ (xor<<pos2-n+1);

 bitPrint(num);

}

int main()
{
 unsigned int num = 99999999;
// bitPrint(num);
bit_swap(num,31,7,8);
 printf("=============================== \n\n");

 printf("\n\n");

}


