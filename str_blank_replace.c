#include <stdio.h>

void remove_space(char *str)
{
    int i;
    char *tmp =str;
    char *last;
    unsigned int count =0;
    unsigned int space=0;
    unsigned int extra = 0;
    while(*tmp)
    {
        count++;
        if (*tmp == ' ')
            space++;
        tmp++;
    }
    last = tmp-1;
    extra = space *2; //*replace space by %20

    tmp = tmp+extra;
    *tmp = '\0';
    tmp--;
    while(last != str)
    {
        if (*last == ' ')
        {
            *tmp = '0';
            tmp--;
            *tmp = '2';
            tmp--;
            *tmp = '%';
            tmp--;
        }
        else
        {
         *tmp= *last;
         tmp--;
        }

       last--;
    }

        printf("%s \n",str);
}
int main()
{
    char string[40] ="MY NAME IS RACHIT";
    remove_space(string);

}
