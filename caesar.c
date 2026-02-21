#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char rotate(char text, int key);
bool only_digits(string num);

int main(int argc, string argv[])
{
    if(argc == 2 && only_digits(argv[1]))
    {
        const int key = atoi(argv[1]);
        string plain_text = get_string("plaintext: ");
        int len = strlen(plain_text);
        // new : here i am going to create an array of characters
        // new : read ur notes for string definition
        char ciphertext[len]; // old : i think that ciphertext needs to be declared as char here so that the for loop under this works, you can only assemble back characters into strings. the other way around only works if u do string[i].
        // put the rotated character/s into an array
        for(int i = 0 ; i < len + 1; i++)
        {
            ciphertext[i] = rotate(plain_text[i], key);
        }
        printf("ciphertext: %s\n", ciphertext); // here we can print as a string bc an array of characters is a string (one memory block is gonna be reserved for nul as default)
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// rotate all the alphabetical characters inside the string

char rotate(char text, int key)
{
    if(islower(text))
    {
        return ((text - 'a' + key) % 26) + 'a';
    }
    else if(isupper(text))
    {
        return ((text - 'A' + key) % 26) + 'A';
    }
    else
    {
        return text;
    }
}

// check if input is a number
// check if the string (input) have only digits

bool only_digits(string num)
{
    int i = 0;
    int len = strlen(num);
    do
    {
        if(!isdigit(num[i]))
        {
            return false;
        }
        i++;
    }
    while(i < len);
    return true;
}
