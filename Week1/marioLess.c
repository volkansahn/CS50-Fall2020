#include <stdio.h>
#include <cs50.h>

int get_positive_int(char str[]);
void draw_pyramids(int height);
void draw_pyramids_new(int height);

int main(void)
{
    int height = get_positive_int("Height :");

    //draw_pyramids(height);
    draw_pyramids_new(height);

}

void draw_pyramids(int height)
{
    if (height == 1)
    {
        printf("#\n");
    }
    else
    {
        for (int index = 0; index < height; index ++)
        {
            for (int inner_index = 1; inner_index < height - index; inner_index++)
            {
                printf(" ");
            }
            for(int j = 0; j < index + 1; j ++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
}

void draw_pyramids_new(int height)
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col< height; col++)
        {
            if (col >= (height - row -1))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}



int get_positive_int(char str[])
{
    int n;

    do{
        n = get_int("%s",str);
    }
    while(n < 1 || n > 8);
    return n;

}
