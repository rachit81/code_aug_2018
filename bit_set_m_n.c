#include <stdio.h>

void set_m_n(unsigned int m, unsigned int n, unsigned int start, unsigned int end)
{

	printf( "%u \n",m);
	int num = end -start;
	unsigned int mask =(~(~0<<num))<<start;

	printf( "mask %u \n",mask);
	m = m & ~mask;
	m = m | n << start;		
	printf( "%u \n",m);
}


int main()
{
	set_m_n(1859,13,3,7);	

}
