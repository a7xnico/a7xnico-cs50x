#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // TODO, check first 4 bytes in given file
    string filename = argv[1]; // Saves the name of the file
    FILE *f = fopen(filename, "r"); // in the direction of the file, opens and reads the pdf
    uint8_t buffer[4]; // checks for the 4 integers needed
    fread(buffer, 1, 4, f); // reads the integers

    for (int i = 0; i < 4; i++) // for loop to write all 4 numbers to the user
    {
        printf("%i\n", buffer[i]);
    }
    fclose(f);
}
