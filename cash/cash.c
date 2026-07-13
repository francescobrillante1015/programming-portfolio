#include <cs50.h>
#include <stdio.h>

// Function for all change
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask for how much change is owned user input
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0); // Cant go into negtive

    int quarters = calculate_quarters(cents);

    cents = cents - (quarters * 25);

    int dimes = calculate_dimes(cents);

    cents = cents - (dimes * 10);

    int nickels = calculate_nickels(cents);

    cents = cents - (nickels * 5);

    int pennies = calculate_pennies(cents);

    int total_coins = quarters + dimes + nickels + pennies;
    printf("%d\n", total_coins);
}

int calculate_quarters(int cents)
{

    return cents / 25;
}

int calculate_dimes(int cents)
{

    return cents / 10;
}

int calculate_nickels(int cents)
{

    return cents / 5;
}

int calculate_pennies(int cents)
{

    return cents;
}
