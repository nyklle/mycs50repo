#include <stdio.h>
#include <cs50.h>

void rows (int spaces, int blocks);
int get_height(void);
void pyramid (int height);

int main(void)
{
    //create columns
    int n = get_height();
    pyramid (n);
}

//create a function for columns
void pyramid (int height)
{
    for(int i = 1 ; i < height + 1 ; i++)
    {
        rows(height - i, i);
        printf("\n");
    }
}

//create a function for rows
void rows (int spaces, int blocks)
{
    for(int i = spaces ; i > 0 ; i--)
    {
        printf(" ");
    }
     for(int j = 0 ; j < blocks ; j++)
    {
        printf("#");
    }
}

//create a function to get height
int get_height(void)
{
    int height;
    //prompt user for pyramid height
    do
    {
        height = get_int("How high is the pyramid? ");
    }
    while (height < 1);
    return height;
}
