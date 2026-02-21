#include <stdio.h>
#include <cs50.h>

int get_change(void);

int main(void)
{
    //set initial no. of coins to 0
    int coins = 0;

    //get user input for change owed
    int change = get_change();

    //loop for change to be given the least amounts of coins
    while(change > 0)
    {
        if(change >= 25)
        {
            change -=25;
            coins +=1;
        }
        else if(change >= 10)
        {
            change -=10;
            coins +=1;
        }
        else if(change >= 5)
        {
            change -=5;
            coins +=1;
        }
        else if(change >= 1)
        {
            change -=1;
            coins +=1;
        }
    }
    //print out coins
    printf("%i\n", coins);
}

//make a function to get user input for change
int get_change(void)
{
    int n;
    do
    n = get_int("Change owed: ");
    while(n < 1); //change must be greater than 0
    return n;
}
