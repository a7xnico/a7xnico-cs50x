#include <cs50.h>
#include <stdio.h>

// poner la funion aca para que se recuerde al pasarse a machine code
void print_row(int height, int row); // se centra en la implementacion del codigo

int main(void) // se centra en la interaccion con el usuario
{
    int height, row; // llamar las variables aca para que no haya problemas
    do
    {
        height = get_int("enter the height here: "); // pedirle la altura al usuario y guardarla
    }
    while (height < 1 || height > 8); // evitar que se procese la altura equivocada
    for (row = 0; row < height; row++) // el loop que va a crear la piramide
    {
        print_row(height, row); // llamar la funcion para crear la piramide
    }
}
void print_row(int height, int row)
{
    int space, column;

    for (space = 0; space < height - row - 1; space++) // esto crea los espacios
    {
        printf(" "); // mueve al # lo que sea necesario
    }
    for (column = 0; column <= row; column++) // crea los # luego de dejar los espacios
    {
        printf("#");
    }
    printf("\n"); // hace que la fila vaya hacia abajo, creando asi la piramide
}
