#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");
    while (height <= 0 || height > 8)
    {
        height = get_int("Height: ");
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < ((height + 1) * 2); j++)
        {
            if (j < (height - i - 1) || j == height || (j == height + 1))
            {
                printf(" ");
            }
            else if (j > (height + i + 2))
            {
                printf("");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
