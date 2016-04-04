#include <stdio.h>


void RecursiveBitPrint(unsigned int num)
{
  if (num ==0) {
    printf("0");
    return;
  }
  if ( num & 0x1)
  {
    RecursiveBitPrint(num>>1);
    printf("1");
  } else{
    RecursiveBitPrint(num>>1);
    printf("0");
  }
 
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
 unsigned int num = 99999999;
 bitPrint(num);

 printf("=============================== \n\n");
 RecursiveBitPrint(num);
 printf("\n\n");

}


