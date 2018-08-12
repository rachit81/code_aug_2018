#include <stdio.h>

void consecutive(unsigned int x)
{
	unsigned int num =x;
	int max_cnt =0;
	int count =0;

	while (num)
	{
		if (num & 0x1)
		count++;
		else
		count =0;
		if (max_cnt < count)
		max_cnt = count;
		
	num = num >>1;
	} 	
	printf("num is %d \n",max_cnt);
}

int main()
{

consecutive(446);

}
