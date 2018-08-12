#include <stdio.h>
#include<conio.h>
unsigned  char screen[144];

/*

Draw Line: A monochrome screen is stored as a single array of bytes, allowing eight consecutive
pixels to be stored in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will
be split across rows). The height of the screen, of course, can be derived from the length of the array
and the width. Implement a function that draws a horizontal line from (xl, y) to (x2, y).
The method signature should look something like:
drawLine(byte[] screen, int width, int xl, int x2, int y)

*/


int is_set(unsigned int num)
{
    unsigned char bmap = 0x80;
    unsigned int div = num>>3;
    unsigned int mod = num & 0x7;
    return (screen[div] & ((bmap>>mod)));
}



void draw_line(char *screen1, int width, int x1, int x2, int y)
{
    int start_index = (width/8) * y ;
    int start_offset = x1/8;
    int end_offset = x2/8;
    unsigned char mask1 =0;
    unsigned char mask2 =0;
    unsigned char mask3 =0;


    int i=0;
    if ((x1%8) != 0)
        start_offset++;

    if ((x2%8) != 0)
        end_offset--;
    for(i=start_offset;i<=end_offset;i++)
    {
        screen[i+start_index] = 0xFF;
    }

    if ((x1%8) != 0)
    {
        mask1 = 0xff;
        mask1 = mask1>>(x1%8);
        printf("%x \n",mask1);
        screen[start_index+start_offset-1] = mask1;
    }

    if ((x2%8) != 0)
    {
        mask2 = 0xff;
        mask2 = ~(mask2>>((x2%8)+1));
                printf("%x \n",mask2);

        screen[start_index+end_offset+1] = mask2;
    }

    if ((x1/8) == (x2/8))
    {
        mask1 = 0xff;
        mask1 = mask1>>(x1%8);

        mask2 = 0xff;
        mask2 = ~(mask2>>((x2%8)+1));

        mask3 = mask1 & mask2;

        screen[start_index+(x1/8)] = mask3;

    }


}



void print_screen(char *screen, int row,int col)
{
    int i=0;
        printf("    ");
        int count =0;
        int j=0;

    for (i=0;i<48;i++)
    {
        if (i<10){
            printf("0%d ",i);

        }
        else {
        printf("%d ",i);
        }
    }
    printf("\n");
//    printf("\t");
//    printf("\n");

    for (i=0;i<24;i++)
    {
         if (i<10){
            printf("0%d",i);
        }
        else {
        printf("%d",i);
        }
             printf("  ");

        for (j=0;j<48;j++)
        {

               if (is_set(count))
               {
                    printf("1  ");
               }
            else
                printf("0  ");


            count++;

        }
        printf("\n");
    }


}
int main()
{
    memset(screen,0,144);
    draw_line(screen,48,17,20,4);
    print_screen(screen,48,24);

    return 0;
}
