#include<stdio.h>
#define MAX 100
char stk[MAX];
int top =-1;

void push(char num)
{
  if(top == MAX)
  {
  printf("stack overflow \n");
  return;
  }
  stk[++top] = num; 
}

char pop()
{
char num;
  if(top == -1)
  {
  printf("stack underflow \n");
  return -1;
  }
num = stk[top];
top--;
return num;

}

void balance (char *str)
{
  unsigned int i =0;
  char temp;
  while (str[i] != '\0')
  {
    if (str[i] == '{' || str[i] == '[' || str[i] == '(')
    {
      push(str[i]);
    }
    else if (str[i] == '}' || str[i] == ']' || str[i] == ')')
    {
      temp = pop();
      if ((str[i] == '}'  && temp != '{' ) || 
          (str[i] == ']'  && temp != '[' ) ||
          (str[i] == ')'  && temp != '(' )) 
        {
          printf(" STRING NOT BALNACE %c %c \n",str[i],temp);
          return;
        }

    }  
    i++;
  }
  
          printf(" STRING BALNACE %s %d \n",__FILE__,__LINE__);
          return;
}

int main()
{
//char str[] = "{a{3{5}o}p}\[;(l{+}-)~]";
//char str[] = "{a{35}o}p}\[;(l{+}-)~]";
char str[] = "[] {{{ }}} ]]]";

balance(str);
}


