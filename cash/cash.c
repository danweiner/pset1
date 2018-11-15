#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float change;
    do {
        change = get_float("enter amount of change: ");
    }
    while(change < 0);
    change = change * 100;
    int numQuarters = 0;
    int numDimes = 0;
    int numNickels = 0;
    int numPennies = 0;
    while(change > .001) {
        if (change >= 24.99)
        {
            numQuarters++;
            change -= 25;
        }
        else if (change >= 9.99)
        {
            numDimes++;
            change -= 10;
        }
        else if (change >= 4.99)
        {
            numNickels++;
            change -= 5;
        }
        else
        {
            numPennies++;
            change -= 1;
        }
    }
    int totalCoins = numQuarters + numDimes + numNickels + numPennies;
    printf("%i\n", totalCoins);


}
