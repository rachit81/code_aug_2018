/*Write a program to add one to a given number. You are not allowed to use operators like ‘+’, ‘-‘, ‘*’, ‘/’, ‘++’, ‘–‘ */

#include<stdio.h>

void bit_adder(unsigned int num)
{
    unsigned int carry =0;
    unsigned int temp =num;
    unsigned int num1 = 1;
    unsigned int sum = num;

    do{
       temp = sum ^ num1;
       carry = sum & num1;
       num1 = carry<<1;
       sum =temp;
       //printf("temp %u carry %u num1 %u\n",temp,carry,num1);
    }while(carry);

    printf(" original number %u added_num %u \n",num,temp);
}

int main()
{
    bit_adder(176);
    bit_adder(1997);
    bit_adder(40);
    bit_adder(44444);
    bit_adder(13222222);
    bit_adder(7865);
}
