#include <cs50.h> //libraries
#include <stdio.h>

int main(void)
{

    // ask user for height
    int n;
    do
    {
        n = get_int("height: ");
    }
    while (n < 1 || n > 8); // solo aceptar valores entre 1 y 8

    for (int i = 0; i < n; i++) // print pyramid that same height
    {
        for (int j = 0; j < n; j++) // hacerlo 2 veces para el largo y el alto
        {
            printf("#");
        }
        printf("\n");
    }
}
