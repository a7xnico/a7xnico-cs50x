#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
int compute_score(string word);

int main(void)
{
    string word1;
    do
    {
          word1 = get_string("Player 1: ");   // ask the user for two words
    }
    while (strlen(word1) == 0);
    string word2;
    do
    {
           word2 = get_string("Player 2: ");
    }
    while (strlen(word2)  == 0);

    int score1 = compute_score(word1);   // compute the score of both of them
    int score2 = compute_score(word2);
    // declare the word with the highest score
    if (score1 > score2) // Player 1 wins
    {
        printf("P LAYER1 WINS!\n"); // the winner is player 1
    }
    else if (score2 > score1)//player 2 wins)
    {
        printf("PLAYER 2 WINS!\n"); // the winner is player 2
    }
    else
    {
        printf("IT'S A TIE!\n"); //it's a tie
    }
}

int compute_score(string word)
{   // Values of all the letters from a to z
    const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0; // track score, start at 0

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}
