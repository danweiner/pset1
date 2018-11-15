#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    long long ll = get_long_long("Enter an input: ");

    char buffer[17];

    sprintf(buffer,"%lld", ll);

    int total_multiplied = 0;
    for(int n = strlen(buffer) - 2, i = n; i >= 0; i -= 2) {
        int conv_to_num = buffer[i] - '0';
        conv_to_num = conv_to_num * 2;

        char b[2];
        sprintf(b, "%i", conv_to_num);

        for(int j = 0, m = strlen(b); j < m; j++) {
            int conv_n = b[j] - '0';
            total_multiplied = total_multiplied + conv_n;
        }
    }

    int total_others = 0;
    int str_len = strlen(buffer);
    if (str_len % 2 == 0) {
        for (int i = 1; i < str_len; i+= 2) {

            int conv = buffer[i] - '0';
            total_others = total_others + conv;
        }
    } else {
        for (int i = 0; i < str_len; i+= 2) {

            int conv = buffer[i] - '0';
            total_others = total_others + conv;
        }
    }
    int checksum = total_multiplied + total_others;
    for (int i = 0, n = strlen(buffer); i < n; i++) {

        if (checksum % 10 == 0 && (n == 15) && ((buffer[0] == '3' && buffer[1] == '7')
        || (buffer[0] == '3' && buffer[1] == '7')))
        {
            printf("AMEX\n");
            break;
        }  else if (checksum % 10 == 0 && (n == 16) && ((buffer[0] == '5' && buffer[1] == '1')
        || (buffer[0] == '5' && buffer[1] == '2') || (buffer[0] == '5' && buffer[1] == '3') ||
        (buffer[0] == '5' && buffer[1] == '4') || (buffer[0] == '5' && buffer[1] == '5')))
        {
            printf("MASTERCARD\n");
            break;
        } else if (checksum % 10 == 0 && ((n == 13) || (n == 16)) && ((buffer[0] == '4')))
        {
            printf("VISA\n");
            break;
        } else {
            printf("INVALID\n");
            break;
        }
    }


}