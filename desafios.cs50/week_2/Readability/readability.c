// Include the libraries I will use.
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Functions prototypes.
float CountLettlers(string text, int l);
float CountWords(string text, int l);
float CountSentences(string text, int l);
void results(float L, float W, float S);

int main(void)
{
    string text = get_string("Text: "); // Save the text of user in the varible text.

    const int length = strlen(text);
    float L = CountLettlers(text, length);
    float W = CountWords(text, length);
    float S = CountSentences(text, length);

    results(L, W, S);
}

// Counter of letters for the text.
float CountLettlers(string text, int l)
{
    int count = 0;
    for (int i = 0; i < l; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Counter of words for the text.
float CountWords(string text, int l)
{
    int count = 0;
    for (int i = 0; i < l; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return (count + 1);
}

// Counter of sentences for the text.
float CountSentences(string text, int l)
{
    int count = 0;
    for (int i = 0; i < l; i++)
    {
        char C = text[i];
        if (C == '!' || C == '.' || C == '?')
        {
            count++;
        }
    }
    return count;
}

// Results.
void results(float letters, float words, float sentences)
{
    // Coleman Liau Index Formula.
    float index = (0.0588 * (100 * (letters / words)) - (0.296 * (100 * (sentences / words))) - 15.8);

    int approximation = round(index);
    if (approximation <= 1)
    {
        printf("Before Grade 1");
    }
    else if (approximation > 1 && approximation < 16)
    {
        printf("Grade %i", approximation);
    }
    else
    {
        printf("Grade 16+");
    }
    printf("\n");
}
