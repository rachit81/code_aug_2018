#include<stdio.h>
#define MAX 100
int stk[MAX];
int top =-1;
void push(int num)
{
  if(top == MAX)
  {
  printf("stack overflow \n");
  return;
  }
stk[++top] = num; 
}

int pop()
{
int num;
  if(top == -1)
  {
  printf("stack underflow \n");
  return -1;
  }
num = stk[top];
top--;
return num;

}


int main()
{
push(3);
push(7);
push(17);
push(19);
push(31);
push(71);

printf(" number is %d \n",pop());
printf(" number is %d \n",pop());
printf(" number is %d \n",pop());
printf(" number is %d \n",pop());
printf(" number is %d \n",pop());
printf(" number is %d \n",pop());
printf(" ######################### \n");
printf(" number is %d \n",pop());

printf(" $$$$$$$$$$$$$$$$$$$$$$$$ \n");
printf(" number is %d \n",pop());

}


