#include <stdio.h>

int main()
{
  int i=0;
  char * str ="ABCD";
  unsigned int size = strlen(str);
  unsigned char *map = (unsigned char *)malloc(sizeof(unsigned char)*size);
  char *temp = (char *)malloc(sizeof(char)*size+1);
  memset(map,0,size);  
  
  for(i=0;i<size;i++)
  {
    map[i] =1 ;
    
    for 

  }  
    printf ("%d \n",strlen(str));
    printf ("\n");
}
