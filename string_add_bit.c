#include <stdio.h>

void reverse(char* rev)
{
  int index1=0,index2=0;
 char c;
   while(rev[index1])
        index1++;
   if (index1) index1--;

    while(index2<index1)
    {
       c = rev[index1];
       rev[index1] = rev[index2];
       rev[index2] = c;

       index2++;
       index1--;
    }
}

void str_add(char * str1, char *str2)
{
    char add[100];
    int index1=0,index2=0;
    int carry=0;
    int i=0;
    int temp1=0,temp2=0;

    while(str1[index1])
        index1++;

    while(str2[index2])
        index2++;

    if (index1) index1--;
    if (index2) index2--;
    while((index1>=0) && (index2>=0))
    {
        add[i++] = ((str1[index1] -'0') ^ (str2[index2] -'0') ^ carry) + '0';
        carry = (str1[index1] -'0') & (str2[index2] -'0') | ((str1[index1] -'0') & (carry)) | (carry & (str2[index2] -'0')) ;
        index1--;
        index2--;
    }

    while(carry)
    {
        if (index1>=0)
            {
                add[i++] = ((str1[index1] -'0')  ^ carry) + '0';
                carry = (str1[index1] -'0') & (carry);
                index1--;

            }
            else  if (index2>=0)

            {
                add[i++] = ((str2[index2] -'0') ^ carry) + '0';
                carry = (carry) & (str2[index2] -'0');
                index2--;
            }else{break;}

        printf("carry is  %c  %d\n",add[i-1],carry);

    }
    if (carry)
                 add[i++] = '1';

    while(index1>=0)
    {
         add[i++] = str1[index1];
         index1--;
    }

    while(index2>=0)
    {
         add[i++] = str2[index2];
         index2--;
    }

    add[i] = '\0';
    printf("before String is %s \n",add);
    reverse(add);
    printf("String is %s \n",add);
}

int main()
{
    str_add("111111","1");
}
