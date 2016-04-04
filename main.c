#include <stdio.h>
#include <stdlib.h>

int main ()
{

printf("HEELO WORLD");

}


#if 0

int func(int fun)
{


  	printf("Func ------ %d\n", fun );
}


int main()
{
  int a[100], i;
  unsigned char temp[8] = {0x1,0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8};
  int *p = NULL;
  int *all = NULL;
  int unalign;

  for (i =0; i < 100; ++i) {
	  a[i] =i;
  }

  for (i =0; i < 10; ++i) {
  	printf("value: %d\n", a[i] );
	//sleep(1);
	func(a[i]);
        p =(int *)malloc(sizeof(8000));	
  }

  p =(int *) malloc(sizeof(int));
  *p=500;
  free(p);

  printf("address: %p\n", temp );
  unalign= *((int *)(temp + 1));

  all = (int *)(temp+3);

  *all =0x555;

  return 0;
}

#endif
