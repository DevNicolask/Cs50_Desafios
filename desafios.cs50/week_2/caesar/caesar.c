// Includes libraries that I will use
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int start(int argc, string argv[]);
void encrypt(char phrase[], int l, int key);

int main(int argc, string argv[])
{
    int n = 0;
    n = start(argc, argv);

    if (n != 1)
    {
        string phrase = get_string("plaintext: ");

        // Finds the Key to the phrase.
        int key = atoi(argv[1]);

        // Finds the length to the phrase.
        int length = strlen(phrase);

        // Does the cryptation.
        encrypt(phrase, length, key);
    }
    return n;
}

// Verify if argc is different of two and if the secund value for string srgv[], that is char argv[1], is an integer number.
int start(int argc, string argv[])
{
    if (argc != 2) // Verify if argc is different of 2.
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Pointer for the function strtol.
    char *endptr;

    // Verifies if argv[1] is a number integer, this is, if argv[1] is an number convertible for the decimal base.
    // If "yes" strtol does the pointer point to the null char '\0'.
    // Else, strtol points to the first char that's not convertible.
    long key = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0')
    {
        printf("Usage: ./caesar key\n"); // Error message
        return 1;
    }
    return 0;
}

// Encryptation function.
void encrypt(char phrase[], int l, int key)
{
    // Declaration for the variables to the ciphertext.
    char ciphertext[l];

    for (int i = 0; i < l; i++)
    {
        // Uses a different parameter depending on the type of letter the character is (Uppercase or lowercase).
        // Note: The character 'A' and 'a' is assigned to the variable "type" as an int, that is, its form in the ASCII table.
        int type = isupper(phrase[i]) ? 'A' : 'a';

        // Verifies char by char that char's a letter for to crypt just alphabet simbols.
        if (isalpha(phrase[i]))
        {
            // Makes the cipher text using the Caesar's formula!
            // Note: The 'type' needs to be shortened from 'phrase' so that the modulus of 26 results in a number between 0 and 25.
            // After that, I add 'type' again to correct the character's position in the ASCII table.
            ciphertext[i] = ((phrase[i] - type + key) % 26) + type;
        }
        else
        {
            // Repeats the simbol to the ciphertext.
            ciphertext[i] = phrase[i];
        }
    }

    // Shows the ciphertext in the terminal.
    printf("ciphertext: %s\n", ciphertext);
}
