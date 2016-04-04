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

int main()
{
  unsigned int num =1000;
  printf (" number of setbits in %u is %u\n",10001,count(10001));
  printf (" number of setbits in %u is %u\n",63,count(63));
  printf (" number of setbits in %u is %u\n",128,count(128));
  printf (" number of setbits in %u is %u\n",4294967295,count(4294967295));
}
