#include <stdio.h>

void palindrome(unsigned int num)
{

  unsigned int msb =0;
  unsigned int lsb =1;
  msb = ~((~msb)>>1);
  
  while (msb != 0 )
  {
    if ( !(msb & num) != !(lsb &num))
    {
      printf( "\n The number is  not a palidrome \n");  
      break;
    } 
    msb = msb>>1;
    lsb = lsb<<1;

  }

  if (msb == 0)
      printf( "\n The number is palidrome YIPEE !!!!! :-) \n");  
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
 //unsigned int num = 3003121869;
 unsigned int num = 73;
 bitPrint(num);

 printf("=============================== \n\n");
 palindrome(num);
 printf("\n\n");

}


