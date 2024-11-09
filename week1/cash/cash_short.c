#include <cs50.h>
#include <stdio.h>
// make as a constant all the coin values
const int Q = 25;
const int D = 10;
const int N = 5;
const int P = 1;
const int NUM_COINS = 4;

int main(void)
{
    int cents;
    // it's between 1 and 99 because the measurement is in cents
    do
    {
        cents = get_int("change owed in cents: ");
    }
    while (cents < 1 || cents > 99);

    int coin_values[NUM_COINS] = {Q, D, N, P};
    int total_coins = 0;

    for (int i = 0; i < NUM_COINS; i++)
    {
        int num_coins = cents / coin_values[i];
        total_coins += num_coins;
        cents = cents % coin_values[i];
    }
    printf("%i\n", total_coins);
}
