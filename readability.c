#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int determine_grade(string text);

int main(void)
{
    string user_text = get_string("Text: ");
    int grade = determine_grade(user_text);
    if(grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

//count how many letters in total
//count how many words in total
//count how many sentences in total
//use the Coleman-Liau index formula

int determine_grade(string text)
{
    float index = 0.0588 * (count_letters(text) * 100.0 / count_words(text)) - 0.296 * (count_sentences(text) * 100.0 / count_words(text)) - 15.8;
    int grade = round(index);
    return grade;
}

int count_sentences(string text)
{
    int sentences = 0;
    for(int i = 0, n = strlen(text) ; i < n ; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

int count_words(string text)
{
    int spaces = 0;
    for(int i = 0, n = strlen(text) ; i < n ; i++)
    {
        if(text[i] == ' ')
        {
            spaces++;
        }
    }
    int words = spaces + 1;
    return words;
}

int count_letters(string text)
{
    int letters = 0;
    for(int i = 0, n = strlen(text) ; i < n ; i++)
    {
        if(isalnum(text[i]))
        {
            letters ++;
        }
    }
    return letters;
}
