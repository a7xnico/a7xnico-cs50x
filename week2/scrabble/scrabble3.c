#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int POINTS[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const int MAX_PLAYERS = 5; // max amount of players, stops it from being too big
const int MIN_PLAYERS = 1; // minimum amoun, stops from failing if user inputs 0 or a negative
int char_score(char c);
int compute_score(string word);
bool is_valid_input(string word);
void get_player_scores(int num_players, string players[],
                       int scores[]); // gets the words and scores of every player
int main(void)
{
    int num_players;
    do
    {
        num_players = get_int("Number of players: "); // asks the user how many people are playing
        if (num_players < MIN_PLAYERS)
        {
            printf(
                "Please enter a positive number from %i to %i\n", MIN_PLAYERS, MAX_PLAYERS); // warning when the user inputs a wrong answer
        }
        else if (num_players >  MAX_PLAYERS)
        {
            printf("Please enter a number not greater than %i\n", MAX_PLAYERS); // informs the user of the limit of players for this code
        }
    }
    while (
        num_players < MIN_PLAYERS ||  num_players > MAX_PLAYERS); // this loop ensures that it only activates when the user inputs a positive number
    string players[num_players]; // manages the information of every player
    int scores[num_players];     // manages the score of every player

    get_player_scores(num_players, players, scores);

    // Determine the winner
    int max_score = scores[0];
    int winner = 0;
    for (int i = 1; i < num_players; i++)
    {
        if (scores[i] > max_score)
        {
            max_score = scores[i];
            winner = i;
        }
    }
    printf("PLAYER %i WINS!\n", winner + 1);
}

int char_score(char c)
{
    if (isupper(c))
    {
        return POINTS[c - 'A'];
    }
    else if (islower(c))
    {
        return POINTS[c - 'a'];
    }
    return 0;
}

int compute_score(string word)
{
    int score = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(word[i]))
        {
            score += char_score(word[i]);
        }
    }
    return score;
}

bool is_valid_input(string word)
{
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(word[i]))
        {
            return false;
        }
    }
    return true;
}

void get_player_scores(int num_players, string players[],
                       int scores[]) // asks to every player to select a word
{
    for (int i = 0; i < num_players; i++)
    {
        do
        {
            players[i] = get_string("Player %i: ", i + 1);
            if (strlen(players[i]) == 0 || !is_valid_input(players[i]))
            {
                printf("Invalid input. Please enter a valid word.\n"); // warns the user if there's
                                                                       // a wrong input
            }
        }
        while (strlen(players[i]) == 0 || !is_valid_input(players[i])); // checks for invalid inputs
        scores[i] = compute_score(
            players[i]); // collects the score for every player and puts it into the array
    }
}
