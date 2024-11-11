#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2) // make sure program is run with one command line argument
    {
        printf("Usage : ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i])) // make sure every character in argv[1] is a digit
        {
            printf("Usage : ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]); // convert argv[1] from a string to an int

    string plaintext = get_string("Plaintext: "); // prompt user for plaintext
    printf("Ciphertext: ");

    for (int j = 0; j < strlen(plaintext);
         j++) // for each character in the plaintext rotate the chacacters if it's a letter
    {
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + key) % 26 + 65);
        }
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}
