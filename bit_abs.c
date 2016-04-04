#include <stdio.h>

int main()
{
 int num = -765990;
 int mask = num>>31;
 
 printf("The original number is %d \n\n",num);
  num = (num^mask)-mask; 
 printf("The absolute value ofnumber is %d \n\n",num);
 printf("=============================== \n\n");


 printf("=============================== \n\n");
 printf("\n\n");

}


