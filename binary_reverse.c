#include <stdio.h>


unsigned int bin_reverse(unsigned int num)
{
    unsigned int reverse =0;
    unsigned int mask1 = ~0;
    unsigned int mask2 = 1;
    mask1 = ~(mask1>>1);

    while(mask1)

    {
        if (num & mask1)
        {
            reverse = reverse | mask2;
        }
        mask1>>=1;
        mask2<<=1;
    }
    return reverse;
}
void bitPrint(unsigned int num)
{
  unsigned int mask =0;
  mask = ~((~mask)>>1);
  printf( " %lu \n The number is \n",mask);
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

int main()
{
        unsigned int num = 9878;
        unsigned int reverse = 0;
        reverse = bin_reverse(num);
    bitPrint(num);
    bitPrint(reverse);
}
