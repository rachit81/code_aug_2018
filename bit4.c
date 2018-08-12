#include <stdio.h>

void consecutive_toggle(unsigned int x)
{
	unsigned int num =x;
	int max_cnt =0;
	int count =0;
	int prev_count =0;
	int tot_count =0;

	while (num)
	{
		if (num & 0x1)
		count++;
		else
		{
			if ((num & 0x2) && (prev_count ==0))
			{
				prev_count = count;
			}else
			{
				prev_count =0;
			}
			count =0;
		}

		tot_count = count+prev_count;
		if (prev_count)
			tot_count++;	
			
		if (max_cnt < (tot_count))
			max_cnt = tot_count;
		
	num = num >>1;
	} 	
	printf("num is %d \n",max_cnt);
}

int main()
{

consecutive_toggle(160);

}
