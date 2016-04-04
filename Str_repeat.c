#include <stdio.h> 
unsigned int map[8];
void setmap(unsigned char num)
{
  int index = num>>5;
  int rem =   num & 0x1f;
  map[index] |=  1<<rem; 
}

void resetmap(char num)
{
  int index = num>>5;
  int rem =   num & 0x1f;
  map[index] &= ~( 1<<rem); 
}

int issetmap(unsigned char num)
{
  int index = num>>5;
  int rem =   num & 0x1f;
  if (map[index] & (1<<rem))
    {
      return 1; 
    }
  else{
      return 0; 
    }
}
int main()
{
  char str[]="MY NAME IS RACHIT";
  char squeeze[] ="AEIOU";
  char *itr=NULL;
  int i=0,j=0;
  while(squeeze[i])
  {
    setmap(squeeze[i]);
    i++;
  }

  for(i=0,j=0;str[j]!= '\0';j++)
  {
    if (!issetmap(str[j]))
    {
     str[i++] = str[j];
    }
  }
  str[i] = '\0';    
  printf ("\n %s \n\n ",str );

}
