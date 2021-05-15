#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompt for input
    long c = get_long("Please input a credit card number: ");
    
    // Find total number of digits
    int digits = log10(c) + 1;
    
    // Multiply every other digit by 2 starting with number's second to last digit, and add those products' digits together
    // Variable = 0
    
    int secondSum = 0;
    
    long secondC = c / 10;
    
    while (secondC > 0)
    {
        // Underline the digit that's most on the right
        int last = secondC % 10;

        // Multiply the total by 2
        last *= 2;

        if (last >= 10)
        {
            int lastOnes = last % 10;
            int lastTens = last / 10;
            secondSum += lastOnes + lastTens;
        }
        else
        {
            secondSum += last;
        }

        // Delete 2 digits to get the next one
        secondC /= 100;
        
        // Repeat
    }

    // Add the sum to the sum of the digits that weren't multiplied by 2
    long firstC = c;
    int firstSum = 0;
    
    while (firstC > 0)
    {
        int last = firstC % 10;
        firstSum += last;
        firstC /= 100;
    }
    int sum = firstSum + secondSum;
  
    // If total last digit = 0, the number is valid
    int last = sum % 10;
    int first = c / pow(10, digits - 2);
    int firstVISA = c / pow(10, digits - 1);
    // Printing the possible outcomes
    
    if (last != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    
    if ((first == 34 || first == 37) && (digits == 15))
    {
        printf("AMEX\n");
        return 0;
    }

    if ((firstVISA == 4) && (digits == 13 || digits == 16))
    {
        printf("VISA\n");
        return 0;
    }
    
    if ((first >= 51 && first <= 55) && (digits == 16))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    printf("INVALID\n");
}
