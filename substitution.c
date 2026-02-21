#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check_key(string key);
char substitution(char old, string new);

int main(int argc, string argv[])
{
    if(argc == 2 && check_key(argv[1]))
    {
        string key = argv[1];
        string plain_text = get_string("plaintext: ");
        int len = strlen(plain_text);
        char cipher_text[len];
        for(int i = 0 ; i < len + 1 ; i++) //idk why but for this and the caesar one if i dont make it i < n + 1 it wont work.
        {
            cipher_text[i] = substitution(plain_text[i], key);
        }
        printf("ciphertext: %s\n", cipher_text);
        return 0;
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

//substitute characters
char substitution(char old, string new)
{
    char letter;
    if(islower(old))
    {
        letter = tolower(new[old - 'a']);
        return letter;
    }
    else if(isupper(old))
    {
        letter = toupper(new[old - 'A']);
        return letter;
    }
    else
    {
        return old;
    }
}

//check if key are all alphabetical and each character of the alphabet appears exactly once (is 26)
bool check_key(string key)
{
    int len = strlen(key);
    if (len != 26)
    {
        return false;
    }
    char mod_key[len + 1];
    for(int i = 0 ; i < len ; i++)
    {
        if(!isalpha(key[i]))
        {
            return false;
        }
    }
    for(int i = 0 ; i < len ; i++)
    {
        mod_key[i] = toupper(key[i]);
            for(int j = 0 ; j < i ; j++)
            {
                if(toupper(key[i]) == mod_key[j])
                {
                    return false;
                }
            }
    }
    return true;
}
