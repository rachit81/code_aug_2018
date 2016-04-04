#include <stdio.h>
int main()
{
/* char str[] = "aabbbcccdeef"; */ 
/* char str[] = "rachit is a good boy!!!!"; */
char str[] = "aaaaaaaaaaaaaaaaaaaaaaaaa bbbbbbbbbbbbbbbbbbbbbb";
char *tmp =str;
int rd=0,nxt=0;
char ch;
char repeat;
int wrt =0;

        while(tmp[rd] != '\0')
        {
                ch =tmp[rd];
                nxt=rd+1;
                repeat =0;
                while(tmp[nxt] != '\0')
                {
                        if (tmp[nxt] != ch )
                                break;
                        nxt++;
                        repeat =1;
                }
                if (repeat)
                {
                        tmp[wrt++] = '0' + (nxt-rd);
                        tmp[wrt++] = ch;
                        if (!tmp[nxt])
                        {
                                tmp[wrt] = '\0';
                                break;
                        }
                       rd =nxt; 
               }
                else
                {
                     tmp[wrt++] = tmp[rd];
 
                        if (!tmp[nxt])
                        {
                                tmp[wrt] = '\0';
                                break;
                        }
                     rd++;
                }
        }
  printf ("The string is %s \n",str);


}

