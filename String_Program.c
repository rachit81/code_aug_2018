#include<stdio.h>


/**** Remove duplicates from a given string ****/
char map[255];
void remove_duplicate(char *str)
{
    int index=0;
    int w_idx=0;
    int r_idx=0;

    while(str[r_idx])
    {
        if(!map[str[r_idx]])
        {
            str[w_idx] = str[r_idx];
            w_idx++;
            map[str[r_idx]] = 1;
        }
        r_idx++;
    }
    str[w_idx] = '\0';
}

/**** Remove duplicates from a given string ****/

/***Reverse an array without affecting special characters**/
//#define IS_ALPHABET(c) (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
int IS_ALPHABET(char x)
{
    return ( (x >= 'A' && x <= 'Z') ||
            (x >= 'a' && x <= 'z') );
}

void reverse_nospecial(char *str)
{
    int start=0;
    int end=0;
    char temp;

    if (!str[start])
        return;

    while(str[end])
    {
        end++;
    }
    end--;

    while (start < end)
    {
        if (IS_ALPHABET(str[start]) && IS_ALPHABET(str[end]))
        {
            printf ("both char %c %c \n",str[start],str[end]);

            temp =str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }else
        {
              printf ("bot nnot ... char %c %c \n",str[start],str[end]);

            if (!IS_ALPHABET(str[start]))
            {
                start++;
            }
            if (!IS_ALPHABET(str[end]))
            {
                end--;
            }
        }

    }

}

/***Reverse an array without affecting special characters**/



void remove_space(char *str)
{
    int w_idx=0;
    int r_idx=0;

    while(str[r_idx])
    {
        if(str[r_idx]!= ' ')
        {
            str[w_idx] = str[r_idx];
            w_idx++;
            map[str[r_idx]] = 1;
        }
        r_idx++;
    }
    str[w_idx] = '\0';
}

/***Print the string after the specified character has occurred given no. of times***/

void PrintStringCharCount(char *str, char c, int count)
{
    int index =0;
    int cnt =0;
            printf("hit \n");
    while(str[index])
    {

        if (c == str[index])

            cnt++;

        if (cnt == count)
        {

            printf("%s",&str[index]);
            break;
        }
        index++;
    }

}

/*****Print common characters of two Strings in alphabetical order****/
int freq1[26];
int freq2[26];
void printCommonChar(char * str1,char *str2)
{
    int count =0;
    int i=0;
    int min =0;

    while (str1[i])
    {
        freq1[str1[i] -'a']++;
        i++;
    }

    i=0;
    while (str2[i])
    {
        freq2[str2[i] -'a']++;
        i++;
    }

    printf("RACHIT\n\n");

    for (i=0;i<26;i++)
    {
        if ((freq1[i] != 0) && (freq2[i] != 0))
        {
            min = freq1[i];
            if (min > freq2[i])
            {
                min = freq2[i];
            }

            while(min)
            {
                printf("%c",'a'+i);
                min--;
            }

        }
    }
                printf("\n");

}
/*****Print common characters of two Strings in alphabetical order****/

/***Print the string after the specified character has occurred given no. of times***/



/****Check if both halves of the string have same set of characters*****/
int char_freq[26];
void checkStringHalf(char *str)
{
    int strlen = 0;
    int count =0;
    int i =0;

    while(str[i])
    {
        strlen++;
        i++;
    }

    count = (strlen)/2;
    i=0;

     while(i< count)
    {
        char_freq[str[i] - 'a']++;
         i++;
    }
    if (strlen & 0x1)
        i++;

    while(i< strlen)
    {

        char_freq[str[i] - 'a']--;
         i++;
    }
    for (i=0;i<26;i++)
    {
        if(char_freq[i])
        {
            printf("\nboth halves of the string doesn not have same set of characters\n");
            break;
        }
    }
    if (i==26)
    {
        printf("\nYAY BOTH HALF ARE SAME ....\n");
    }
}

/****Check if both halves of the string have same set of characters*****/


/*****Maximum consecutive repeating character in string******/
int char_freq_1[26];
void maxConsecutiveChar(char *str)
{
    int i=0;
    int j =0;
    int count = 0;
    char c;
    int max =0;
    while(str[i])
    {
        c= str[i];
        count =1;
        j = i+1;
        while(str[j] && (c == str[j]))
        {

            count++;
            j++;
            printf("count %d j %d char %c c %c \n",count,j,str[j-1],c);
        }

            if (count > char_freq_1[c - 'a'])
            {
                char_freq_1[c - 'a'] = count;
                printf("count %d charac %c freq %d  \n",count,c,char_freq_1[c - 'a']);

            }

        i = j;
    }

    for (i=0;i<26;i++)
    {
        printf("%d ",char_freq_1[i]);

        if (max < char_freq_1[i])
        {
            j = i;
            max = char_freq_1[i];
        }
    }
    printf("Char %c \n ",'a' + j );
}

/*****Maximum consecutive repeating character in string******/


/****Efficient method for 2’s complement of a binary string*****/

void Str2Complement(char *str)
{
    int idx=0;
    int len=0;
    printf("String BEFORE Complement %s\n",str);
    while (str[idx])
    {
        len++;
        idx++;
    }
    idx--;

    while((str[idx] == '0') && (idx >= 0))
    {
        idx--;
    }
    if (idx < 0)
        return;

    // skip the 1
    idx--;

    while(idx >= 0)
    {
        if (str[idx] == '0')
            str[idx] = '1';
        else
            str[idx] = '0';
        idx--;
    }
    printf("String after Complement %s",str);

}

/****Efficient method for 2’s complement of a binary string*****/

int main()
{
    char strng[] = "1000100";
    char str1[] = "Ab,c,de!$";
    char str[] = "rachit srivastava";
    char space[] = "g  eeks   for ge  eeks  ";
    char strP[] = "geeksforgeeks";
    char p = 'e';
    int count =2;

    remove_duplicate(str);
    printf("%s\n",str);
    reverse_nospecial(str1);
    printf("reverse ----> %s",str1);
    remove_space(space);
    printf("Space ----> %s\n",space);
    PrintStringCharCount(strP,p,count);
    printf("\n\n\n");
    printCommonChar("hhhhhello","gfghhmh");    printf("\n\n\n");

    checkStringHalf("abcdcab");
    maxConsecutiveChar("aaaabbbbbabbbcbdddeddeddedddeddedbb");
    Str2Complement(strng);
}
