#include <stdio.h>

void bitPrint(unsigned int num);

unsigned int reverse_full(unsigned int num)
{
    unsigned int temp =0;
    unsigned int lsb = 1;
    unsigned int mask =0;
    mask = ~((~mask)>>1);
    while(mask)
    {
        if (mask & num)
        {
            temp = temp | lsb;
        }
        lsb = lsb<<1;
        mask = mask>>1;
    }
    return temp;
}

void bitReverse(unsigned int num,int rot)
{

  unsigned int mask =0;
  mask = ~((~mask)>>1);

  while(rot !=0)
  {
    if (num & 0x1)
    {
      num = num >>1;
      num = num | mask;
    }else
    {
      num = num >>1;
    }
    rot--;
  }

  bitPrint(num);
}


void bitPrint(unsigned int num)
{
  unsigned int mask =0;
  mask = ~((~mask)>>1);
  printf( "\n %lu \n The number is \n",mask);
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
  unsigned int num = 1997;
  bitPrint(num);
  //bitReverse(num,4);
  bitPrint(reverse_full(num));
}


