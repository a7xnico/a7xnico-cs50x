#include <cs50.h> //librerias/libraries
#include <stdio.h>

int main(void) // funcion principal
               //  al querer asignar un valor primero poner el significado (string)
{ // get_string es la forma facil de cs50 para pedirle un valor al usuario
    string name = get_string("what's your name? "); // poner un espacio para respuesta del usuario
    printf("hello, %s\n", name); // siempre poner una coma antes de escribir la respuesta
}
