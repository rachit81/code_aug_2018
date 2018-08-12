#include<stdio.h>

void bitPrint(unsigned int num);
unsigned int left_rotate(unsigned int num , unsigned int rot)
{
	unsigned int index=0;
	unsigned int rot_num=0;
	unsigned int mask = (~0);
	mask = ~(mask>>1);
	while (index < rot)
	{
		rot_num<<=1;
		/* rot_num should be shifted initially onlyh  beacsue we don;t wanted nay shifting for first bit*/
		if (num & mask)
		{
			rot_num = rot_num | 1;
		}
				index++;
		mask>>=1;
	}
	num = num <<rot;

	//bitPrint(num);
	//printf("============================\n");
	//bitPrint(rot_num);
	//printf("============================\n");
	num = num | rot_num;
	return num;
}

unsigned int right_rotate(unsigned int num , unsigned int rot)
{
	unsigned int index=0;
	unsigned int rot_num=0;
	unsigned int mask = 1;

		unsigned int bmask = ~0;
        bmask = ~(bmask>>1);

	while (index < rot)
	{
		rot_num>>=1;
		/* rot_num should be shifted initially onlyh  beacsue we don;t wanted nay shifting for first bit*/
		if (num & mask)
		{
			rot_num = rot_num | bmask;
		}
				index++;
		mask<<=1;
	}
	num = num >>rot;

	num = num | rot_num;
	return num;
}



void bitPrint(unsigned int num)
{
  unsigned char i =0;
  unsigned int mask =0;
  mask = ~((~mask)>>1);
  printf( " %lu \n The number is \n",mask);
  while(mask !=0)
  {
	i++;

    if (mask & num)
    {
      printf("1");
    }else{
      printf("0");
    }
    if (i== 4)
	{
	printf("\t");
	i=0;
	}
    mask =mask>>1;
  }
      printf("\n\n");
}


int main()
{
	unsigned int num =3011338457;
	unsigned int rot = 0;

	bitPrint(num);
	unsigned int rotation =~0;
	rotation = rotation << ((sizeof(unsigned int)*8) -4);
//	bitPrint(rotation);

	rot = left_rotate(num,6);
	bitPrint(rot);
    printf("######################################\n\n");
    rot = right_rotate(num,6);
	bitPrint(rot);

}
