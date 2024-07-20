#include <cs50.h>
#include <stdio.h>

int adding(long card_number);
int multiply_add(int last_digit);
int card_length(long card_number);

int main(void)
{

    // get card number and display it
    long card_number = get_long("Enter Card Number : ");
    printf("Number : %li\n", card_number);
    int len = card_length(card_number);

    int checksum = adding(card_number);
    // display service provider
    if (checksum % 10 == 0)
    {
        // get starting digits
        do
        {
            card_number = card_number / 10;
        }
        while (card_number >= 100);

        // for AmEx
        if ((card_number == 34 || card_number == 37) && len == 15)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }

        // for master card
        if (len == 16 && (card_number == 51 || card_number == 52 || card_number == 53 ||
                          card_number == 54 || card_number == 55))
        {
            printf("MASTERCARD\n");
        }

        // for visa, using if to resolve conflict with mastercard check
        if ((len == 13 || len == 16) &&
            (card_number == 40 || card_number == 41 || card_number == 42 || card_number == 43 ||
             card_number == 44 || card_number == 45 || card_number == 46 || card_number == 47 ||
             card_number == 48 || card_number == 49))
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

// new function for checksum
int adding(long card_number)
{
    int sum_a = 0;
    bool isAlt = false;

    while (card_number > 0)
    {
        if (isAlt == true)
        {
            int last_digit = card_number % 10;
            int multi = multiply_add(last_digit);
            sum_a = sum_a + multi;
        }
        else
        {
            int last_digit = card_number % 10;
            sum_a = sum_a + last_digit;
        }

        isAlt = !isAlt;
        card_number = card_number / 10;
    }
    return sum_a;
}

// new function to multiply every even digit from the end by 2 and add them individually if they are
// double digits
int multiply_add(int last_digit)
{
    int sum_b = 0;
    int product = last_digit * 2;

    while (product > 0)
    {
        int last_multiplied_digit = product % 10;
        sum_b = sum_b + last_multiplied_digit;
        product = product / 10;
    }
    return sum_b;
}

// function to get the length of card number
int card_length(long card_number)
{
    int digits = 0;

    do
    {
        card_number = card_number / 10;
        digits++;
    }
    while (card_number != 0);
    return digits;
}
