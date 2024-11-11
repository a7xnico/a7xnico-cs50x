#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// checks if the conditions are met outside the main function
bool validate_arguments(int argc, string argv[]);
// makes the string key into an integer
int convert_key(string key);
// asks the user for the text to encrypt
string get_plaintext(void);
// encrypts the text
string encrypt_text(string plaintext, int key);

int main(int argc, string argv[])
{
    if (!validate_arguments(argc, argv)) // calls the boolean function
    {
        return 1; // signals an error in main function
    }
    int key = convert_key(argv[1]);                   // gets the key number
    string plaintext = get_plaintext();               // asks the user for the text
    string ciphertext = encrypt_text(plaintext, key); // encrypts on main

    if (ciphertext == NULL)
    {
        return 1;
    }

    printf("Ciphertext: %s\n", ciphertext);           // gives the encrypted text to the user
    free(ciphertext);                                 // free the allocated memory
    return 0;                                         // ends the program
}

bool validate_arguments(int argc, string argv[])
{
    if (argc != 2) // if there's more than 2 inputs counting the ./caesar
    {
        printf("Usage: ./caesar2 key\n"); // error message
        return false;                    // goes back again
    }
    int length = strlen(argv[1]); // converts the function to a simple integer in the for loop
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(argv[1][i])) // checks if there's something other than a number
        {
            printf("Usage : ./caesar2 key (Key must be a numeric value)\n"); // gives this info to
                                                                            // the user
            return false;
        }
    }
    return true; // if everything's correct it continues the program
}

int convert_key(string key)
{
    return atoi(key); // atoi converts a string to an integer
}
string get_plaintext(void)
{
    return get_string("Plaintext: "); // simple function to ask input
}
string encrypt_text(string plaintext, int key)
{

    int length = strlen(plaintext);         // makes it easier in the  for loop
    string ciphertext = malloc(length + 1); // allocate memory for the encrypted text
    if (ciphertext == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (int j = 0; j < length; j++)
    {
        if (isupper(plaintext[j])) // tracks the uppercase letters
        {
            ciphertext[j] = (plaintext[j] - 65 + key) % 26 +
                            65; // moves to the 0-26 range in ASCII and goes back
        }
        else if (islower(plaintext[j])) // tracks the lowercase letters
        {
            ciphertext[j] = (plaintext[j] - 97 + key) % 26 +
                            97; // moves to the 0-26 range in ASCII and goes back
        }
        else // all symbols that aren't letters
        {
            ciphertext[j] = plaintext[j]; // it stays the same
        }
    }
    ciphertext[length] = '\0'; // null-terminate the string
    return ciphertext;         // returns the value for the main function
}
