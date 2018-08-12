#include<stdio.h>
#define MAX 100
#define OPERAND 0
#define OPERATOR 1
#define EQUAL 0
#define GREATER 1
#define LESSER 1

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


int precedence(char op1 , char op2)
{




}

int main()
{



}
