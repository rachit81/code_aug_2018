#include <stdio.h>

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

void bitmsb(unsigned int num)
{
  int count =0;
  if (num & 0xffff0000) {
    count+=16;
    num = num >>16; 
  }

  if (num & 0xff00) {
    count+=8;
    num = num >>8; 
  }
  
  if (num & 0xff) {
    count+=4;
    num = num >>4; 
  }

  if (num & 0xc) {
    count+=2;
    num = num >>2; 
  }


  if (num & 0x1) {
    count+=1;
  }
  
 printf("count is %d  \n\n",count);
}

int main()
{
 unsigned int num = 99999999;
 bitPrint(num);
 bitmsb(num);
 printf("=============================== \n\n");
 printf("\n\n");

}


