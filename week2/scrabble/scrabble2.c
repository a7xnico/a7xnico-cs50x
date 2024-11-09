#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// the values of every number from A to Z
const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// Assigning the score to every letter
int char_score(char c);
// the total score
int compute_score(string word);
// function to validate if the user inputs a word
bool is_valid_input(string word);

int main(void)
{
    string word1;
    do
    {
        word1 = get_string("Player 1: "); // ask the user for two words
    }
    while (strlen(word1) == 0 || !is_valid_input(word1));
    string word2;
    do
    {
        word2 = get_string("Player 2: ");
    }
    while (strlen(word2) == 0 || !is_valid_input(word2));

    int score1 = compute_score(word1); // compute the score of both of them
    int score2 = compute_score(word2);
    // declare the word with the highest score
    if (score1 > score2) // Player 1 wins
    {
        printf("PLAYER 1 WINS!\n"); // the winner is player 1
    }
    else if (score2 > score1) // player 2 wins)
    {
        printf("PLAYER 2 WINS!\n"); // the winner is player 2
    }
    else
    {
        printf("IT'S A TIE!\n"); // it's a tie
    }
}

int char_score(char c)
{
    if (isupper(c)) // Takes the uppercase
    {
        return POINTS[c - 'A']; // gives the value to all letters in the array in uppercase
    }
    else if (islower(c)) // Takes the lowercase
    {
        return POINTS[c - 'a']; // gives the value of all letters in the array in lowercase
    }
    return 0;
}

int compute_score(string word)
{
    int score = 0;                   // tracks the score starting from 0
    int length = strlen(word);       // strlen(word) counts the letters in a word
    for (int i = 0; i < length; i++) // repeats this loop for every letter
    {
        if (isalpha(word[i]))
        {
        score += char_score(word[i]); // The total sum of all the values in a word
        }
    }
    return score; // Gives final score to the main function
}

bool is_valid_input(string word)
{
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        if(!isalpha(word[i]))
        {
            return false;
        }
    }
    return true;
}
