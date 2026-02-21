#include <stdio.h>
#include <cs50.h>

long get_user(void);

// amex 15 digits, starts with 34 or 37
// mastercard 16 digits, starts with 51, 52, 53, 54, or 55
// visa 13 or 16 digits, starts with 4

int main(void)
{
    //first we ask for user's cc number
    long cc_num = get_user();

    //get the number of digits in the cc_num
    int digits = 0;
    for (long i = 1 ; i < cc_num ; i *= 10)
    {
        digits++;
    }

    //get sum of every other digit multiplied by two starting with the number's second to last digit
    int first_sum = 0;
    long stld_num;
    int first_stld;
    int second_stld;
    for(long i = 1 ; i < cc_num ; i *= 100)
    {
        stld_num = (cc_num%(100*i)/(10*i))*2;

        if(stld_num > 9)
        {
            //seperate and add the two digits
            first_stld = stld_num/10;
            second_stld = stld_num%10;
            first_sum += first_stld + second_stld;
        }
        else
        {
            first_sum += stld_num;
        }
    }

    //get sum of digits not multiplied by two
    int second_sum = 0;
    long other_num;
    for(long i = 1 ; i < cc_num ; i *= 100)
    {
        other_num = cc_num%(10*i)/(1*i);
        second_sum += other_num;
    }

    //get total sum
    int total_sum = first_sum + second_sum;

    //check if total sum's last digit is 0
    const long AMEX_15c = 10000000000000;
    const long MASTERCARD_16c = 100000000000000;
    const long VISA_16c = 1000000000000000;
    const long VISA_13c = 1000000000000;
    if(total_sum % 10 == 0)
    {
        // check digits if it belongs to amex, mastercard, or visa
        if(digits == 15 && (cc_num/AMEX_15c == 34 || cc_num/AMEX_15c == 37))
        {
            printf("AMEX\n");
        }
        else if(digits == 16 && (cc_num/MASTERCARD_16c == 51 || cc_num/MASTERCARD_16c == 52 || cc_num/MASTERCARD_16c == 53 || cc_num/MASTERCARD_16c == 54 || cc_num/MASTERCARD_16c == 55))
        {
            printf("MASTERCARD\n");
        }
        else if(digits == 16 && cc_num/VISA_16c == 4)
        {
            printf("VISA\n");
        }
        else if(digits == 13 && cc_num/VISA_13c == 4)
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

//create a function to get user's cc num
long get_user(void)
{
    long n;
    do
    {
    n = get_long("What is your credit card number? ");
    }
    while(n<1);
    return n;
}
