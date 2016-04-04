#include<stdio.h>
#define MAX 100
#define OPERAND 0
#define OPERATOR 1
#define EQUAL 0
#define GREATER 1
#define LESSER 1

char stk[MAX];
int top =-1;

typedef struct elem
{
unsigned char type[MAX];
int index;
int data[MAX];
}elem;

elem postfix;

void put(int num, unsigned char oper)
{
if (postfix.index >= MAX)
{
  printf("stack overflow \n");
  return;
}
postfix.data[postfix.index] = num;
postfix.type[postfix.index] = oper;
postfix.index++;

}

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

unsigned char empty()
{
  if (top == -1)
  return 1;
  else
  return 0;
}

char peek()
{
  return stk[top];
}


int token(char *str,int *i)
{
  int num=0;
  while(str[*i] != '\0')
  {
    if (str[*i] >= '0' && str[*i] <= '9')
    {
      num =  (num*10)+(str[*i] - '0');
    }
    else 
    {
      return num;
    }
    ++*i;
  }
  return num;
}

 int priority(char local1,char local2)
 {  
   if (local1 == local2)
    return EQUAL;
   if (local1 == '*' || local == '/')
    return GREATER;
   if (local1 == '+' || local == '-')
    return LESSER;

 }

int main()
{
  char infix[] = "123+234+567-10*1111";
  int i=0;
  int num=0;
  char temp;
  char stack_top;

  while(infix[i] != '\0')
  {
    num = token(infix,&i);
    put(num,0);
    printf (" Number is %d \n",num);
   
    temp = infix[i];
    
    if(!empty())
    {
      stack_top = peek();
      if(priority(stack_top,temp) == GREATER)
      {
        stack_top = pop();
        put(stack_top,1);      
      }
      else if(priority(stack_top,temp) == LESSER || temp == '('))
      {
        push(temp);
      }
       
    }
    else if (temp == '+' || temp == '-' || temp == '*' || temp =='/' || temp == '(')
    {
      push(temp);
    }
    i++;
  }

}


