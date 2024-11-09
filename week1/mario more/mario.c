#include <cs50.h>
#include <stdio.h>

void print_row(int height, int row); // reminder for the compiler of the function

int main(void) // main function, focused on interaction with the user
{
    int height, row; // makes things easier
    do
    {
        height = get_int(
            "Height of the pyramids: "); // gets the number needed for the code from the user
    }
    while (height < 1 || height > 8); // limits the answers making it repeat if incorrect
    for (row = 0; row < height; row++) // first loop to create the code
    {
        print_row(height, row); // call the function done for the creation of the pyramids
    }
}
void print_row(int height, int row) // function previously written
{
    int space, column;

    for (space = 0; space < height - row - 1; space++) // makes the spaces in the first pyramid
    {
        printf(" ");
    }
    for (column = 0; column <= row; column++) // makes the # for the pyramid
    {
        printf("#");
    }
    printf("  ");                             // separation between first and second pyramid
    for (column = 0; column <= row; column++) // repeats the same line from earlier in the function
    {
        printf("#"); // makes second pyramid, it's easier withouth the spaces
    }
    printf("\n"); // moves one row down
}
