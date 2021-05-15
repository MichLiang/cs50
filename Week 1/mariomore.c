#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = get_int("Height: ");
    while ((h < 1) || (h > 8))
    {
        printf("please input an integer between 1 and 8\n");
        h = get_int("Height: ");
    }
    for (int i = 0; i < h; i++)
    {
        for (int d = h - 1; d > i; d--)
        {
            printf(" ");
        }

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("#");

        printf("  ");

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("#\n");

    }
}