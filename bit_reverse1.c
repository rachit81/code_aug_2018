#include <stdio.h>
#define IS_CHAR(c) ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))
int strcomp(char *str1,char *str2)
{
    int index =0;
     unsigned char mask = 1<<5;
    mask= ~mask;

    if ((IS_CHAR(str1[index])))
        {

        }

    while(1)
    {
        if ((IS_CHAR(str1[index])) && (IS_CHAR(str2[index])) )
        {
                printf("BOTH ARE CHARACTER :-) %d \n",index);
            if ((str1[index] & mask) != (str2[index] & mask))
            {
                printf("%c %c %d \n ",str1[index],str2[index],index);
                break;
            }
        }
        else if (str1[index] != str2[index])
        {
             printf("2 %c %c %d \n ",str1[index],str2[index],index);
            break;
        }
        else if (str1[index] == '\0' || str2[index] == '\0')
        {
             printf("END  %c %c %d \n ",str1[index],str2[index],index);
            break;
        }
        index++;
    }

    if (str1[index] == str2[index])
        return 0;
    else if (str1[index] < str2[index])
        return -1;
    else
        return 1;
}
int main()
{
    int status;
    status =strcomp("rachit~","RAchiT^");
    printf("status is %d \n",status);
}


