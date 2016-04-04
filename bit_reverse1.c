#include <stdio.h>

void bitPrint(unsigned int num);

void bitReverse1(unsigned int num,int rot)
{
  
  unsigned int mask = ~(~0<<rot) ;
  
  num = (num>>rot) | ((num & mask) <<((sizeof(unsigned int)<<3) -rot));
    

  bitPrint(num);
}


void bitPrint(unsigned int num)
{
  unsigned int mask =0;
  mask = ~((~mask)>>1);
  printf( "\n %lu \n The bit reverse number is \n",mask);  
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
  bitReverse1(num,4);
}


