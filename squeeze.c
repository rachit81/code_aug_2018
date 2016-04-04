#include <stdio.h>

void squeeze(char s[], char c)
{
int i =0; int j=0;
  while (s[j] != '\0')
  {
    if(s[j] != c)
    {
      s[i] = s[j];
      i++;
    }
    j++;      
  }
  s[i] = '\0';
}

int main()
{
char *temp = "MY NAME IS RACHIT SRIVASTAVA";
squeeze(temp,'A');

  printf(" squueze string is %s \n", temp);

}
