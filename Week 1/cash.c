#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int numCoins = 0;

    float d = get_float("How much change is owed?\n");
    while (d < 0)
    {
        printf("Please input a non-negative amount\n");
        d = get_float("How much change is owed?\n");
    }

    // Convert dollars to cents (c) and round cents
    int c = round(d * 100);

    // Quarters first
    numCoins += c / 25;
    c %= 25;
    
    // Dimes 
    numCoins += c / 10;
    c %= 10;
    
    // Nickels
    numCoins += c / 5;
    c %= 5;
    
    // Pennies
    numCoins += c;
    c %= 1;
    
    // Show number of coins used to give change
    printf("change owed: %i\n", numCoins);
}
