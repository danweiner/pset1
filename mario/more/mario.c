#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get int between 0 and 23 not inclusive
    int numrows;
    do {

        numrows = get_int("Enter size of pyramid: ");
        if (numrows < 0 || numrows > 23) {
            printf("Number must be greater than 0 and less than 23\n");
        }

    }
    while (numrows < 0 || numrows > 23);


    // print mario pyramid
    for(int i = 0; i < numrows; i++){

        for(int j = 0; j < numrows-(i + 1); j++) {
            printf(" ");
        }
        for(int k = 0; k < i + 1; k++) {
            printf("#");
        }

        for(int l = 0; l < 2; l++) {
            printf(" ");
        }

        for(int k = 0; k < i + 1; k++) {
            printf("#");
        }
        printf("\n");
    }
}