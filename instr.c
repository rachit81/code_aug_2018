#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a[100], i;
  unsigned char temp[8] = {0x1,0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8};
  int *p = NULL;
  int *all = NULL;
  int unalign;
  int div =1;


  for (i =0; i < 100; ++i) {
	  a[i] =i;
  }

  for (i =0; i < 10; ++i) {
  	printf("value: %d\n", a[i] );
  }

  for (i=1 ; i<100000000; i++)
  {
 	div = div/i; 
  }

  unalign= *((int *)(temp + 1));

  all = (int *)(temp+3);

  *all =0x555;
  printf("DIV: %d\n", div );

  return 0;
}

