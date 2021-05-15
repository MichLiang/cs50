#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start = get_int("The starting size of the llama population is: ");
    while (start < 9) 
    {
        printf("start population needs to be greater or equal to 9\n");
        start = get_int("The starting size of the llama population is: ");
    }
    
    // TODO: Prompt for end size
    int end = get_int("The ending size of the llama population is: ");
  
    while (end < start)
    {
        printf("end population needs to be greater or equal to the starting population\n");
        end = get_int("The ending size of the llama population is: ");
    }
   
    // TODO: Calculate number of years until we reach threshold
    int numYears = 0;
    int p = start;
    
    while (p < end)
    {
        p = p + (p / 3) - (p / 4);
        numYears++;
    }
    
    // TODO: Print number of years
    printf("Years: %i\n", numYears);
}
