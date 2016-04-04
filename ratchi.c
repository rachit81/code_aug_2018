#include <stdio.h>
#include <stdlib.h>
/* perf stat -e cycles:u,instructions:u ./a.out */
int main()
{
volatile  int  i =1;
	while (1)
	{
		i = i++;
	}

  return 0;
}

