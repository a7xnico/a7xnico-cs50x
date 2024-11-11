#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int CL_index(int letters, int words, int sentences);

int main(void)
{
    // Prompts the text from the user
    string text = get_string("TEXT: ");

    int letters = count_letters(text);     // Calls function for the letters
    int words = count_words(text);         // Calls the function for the words
    int sentences = count_sentences(text); // Calls the function for the sentences
    int index =
        CL_index(letters, words, sentences); // the answer, it's already computed with the index

    if (index < 1) // diferentiates each answer with this if-else
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16) // it handles all the grades between 2 and 15
    {
        printf("Grade %i\n", index);
    }
    else if (index >= 16) // all the grades from 16 onwards
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text) // return the number of letters in text
{
    int letters = 0;                 // start at 0 to get the result
    int length = strlen(text);       // simpler to use
    for (int i = 0; i < length; i++) // for loop to count all the letters
    {
        if (isalpha(text[i])) // is alpha to only count alphabetical
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text) // returns the number of words
{
    int words = 1;                   // Starts already counting the first word
    int length = strlen(text);       // same thing, simpler
    for (int i = 0; i < length; i++) // for loop now counting words
        if (isspace(text[i]))        // checks every word by counting the spaces
        {
            words++;
        }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' ||
            text[i] == '?') // all the sentence-ending punctuation
        {
            sentences++;
        }
    }
    return sentences;
}

int CL_index(int letters, int words, int sentences) // calculates the grade here in a function
{

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}
