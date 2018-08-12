#include <stdio.h>
#include <stdlib.h>
#include  <limits.h>


/*** Binary representation of a given number**/

void bit_print(unsigned int n)
{
    unsigned int mask = 0;
    int count =0;
    mask = ~((~mask) >> 1);

    while(mask)
    {
        count++;
        if (mask & n)
        {
            printf("1");
        }else{
            printf("0");
        }
        if (count == 4){
            printf("\t");
            count =0;
            }
        mask>>=1;
    }
    printf("\n");
}


/*** Binary representation of a given number**/


/*** Add 1 to a given number**/

void bit_add(unsigned int n , unsigned int m)
{
    unsigned int carry = 0;
    unsigned int sum = 0;





}
/*** Add 1 to a given number**/

/*** Rotate bits of a number**/

void rightRotate(unsigned int num, unsigned int rot)
{
    unsigned int mask = (1<<rot)-1;
    int size = sizeof(unsigned int)*8;
    bit_print(num);
    num = ((num >> rot) | ((num & mask)<< (size - rot)));
    bit_print(num);

}


void leftRotate(unsigned int num, unsigned int rot)
{
    unsigned int mask = ~((~0)>>1);

    int size = sizeof(unsigned int)*8;
    mask = (mask>>rot)-1;
    bit_print(num);
    num = ((num << rot) | ((num & mask) >> (size - rot)));
    bit_print(num);

}

/*** Rotate bits of a number**/

/*** Position of rightmost set bit **/

void rightmostSetBit(unsigned int num)
{
    int mask = num ^ (num & (num-1));
    bit_print(num);
    bit_print(mask);
    int count =0;
    while(mask)
    {
        mask = mask >>1;
        count++;
    }
    printf("%d",count);
}
/*** Position of rightmost set bit **/

/***Toggle bits in the given range***/

void toggleBit(unsigned int num , unsigned int start, unsigned int end)
{
    unsigned int mask = (1<< ((end - start) + 1)) - 1;
    mask = mask << start;

    printf("number before toggling\n");
    bit_print(num);
    num = num ^ mask;
    printf("number AFTER toggling\n");
    bit_print(num);


}
/***Toggle bits in the given range***/

/***Unset bits in the given range****/
void unsetBit(unsigned int num , unsigned int start, unsigned int end)
{
    unsigned int mask1 = (1 << start)-1;
    unsigned int mask2 = (1 << end)-1;
    unsigned int mask = ~(mask1 ^ mask2);

    printf("number before unset \n");
    bit_print(num);
    num = num & mask;
    printf("number AFTER unset \n");
    bit_print(num);



}
/***Unset bits in the given range****/

/*****Toggle case of a string using Bitwise operators*****/

void toggleString(char *str)
{
    int i =0;

    while(str[i])
    {
        if (str[i] != ' ')
            str[i] = (str[i]) ^ (1<<5);
        i++;
    }
}

/*****Toggle case of a string using Bitwise operators*****/

/****Check if a number has bits in alternate pattern ***/

void alternateBit(unsigned int num)
{


}

/****Check if a number has bits in alternate pattern ***/


/****Add two numbers without using arithmetic operators****/

int ADD_BIT(int x,  int y)
{
    int sum =0;
    int carry =0;
    printf("x = %d y =%d",x,y);

    while(y)
    {
        sum = x ^ y;
        carry = x & y;
        x= sum;
        y = carry<<1;
    }
    printf("x = %d y =%d  sum = %d ",x,y,sum);
    return sum;
}




/****Add two numbers without using arithmetic operators****/


/****Check if binary representation of a number is palindrome *****/

void bit_palindrome(unsigned int num)
{
    unsigned int msb = ~0;
    unsigned int lsb = 1;
    int isPalin = 1;
    msb = ~(msb>>1);
    bit_print(msb);
    while (msb > lsb)
    {
        if (!(msb & num) != !(lsb & num))
        {
            isPalin = 0;
            break;
        }
        msb>>=1;
        lsb<<=1;
    }

    bit_print(num);

    if (isPalin)
    {
        printf(" \n the number is palndrome \n");
    }else{
        printf(" \n the number is not a palndrome \n");
    }
}


/****Check if binary representation of a number is palindrome *****/


/****Write an Efficient C Program to Reverse Bits of a Number***/
void bit_reverse(unsigned int num)
{
    unsigned int reverse = 0;
    unsigned int msb = ~0;
    unsigned int lsb = 1;
    msb = ~(msb>>1);
    bit_print(msb);

    while(msb)
    {
        if (msb & num)
        {
            reverse = reverse | lsb;
        }
        lsb<<=1;
        msb>>=1;
    }

    printf(" The oiginal number %u \n",num);
    bit_print(num);
    printf(" The reversed number %u \n",reverse);
    bit_print(reverse);
}


/****Write an Efficient C Program to Reverse Bits of a Number***/
/****How to swap two bits in a given integer****/

void swapBits(unsigned int num, int pos1, int pos2)
{
    unsigned int mask1 = num & (1<<pos1);
    unsigned int mask2 = num & (1<<pos2);

    bit_print(num);
    bit_print(mask1);
    bit_print(mask2);

    if (!mask1 == !mask2)
        return;

   num = num ^ (1<<pos1);
   num = num ^ (1<<pos2);
   bit_print(num);
}

/****How to swap two bits in a given integer****/
/*****Set the rightmost unset bit****/

void rightmostUnset(unsigned int num)
{
    int result = num;
    bit_print(num);
    result = (~result);
    result = result & (result -1);
    result = (~result);
    bit_print(result);

}

/*****Set the rightmost unset bit****/

/****Efficient method for 2’s complement of a binary string*****/

void twoComplement(char *num)
{
    int i=0;
    int count =0;
    printf("%s\n",num);
    while (num[i])
    {
        i++;
    }
    count = i-1;
    printf("\n count %d\n",count);

    while (count >=0)
    {
        if (num[count] =='1')
        {
            count--;
            break;
        }

        count--;
    }

    while (count >=0)
    {
        if (num[count] =='1')
        {
            num[count] = '0';
        }else
        {
             num[count] = '1';
        }
        count--;
    }
        printf("%s",num);

}


/****Efficient method for 2’s complement of a binary string*****/

/****Find the two non-repeating elements in an array of repeating elements****/

void twoNonRepeat(int arr[], int num)
{
    int temp =0 ;
    int i =0;
    int num1 =0;
    int num2 =0;
    int mask= 1;

    for (i=0;i<num;i++)
    {
        temp = temp^arr[i];
    }

    while (mask)
    {
        if (mask & temp)
            break;
        mask = mask<<1;
    }

    for (i=0;i<num;i++)
    {
        if (mask & arr[i])
            num1 = num1^arr[i];
        else
            num2 = num2^arr[i];
    }
    printf("\n\n num1 %d num2 %d",num1,num2);
}


/****Find the two non-repeating elements in an array of repeating elements****/

/***Copy set bits in a range***/

void setBitsInRange(unsigned int num1,unsigned int num2, unsigned char start,unsigned char end)
{
    unsigned char range  = end - start + 1;
    unsigned int mask = ((1<<range)-1)<<start-1;
    unsigned int mask1 = num2 & mask;

    bit_print(num1);
    bit_print(num2);
    bit_print(mask);
    bit_print(mask1);

    printf("===============\n");
    num1 = num1 & ~mask;
    num1 = num1 | mask1;

    bit_print(num1);
}

/***Copy set bits in a range***/

/****Calculate square of a number without using *, / and pow()***/

unsigned int bit_square(unsigned int num)
{
    unsigned int result =1;
    if (num == 0 || num == 1)
        return 1;



}


/****Calculate square of a number without using *, / and pow()***/

/****Swap bits in a given number****/

void swapBitsPos1Pos2(unsigned int num, unsigned int pos1, unsigned int pos2,unsigned int range)
{
    unsigned int mask = (1<<range) - 1;
    unsigned int num1 = (num & (mask<<pos1))>>pos1;
    unsigned int num2 = (num & (mask<<pos2))>>pos2;
    unsigned int xor = num1 ^ num2;

    printf("\n@@@@@@@@@@@@@@@@@@@\n");
    bit_print(mask);

    printf("\n````````````````\n");
    bit_print(num);
    bit_print(num1);
    bit_print(num2);


    bit_print(num);
    num =  num ^ xor<<pos1;
    num =  num ^ xor<<pos2;
    bit_print(num);
    printf("\nRESETING BIT at twp positions %d \n",num);

}



/****Swap bits in a given number****/


/****Maximize a given unsigned number number by swapping bits at it’s extreme positions*****/

void maximizeSwapExtremePosition(unsigned int num)
{
    unsigned int msb = ~0;
    unsigned int lsb = 1;
    msb = ~(msb>>1);
bit_print(num);
    printf("ORIGINAL number %d \n",num);

    while (msb > lsb)
    {
        if (!(msb & num) && (lsb & num))
        {
            num = num ^ msb;
            num = num ^ lsb;
        }
        msb = msb >>1;
        lsb = lsb <<1;
    }

    printf("Changed number %d \n",num);
    bit_print(num);
}

/****Maximize a given unsigned number number by swapping bits at it’s extreme positions*****/


/****Next greater integer having one more number of set bits****/

void greatestInteterOneMoreBit(unsigned int num)
{
    unsigned int temp = ~num;
    printf("BEFORE %d \n\n",num);
    temp = temp & (temp-1);
    num = ~temp;
    printf("AFTER %d \n\n",num);
}

/****Next greater integer having one more number of set bits****/

int main()
{
    char str[] = "RaChiT SriVaStava";
    unsigned int n = 32768;
        char num[] = "1001100100";
        int arr[] = {100,200,300,401,500,100,300,200,800,500,701,900,800,900};
    bit_print(n);

    rightRotate(3333459,6);
    leftRotate(2419252563,4);
    rightmostSetBit(589728);


    toggleBit(999898, 5,16);
    unsetBit(0xFFFFFFF,8,19);
    printf("%s\n",str);
    toggleString(str);
    printf("%s\n",str);

    alternateBit(15);
    ADD_BIT(11970,-201);
    printf("\n\n\n");
    bit_palindrome(3357120531);
    bit_reverse(4127195136);
        bit_reverse(111);
    printf("=======\n\n");
   swapBits(4127195136, 10,31);
     printf("=======\n\n");
    rightmostUnset(21);

    twoComplement(num);
    twoNonRepeat(arr,14);
         printf("\n\n++++++++++++++++++++\n\n");

    setBitsInRange((unsigned int)~0,499961,9,20);

    swapBitsPos1Pos2(28,0,3,2);
    maximizeSwapExtremePosition(4);
    greatestInteterOneMoreBit(19);

    return 0;
}
