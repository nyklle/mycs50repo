#include <stdio.h>
#include <cs50.h>

void rows(int blocks, int spaces);
int get_height(void);
void pyramid(int height);

int main(void)
{
    int tall = get_height();
    pyramid(tall);
}

//create a function to make the pyramid
void pyramid(int height)
{
    for (int i = 1 ; i < height + 1 ; i++)
    {
        rows(i, height - i);
        printf("\n");
    }
}


//create a function to ask the user how tall the pyramid is
int get_height(void)
{
    //get input from user
    int n;
    //re-prompt the user if input is a negative number
    do
    {
        n = get_int("How tall is the pyramid? ");
    }
    while (n < 1 || n > 50); //limit how tall the pyramid can be (personal modification as per duckie's advice)
    return n;
}

//create a function to make the rows for the left side of the pyramid
void rows(int blocks, int spaces)
{
    //add spaces so that the pyramid starts from the right
    for (int i = spaces ; i > 0 ; i--)
    {
        printf(" ");
    }
    //right side of pyramid row
    for (int i = 0 ; i < blocks ; i++)
    {
        printf("#");
    }
    //gap between two pyramid
    printf("  ");
    //left side of pyramid row
    for (int i = 0 ; i < blocks ; i++)
    {
        printf("#");
    }
}
