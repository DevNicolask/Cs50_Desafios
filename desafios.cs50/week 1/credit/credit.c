#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Prototypes of all the functions that I created.
int count_digit(long n);
bool test_visa(long n);
bool test_amex(long n);
bool test_visa_mastercard(long n);
string master_visa(long n);
bool luhn_algorithm(int dgts, long n);
void test(bool answers, string cd, string err);

int main(void)
{
    // Loop to the answer of the user
    long number = 0;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);

    // Initialization of variables
    int digits = count_digit(number);
    bool result = false;
    string error = "INVALID";

    // If the number has 13 digits it will do this;
    if (digits == 13)
    {
        string card = "VISA";
        result = test_visa(number) && luhn_algorithm(digits, number);
        test(result, card, error);
    }

    // If the number has 15 digits it will do this;
    else if (digits == 15)
    {
        string card = "AMEX";
        result = test_amex(number) && luhn_algorithm(digits, number);
        test(result, card, error);
    }

    // If the number has 16 digits it will do this;
    else if (digits == 16)
    {
        string card = master_visa(number);
        result = test_visa_mastercard(number) && luhn_algorithm(digits, number);
        test(result, card, error);
    }

    // If the number doesn't have the number of digits on any card;
    else
    {
        printf("%s\n", error);
    }
}

// Function to count digits
int count_digit(long n)
{
    int digits = 0;
    do
    {
        n /= 10;
        digits += 1;
    }
    while (n != 0);
    return digits;
}

// Function to test if the number could be from AMEX
bool test_amex(long n)
{
    int start = (n / pow(10, 13)); // 10^13
    return start == 34 || start == 37;
}

// Function to test if the number could be from VISA
bool test_visa(long n)
{
    int start = (n / pow(10, 12));
    return (start == 4);
}

// Function to test if the number could be from AMEX or from VISA. If yes, I had other test for after.
bool test_visa_mastercard(long n)
{
    bool result = false;
    int start = (n / pow(10, 15));
    if (start == 4)
    {
        result = true;
    }
    start = (n / pow(10, 14));
    if (start == 51 || start == 52 || start == 53 || start == 54 || start == 55)
    {
        result = true;
    }
    return result;
}

// Function to determine whether the number is from MASTERCARD or VISA
string master_visa(long n)
{
    string result = "";
    int start = (n / pow(10, 14));
    if (start == 51 || start == 52 || start == 53 || start == 54 || start == 55)
    {
        result = "MASTERCARD";
    }
    else
    {
        result = "VISA";
    }
    return result;
}

// Final test, shows whether the card exists or not.
void test(bool answers, string cd, string err)
{
    if (answers == true)
    {
        printf("%s\n", cd);
    }
    else
    {
        printf("%s\n", err);
    }
}

// Function to perform Luhn's algorithm
bool luhn_algorithm(int dgts, long n)
{
    // Variables to accumulate sums
    int add = 0;

    // If the number of digits is 13. (Test with the Luhn's Algorithm)
    if (dgts == 13)
    {
        long number = n;
        int digit = 0;

        // Loop for to split digits 2-by-2
        for (int i = (dgts - 1); i >= 0; i -= 1)
        {
            if(i % 2 == 0)
            {
                digit = (number % 10);
            }
            else
            {
                digit = (number % 10) * 2;
            }

                // Add every number with more than one digit
                if (digit > 9)
                {
                    digit = (digit % 10) + (digit / 10);
                }
            number /= 10;
            add += digit;
        }
    }

    // If the number of digits is 15. (Test with the Luhn's Algorithm)
    else if (dgts == 15)
    {
        long number = n;
        int digit = 0;

        // Loop for to split digits 2-by-2
        for (int i = (dgts - 1); i >= 0; i -= 1)
        {
            if(i % 2 == 0)
            {
                digit = (number % 10);
            }
            else
            {
                digit = (number % 10) * 2;
            }

                // Add every number with more than one digit
                if (digit > 9)
                {
                    digit = (digit % 10) + (digit / 10);
                }
            number /= 10;
            add += digit;
        }
    }

     // If the number of digits is 16. (Test with the Luhn's Algorithm)
    else if (dgts == 16)
    {
        long number = n;
        int digit = 0;

        // Loop for to split digits 2-by-2
        for (int i = (dgts - 1); i >= 0; i -= 1)
        {
            if (i % 2 == 0)
            {
                digit = (number % 10) * 2;
            }
            else
            {
                digit = (number % 10);
            }

                // Add every number with more than one digit
                if (digit > 9)
                {
                    digit = (digit % 10) + (digit / 10);
                }
            number /= 10;
            add += digit;
        }
    }
 
    // Return the result of Luhn's algorithm
    return ((add % 10) == 0);
}
