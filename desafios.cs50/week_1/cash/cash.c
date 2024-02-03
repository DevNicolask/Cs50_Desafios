#include <cs50.h>
#include <stdio.h>

// Declaration of prototypes.
int testx(int num, int x);

int main(void)
{
    int number = 0;
    do
    {
        number = get_int("Change owed: ");
    }
    while (number < 0);

    // Test from how many times this number is divisible for x, and save this in the variable coinsx.
    int coins25 = testx(number, 25);
    number = number % 25;

    int coins10 = testx(number, 10);
    number = number % 10;

    int coins5 = testx(number, 5);
    number = number % 5;

    int coins1 = testx(number, 1);

    // Add all numbers in the variable coinsx in coins.
    int coins = (coins25 + coins10 + coins5 + coins1);

    // Print the numbers of coins in total.
    printf("%i\n", coins);
}

int testx(int num, int x)
{
    int contcoins = 0;
    while (num >= x)
    {
        num -= x;
        contcoins += 1;
    }
    return contcoins;
}
