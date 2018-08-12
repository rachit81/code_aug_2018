#include <stdio.h>
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

int lengthLongSubstring(char *arr)
{
    int i =0;
    int count =0;
    char temp;
    while (arr[i])
    {
        if (arr[i] == '(')
        {
            push(arr[i]);
        }
        else if (arr[i] == ')')
        {
            temp = peek();
            if (temp == '(')
            {
                pop();
                count++;
            }
        }
        i++;
    }
    printf("matching %d \n",count);

}

void push2bottom(char temp)
{
    char c;
    if (empty())
    {
        push(temp);
        return;
    }
    c = pop();
    push2bottom(temp);
    push(c);
}


void reverse()
{
    if (empty())
        return;
    char temp;
    temp = pop();
    reverse();
    push2bottom(temp);
}

void sortedInsert(char temp)
{
    char stk;
    if (empty())
    {
        push(temp);
        return;
    }
    stk = pop();
    if (temp < stk)
    {
        sortedInsert(temp);
        push(stk);
    }else{
        push(stk);
        push(temp);
    }
}

void sort()
{
    char temp;
    if (empty())
        return;

    temp = pop();
    sort();
    sortedInsert(temp);
}

int main()
{
    char par[] = "()(()))))";
    push('e');
    push('g');
    push('b');
    push('d');
    push('a');
    push('f');
    push('c');
    push('h');
//    reverse();
    sort();
printf("===============\n");
  while(!empty())
  {
      printf ("%c \n",pop());
  }
    //lengthLongSubstring(par);
}
