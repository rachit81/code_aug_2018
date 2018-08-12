#include <stdio.h>

char * string_add(char * num1, char* num2)
{
    char *result = malloc(200 * sizeof(char));
    int len1= strlen(num1);
    int len2= strlen(num2);
    int sum=0 ,carry=0,i=0,start,end;
    char temp;
    if ((num1 == NULL) && (num2 == NULL))
    {
        printf(" BOTH STRING ARE NULL");
        return NULL;
    }

    while (len1 && len2)
    {
        sum = carry + (num1[len1-1] - '0') + (num2[len2-1] - '0');
        result[i++] = (sum%10) + '0';
        carry = sum /10;
        len2--;len1--;
    }
    if (!len1 && len2)
    {
        while(len2)
        {
            sum = carry +  (num2[len2-1] - '0');
            result[i++] = (sum%10) + '0';
            carry = sum /10;
            len2--;
        }
    }
    if (!len2 && len1)
    {
        while(len1)
        {
            sum = carry +  (num1[len1-1] - '0');
            result[i++] = (sum%10) + '0';
            carry = sum /10;
            len1--;
        }
    }
    if (carry)
    {
        result[i++] = carry + '0';
    }
    result[i] = '\0';
    start =0;
    end = i-1;
    while (start < end)
    {
        temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
    printf("sum is %s ",result);
    return result;
}

int main()
{
    string_add("9999","9999");
}
