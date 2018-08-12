#include <stdio.h>

void bitPrint(unsigned int num);

void bittoggle(unsigned int num)
{
unsigned int temp = num;
  unsigned int mask =0;
  mask = ~mask;

  while(temp)
  {
    temp = temp >>1;
    mask = mask <<1;
  }
   mask = ~mask;
   temp = num ^ mask;
  bitPrint(num);

  bitPrint(temp);
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
  unsigned int num = 50;
 // bitPrint(num);
  bittoggle(num);
}


