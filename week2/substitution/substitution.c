#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int ASCII_LOWER_A = 97; // makes the lowercase values of characters on ASCII drop to 0 to 26
const int ASCII_UPPER_A = 65; // makes the uppercase values of characters on ASCII drop to 0 to 26

bool is_valid_key(string key); // Validates the encryption key
string get_plaintext(void);    // asks the user the text to encrypt
void encrypt_text(string plaintext, string key,
                  char ciphertext[]);     // encrypts the text in another function
void print_ciphertext(char ciphertext[]); // prints the encrypted text to the user

int main(int argc, string argv[])
{

    if (argc != 2) // checks for errors in input
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (!is_valid_key(argv[1]))
    {
        printf("Key must contain 26 unique alphabetical characters\n");
        return 1;
    }

    string plaintext = get_plaintext(); // calls the function to ask user input
    int length = strlen(plaintext);     // measures the amount of letters in the text
    char *ciphertext = malloc((length + 1) * sizeof(char)); // dinamically allocate memory
    if (ciphertext == NULL)                                 // handles memory allocation failure
    {
        return 1;
    }
    encrypt_text(plaintext, argv[1], ciphertext); // calls the function to encrypt the text
    print_ciphertext(ciphertext);                 // prints it to the user
    free(ciphertext);                             // free the allocated memory
    return 0;
}

bool is_valid_key(string key) // function to check the key
{
    int length;
    length = strlen(key); // counts how many letters
    if (length != 26)     // checks if it's correct with the alphabet
    {
        return false; // false if it's incorrect
    }
    bool seen[26] = {false};
    for (int i = 0; i < length; i++)
    {
        char c = toupper(key[i]);
        if (!isalpha(c))
        {
            printf("The characters aren't alphabetical\n");
            return false;
        }
        int index = c - 'A';
        if (seen[index])
        {
            printf("The characters aren't unique\n");
            return false;
        }
        seen[index] = true;
    }
    return true; // returns true if all checks pass
}

string get_plaintext(void)
{
    return get_string("Plaintext: ");
}

void encrypt_text(string plaintext, string key, char ciphertext[])
{
    int length = strlen(plaintext);
    int index;
    for (int i = 0; i < length; i++)
    {
        if (islower(plaintext[i])) // checks if it's lowercase
        {
            index = plaintext[i] - ASCII_LOWER_A; // makes it go to the 0 to 26 range
            ciphertext[i] = tolower(key[index]);    // compares the letter to encryption key
        }                                           // makes the key lowercase
        else if (isupper(plaintext[i])) // the same for uppercase letters
        {
            index = plaintext[i] - ASCII_UPPER_A; // goes to range 0 to 26
            ciphertext[i] = toupper(key[index]);  // compares with encryption key
        }                                         // makes the key value uppercase
        else
        {
            ciphertext[i] = plaintext[i]; // maintains the same with other characters
        }
    }
    ciphertext[length] = '\0'; // adds NULL to end the string
}

void print_ciphertext(char ciphertext[])
{
    printf("Ciphertext: %s\n", ciphertext); // gives the encrypted string to the user
}
