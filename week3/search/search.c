#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[]= {20, 500, 10, 5, 100, 1, 50}; // assign the values in the array

    int n = get_int("Number: ");
    for(int i = 0; i < 7; i++) // 7 is the array length
    {
        if (numbers[i] == n) // searchs a number in the array
        {
            printf("Found\n");
            return 0; // ends the program earlier, indicating success
        }
    }
     printf("Not Found\n");
     return 1; // indicates failure
}
