#include<stdio.h>
#include<string.h>

void reverse(char *str,int start, int end)
{
char temp;
while(start < end)
{
temp = str[start];
str[start] = str[end];
str[end] = temp;
start++;
end--;
}

}

int main()
{
/* char str[] ="my name is rachit srivastava"; */
char str[] ="  my   name   is rachit srivastava";
char str1[] ="RACHITS";
char *tmp = str;
char flag =0;
int i=0,start=0,end=0;
reverse(str1,0,strlen(str1)-1);

printf ("the string is %s \n", str1);

start=0;
do
{
  if(str[i] != ' ' && !flag)
  {
    start = i;
    flag = 1;
  }else if (str[i] == ' ' && flag)
  {
    flag =0;
    end = i-1;
    reverse(str,start,end);
  }else if (str[i+1] == '\0' && flag)
      {
        
        end = i;
         reverse(str,start,end);
      }
  
  i++;  

}while(str[i]);

reverse(str,0,strlen(str)-1);

printf ("the string is %s \n", str);


}
