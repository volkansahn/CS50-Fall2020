#include <cs50.h>
#include <stdio.h>

int get_positive_int(char str[]);
void draw_pyramids_new(int height);

int main(void)
{
    //Word to ask user
    char str[] = "Height : ";
    int height = get_positive_int(str);
    draw_pyramids_new(height);
}
//Draw pyramids according to user entered Height
void draw_pyramids_new(int height)
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < height; col++)
        {
            if (col >= (height - row - 1))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("  ");
        for (int index = 0; index < row + 1; index++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_positive_int(char str[])
{
    int n;
    do
    {
        n = get_int("%s", str);
    }
    while (n < 1 || n > 8);
    return n;
}
