#include <stdio.h>
int main()
{
/* char string[] ="my name is rachit srivastava"; */
char string[] ="rachhhhit rachits";
char sub[]="rachits";
int i=0,j=0,k=0;
char found =0;
  while(string[i])
  {
    j=0;
    k=0;
    found =1;
    while(sub[j])
    {
      if (sub[j] != string [i+k])
      {
        found = 0; 
        break;
      }
      j++;
      k++;
    }
      
   if (found == 1)
    break; 
     
    i++;
  }

  if (found)
    printf(" sub string is at pos %d \n", i);
    else 
    printf(" sub string NOT FOUND !!!!!!\n");
}
