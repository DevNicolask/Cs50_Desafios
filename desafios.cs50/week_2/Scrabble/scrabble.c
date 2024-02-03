// Include the libraries I will use.
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Declaration for global variables.
int player1Score = 0;
int player2Score = 0;

// Functions prototypes.
void removeSymbols(char response[], char word[]);
int calculateLengthWithoutSymbols(char word[], int length);
void convertToUpperCase(char word[], char upperCaseWord[], int length);
int calculateScoreForWord(char word[], int length);

// Function Principal
int main(void)
{
    // Get the word chosen by both users.
    string player1Response = get_string("Player 1: ");
    string player2Response = get_string("Player 2: ");

    // Analisys of the word that user 1 typed.
    int length1 = strlen(player1Response);

    // Criate a variable to store the new word without symbols.
    char word1[length1];

    // Removes all symbols from the variable "word1".
    removeSymbols(player1Response, word1);

    // Calculates how many symbols have in the variable "word1".
    int lengthWithoutPunctuation1 = calculateLengthWithoutSymbols(word1, length1);

    // Add 1 to account for null terminator, becase I remove it when i removed all the symbols.
    char upperCaseWord1[lengthWithoutPunctuation1 + 1];

    // Converts all letters from "word1" to upper case.
    convertToUpperCase(word1, upperCaseWord1, lengthWithoutPunctuation1);

    // Calculates the pontuation of player 1 word in scrabble.
    int score1 = calculateScoreForWord(upperCaseWord1, lengthWithoutPunctuation1);
    // Ended of analisys from player 1.

    // Analisys of the word that user 2 typed.
    int length2 = strlen(player2Response);

    // Criate a variable to store the new word without symbols.
    char word2[length2];

    // Removes all symbols from the variable "word2".
    removeSymbols(player2Response, word2);

    // Calculates how many symbols have in the variable "word2".
    int lengthWithoutPunctuation2 = calculateLengthWithoutSymbols(word2, length2);

    // add 1 to account for null terminator, becase I remove it when i removed all the symbols.
    char upperCaseWord2[lengthWithoutPunctuation2 + 1];

    // Converts all letters from "word2" to upper case.
    convertToUpperCase(word2, upperCaseWord2, lengthWithoutPunctuation2);

    // Calculates the pontuation of player 2 word in scrabble.
    int score2 = calculateScoreForWord(upperCaseWord2, lengthWithoutPunctuation2);
    // Ended of analisys from player 2.

    // Determine the winner.
    if (score1 == score2)
    {
        printf("It's a Tie!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }

    return 0;
}

// Function to remove symbols and save only the word
void removeSymbols(char response[], char word[])
{
    int j = 0;

    for (int i = 0; response[i] != '\0'; i++)
    {
        if (isalpha(response[i]))
        {
            word[j] = response[i];
            j++;
        }
    }

    word[j] = '\0';
}

// Function to calculate length without symbols
int calculateLengthWithoutSymbols(char word[], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(word[i]))
        {
            count++;
        }
    }
    return count;
}

// Function to converts to upper case the word.
void convertToUpperCase(char word[], char upperCaseWord[], int length)
{
    for (int i = 0; i < length; i++)
        if (word[i] > 'Z')
        {
            upperCaseWord[i] = toupper(word[i]);
        }
        else
        {
            upperCaseWord[i] = word[i];
        }

    upperCaseWord[length] = '\0';
}

// Function to calculate score letter by letter in the word.
int calculateScoreForWord(char word[], int length)
{
    int score = 0;

    for (int i = 0; i < length; i++)
    {
        switch (word[i])
        {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                score += 1;
                break;
            case 'D':
            case 'G':
                score += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                score += 3;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                score += 4;
                break;
            case 'K':
                score += 5;
                break;
            case 'J':
            case 'X':
                score += 8;
                break;
            case 'Q':
            case 'Z':
                score += 10;
                break;
        }
    }

    return score;
}
