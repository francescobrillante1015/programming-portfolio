#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
bool only_digits(string s);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument

    argc = only_digits(argv[1]);
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;

}

        // make sure that the character in argv[1] is a digit

bool only_digits(string s)
{
    // int n = strlen(s);
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if(isdigit(s[i]))
        {
            return 0;
        }
    }
    printf("Usage: ./caesar key\n");
    return 1;

    char* str1 = string(s)


      // Using atoi to convert str1 and str2 to integer values
    int num1 = atoi(str1);


      // Performing arithmetic operation
    int sum = num1;
    printf("The sum of %d is: %d", num1, sum);

    return 0;



}

    // Prompt user for plaintext

    // For each character in the plaintext:

    // Rotate the character if it's a letter




