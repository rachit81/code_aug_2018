#include <stdio.h>

void consecutive(unsigned int x)
{
	unsigned int num =1;
	unsigned int max_cnt =0;
	unsigned int count =0;
	unsigned int mask =0;
	unsigned int start =1;
    sunsigned int start =1;

	printf("x is %d \n",x);
//	num = x & x-1;
//	num = num ^ x;
	mask = num;
	start = num;

	while(start)
	{
	    init =start;
	    flag =1;
	    mask =1;
	    while (flag){

         mask =mask <<1 | init;
         mask_2 = ~(x & mask);

		if ((mask & x) == mask)
		{
			count++;
			mask = mask <<1 | num;
			printf("count increment is %d %u \n",count,mask);
		}else
		{
			count =0;
			num = start;
			mask = start;
		}

		if (max_cnt < count )
			max_cnt = count;
		start = start <<1;

	}
	printf("num is %d \n",max_cnt);
}

int main()
{

consecutive(649);

}
