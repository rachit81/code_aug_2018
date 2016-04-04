#include <stdio.h>
char ascii_map[256];

int main()
{
char str[]="my name is rachit srivastava";
int i =0 ,j=0;
char *tmp = str;

while(str[i])
{
  if(!ascii_map[str[i]])
    {
    str[j] = str[i];
    j++;
    ascii_map[str[i]] =1;
    }

  i++;
}

str[j] = '\0';

printf(" string is %s \n", str);
}
