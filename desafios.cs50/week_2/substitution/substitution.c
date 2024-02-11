// Including necessary libraries.
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototypes.
int start(int argc, string argv[]);
void encript(string plaintext, int plaintextLength, char key[]);

int main(int argc, string argv[])
{
    // Checking if the correct number of command-line arguments is provided.
    int n = start(argc, argv);

    if (n == 0)
    {
        string key = argv[1]; // Assigning argv[1] to the variable 'key'.

        int keyLength = strlen(key); // Calculating the length from the key.

        string plaintext = get_string("plaintext: "); // Gets the plaintext from the user.
        int plaintextLength = strlen(plaintext);      // Calculating the length from the plaintext.

        encript(plaintext, plaintextLength, key); // This function encript and show the encriptated plaintext.
    }
    return n; // This is a command to the system that tells you whether this program ended correctly or not.
}

// Function to check the number of command-line arguments.
int start(int argc, string argv[])
{
    if (argc != 2) // Verifying if argc is different from 2.
    {
        printf("Usage: %s key\n", argv[0]); // If yes
        return 1;
    }

    // Checking if the key contains exactly 26 alphabetic characters.
    int keyLength = strlen(argv[1]);
    if (keyLength != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Checking if the key contains only alphabetic characters.
    for (int i = 0; i < keyLength; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
    }

    // Checking if the key not contains duplicate characters in uppercase or lowercase key.
    for (int i = 0; i < (keyLength - 1); i++)
    {
        for (int j = (i + 1); j < keyLength; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key dont must contain duplicate characters in uppercase or lowercase key\n");
                return 1;
            }
        }
    }
    return 0;
}

// Function to encript the string 'plaintext'.
void encript(string plaintext, int plaintextLength, char key[])
{
    char ciphertext[plaintextLength + 1]; // Declaration of char depending from length of plaintext and add one for th null char.

    for (int i = 0; i < plaintextLength; i++)
    {
        if (isalpha(plaintext[i])) // If the char are a alphabect char.
        {
            int type = isupper(plaintext[i]) ? 'A' : 'a';
            int position = (plaintext[i] - type);

            if (type <= 'Z') // This condition treats a different encrypted char depending on the type make plaintext.
            {
                ciphertext[i] = toupper(key[position]); // If the char from plaintext was in uppercase.
            }
            else
            {
                ciphertext[i] = tolower(key[position]); // If the char from plaintext was in lowercase
            }
        }
        else // Else If the char are'nt a alphabect char.
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[plaintextLength] = '\0';

    printf("ciphertext: %s\n", ciphertext); // Shows the encripted text.
}
