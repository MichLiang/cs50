#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // This is asking the username to input their name
    string name = get_string("What is your name?\n");
   
    // This is the response with the user's name
    printf("hello, %s\n", name);
}