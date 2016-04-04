#include <stdio.h>

unsigned char find_rightmost_index(unsigned int num)
{
  unsigned char index =0;
  unsigned int temp =1;
  while(temp)
  {
    if (num & temp)
    {
      return index;
    }
    index++;
    temp<<=1;
  }

}

unsigned int duplicate(int *a, unsigned int size)
{
  int num1 =0,i; 
  int num2 =0;
  unsigned int dup=0;
  unsigned char index =0;
  for (i=0;i<size;i++)
  {
    dup = dup ^ a[i];
  }
  index = find_rightmost_index(dup);
 
  for (i=0;i<size;i++)
  {
      if (a[i] & (1<<index))
      {
        num1 = num1^a[i];
      }
      else
      {
        num2 = num2^a[i];
      }
  }
  printf( " num 1 %d num2 % d \n ", num1,num2);
} 

int main()
{
  int a[10] = { 23,44,65,0,1,10,10,65,44,23};
  duplicate(a,10);
}
