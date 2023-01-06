#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Procedure to rotate numbers
void caesar(string plaintext, int rotate)
{
    int i = 0;
    //checks if we are not at the end of the string
    while (plaintext[i] != '\0')
    {
        //rotate for upper case characters
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            char c = plaintext[i] - 'A';
            c += rotate;
            c = c % 26;
            plaintext[i] = c + 'A';
        }

        //rotate for lower case characters
        else  if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            char c = plaintext[i] - 'a';
            c += rotate;
            c = c % 26;
            plaintext[i] = c + 'a';
        }
        i++;
    }

    //print the cyphered text
    printf("ciphertext:  %s", plaintext);
}
int main(int argc, string argv[])
{
    //check if the input at commend line is present
    if (argc == 2)
    {

        //converts string int to int for the key
        int k = atoi(argv[1]);
        //checks if the command line input is a digit or not
        for (size_t x = 0;  argv[1][x] != '\0'; x++)
        {
            if (!isdigit(argv[1][x]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        //get the plaintext and pass in through the procedure caesar for cypher
        string plaintext = get_string("plaintext:  ");
        caesar(plaintext, k);
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}