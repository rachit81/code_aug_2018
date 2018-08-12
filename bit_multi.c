#include <stdio.h>
unsigned int bitAdd(unsigned int num1, unsigned int num2 )
{
    unsigned int carry =0;
    unsigned int temp = num2;
    unsigned int result =0;
    unsigned int temp1= 0;
    while(temp)
    {
       if (temp & 0x1)
       {
            result = result + (num1<<cnt);
       }
        temp = temp >> 1;
        cnt++;
    }
    printf (" num 1 %u  num2 %u   result %u \n",num1,num2,result);
    return result;
}


unsigned int bitMultiply(unsigned int num1, unsigned int num2 )
{
    unsigned int cnt =0;
    unsigned int temp = num2;
    unsigned int result =0;
    unsigned int temp1= 0;
    while(temp)
    {
       if (temp & 0x1)
       {
            result = result + (num1<<cnt);
       }
        temp = temp >> 1;
        cnt++;
    }
    printf (" num 1 %u  num2 %u   result %u \n",num1,num2,result);
    return result;
}

int main()
{
    bitMultiply(765 , 789);
}
