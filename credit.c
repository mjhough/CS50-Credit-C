#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long long cc_number;
    do  // Get user input as long long type and store in the variable 'cc_number'.
    {
        cc_number = get_long_long("Enter Card Number: ");
    }
    while (cc_number < 1000000000
           || cc_number > 5699999999999999);  // If the user did not enter a number withing a wide pre-check range, ask again.

    // Find length of credit card number
    int length = 0;
    long long num = cc_number;
    while (num != 0)
    {
        length++;
        num = num / 10;
    }

    // Find first two digits of credit card number
    int len = length;
    int first_two_digits = cc_number / pow(10, len -= 2);

    int sum_of_digits = 0;

    // Starting from the 2nd last digit, multiply every other digit by 2. Then take the result and sum the digits if >= 10.
    // Then add all the sums of the products' digits together
    for (int i = 2; i < length + 2; i += 2)
    {
        long long point = pow(10, i);
        int current_num = (cc_number % point) / (point / 10);
        int product = current_num * 2;
        sum_of_digits += product / 10 + product % 10;
    }
    // Starting from the last digit, add every other digit to the total sum of digits.
    for (int i = 1; i <= length; i += 2)
    {
        long long point = pow(10, i);
        int current_num = (cc_number % point) / (point / 10);
        sum_of_digits += current_num;
    }

    // Check if the sum of the digits results in a number divisible by 10 with no remainder.
    // If so, check what card it is. If not, print 'INVALID'.
    if (sum_of_digits % 10 == 0)
    {
        if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        if (length == 16 && first_two_digits >= 51 && first_two_digits <= 55)
        {
            printf("MASTERCARD\n");
        }
        if ((length == 13 || length == 16) && first_two_digits / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}