#include <cs50.h>
#include <stdio.h>
#include <string.h> // strlen, strcmp

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");
    for(int i = 0; i < 6; i++)
    {   // use strcmp instead of == like in integers
        if(strcmp(strings[i], s) == 0) // find equality between array and input
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
