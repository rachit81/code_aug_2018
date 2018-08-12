/*Implement an algorithm to determine if a string has all unique characters. What if you
cannot use additional data structures*/
#include <stdio.h>
unsigned int bitmap[8];

void set_bit(unsigned char num)
{
    unsigned int div = num>>5;
    unsigned int mod = num & 0x1f;
    bitmap[div] = bitmap[div] | 1<<mod;
}

void clear_bit(unsigned char num)
{
    unsigned int div = num>>5;
    unsigned int mod = num & 0x1f;
    bitmap[div] = bitmap[div] & (~(1<<mod));
}

int is_set(unsigned char num)
{
    unsigned int div = num>>5;
    unsigned int mod = num & 0x1f;
    return (bitmap[div] & ((1<<mod)));
}

void toggle_bit(unsigned char num)
{
    unsigned int div = num>>5;
    unsigned int mod = num & 0x1f;
    bitmap[div] = bitmap[div] ^ (1<<mod);
}

unsigned int count[256];

/*
Given two strings, write a method to decide if one is a permutation of the
other.
*/

int permutation(char *str1,char *str2)
{
    int i=0;
    int j=0;
    int flag=0;
    while(str1[i])
    {
        count[str1[i]]++;
        i++;
    }
    i=0;
    while(str2[i])
    {
        if (count[str2[i]])

        count[str2[i]]--;
        else
        {
            flag =1;
            break;
        }

        i++;
    }

    for (j=0;j<256;j++)
    {
        if (count[j])
            flag =1;

    }
    if (flag)
    {
        printf("\nstring are not permutation\n");
    }else
    printf("\n string are permutation  :-) :-) :-)\n");

}
/*
Given a string, write a function to check if it is a permutation of
a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A
permutation is a rearrangement of letters. The palindrome does not need to be limited to just
dictionary words.
*/
int palindrome_permutation(char *str)
{
    int palin_false=0;
        int i=0;
        int cnt=0;
    while(str[i])
    {
         toggle_bit(str[i]);
         i++;
    }
    for (i=0;i<8;i++)
    {
        if(bitmap[i])
        {
            if (bitmap[i] & (bitmap[i]-1))
            {
                palin_false =1;
                break;
            }

            cnt++;
        }
    }

    if (cnt >1 || palin_false)
        printf("NOT A PALINDROME\n");
    else
        printf("YAY PALINDROME :-0 :-0 \n");

}

int main()
{
    char *str = "RACHITA";
    int index=0;
        int i=0;

    while(str[i])
    {
        if (!is_set(str[i]))
         set_bit(str[i]);
        else{
        printf("The char is repeated %c",str[i]);
            break;
        }
        i++;
    }
    if (!str[i])
                printf("The char is not repeated");


      permutation("EEAPSC","ESCAPE");

    for(i=0;i<8;i++)
    {
        bitmap[i] = 0;
    }

    palindrome_permutation("tacocat");
}
