#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);

int calculate_dimes(int cents);

int calculate_nickels(int cents);

int calculate_pennies(int cents);

int main(void)
{
    int cents;
    do
    { // pedirle al usuario cuanto cambio se le debe
        cents = get_int("change owed in cents: ");
    }
    while (cents < 0 || cents > 99); // el maximo es 99 debido a que solo se utilizan centavos

    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25); // restar el valor de estas monedas

    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10); // restar el valor de estas monedas

    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5); // restar el valor de estas monedas

    int pennies = calculate_pennies(cents);
    cents = cents - pennies; // restar el valor de estas monedas

    int coins =
        quarters + dimes + nickels + pennies; // sumar el numero de monedas de 25, 10, 5 y 1 centavo
    printf("number of coins: %i \n", coins);  // escribirselo al usuario
}
int calculate_quarters(int cents) // calcular cuantas monedas de 25 centavos deba de darle al
                                  // cliente
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents) // calcular cuantas monedas de 10 centavos deba de darle al cliente
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}
int calculate_nickels(int cents) // calcular cuantas monedas de 5 centavos deba de darle al cliente
{
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}
int calculate_pennies(int cents) // calcular cuantas monedas de 1 centavo deba de darle al cliente
{
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}
