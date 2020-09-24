#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int calculate_key(string argv);
int calculate_shift_value (int key);
string get_ciphertext(string plaintext, int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int arglen = strlen(argv[1]);
        for (int i = 0; i < arglen; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key");
                return 1;
            }
        }
        int key = calculate_key(argv[1]);
        int shift_value = calculate_shift_value(key);
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: %s\n", get_ciphertext(plaintext, shift_value));
        return 0;
    }
    else
    {
        printf("Not proper Key\n");
        return 1;
    }

}
// Get Key value from string argument
int calculate_key (string argv)
{
    int key = 0;
    int arglen = strlen(argv);
    int expnumber = arglen - 1;

    for (int i = 0; i < arglen; i++)
    {
        key = key + (pow(10, expnumber) * (argv[i] - 48));
        expnumber = expnumber - 1;
    }
    return key;
}
// Calculatin Shift value if it is greater that 26
int calculate_shift_value (int key)
{
    int shift_value = key % 26;
    return shift_value;
}
// Get ciphertext according to key
string get_ciphertext(string plaintext, int key)
{
    int text_length = strlen(plaintext);
    char ciphertext[text_length];

    for (int i = 0; i < text_length; i++)
    {
        if isalpha(plaintext[i])
        {
            int temp_char_dec = (int) plaintext[i] + key;
            if (((int)plaintext[i] < 90 && temp_char_dec > 90) || ((int)plaintext[i] > 90 && temp_char_dec > 122))
            {
                temp_char_dec = temp_char_dec - 26;
            }
            ciphertext[i] = temp_char_dec;
        }
        else
        {
            char text = plaintext[i];
            ciphertext[i] = text;
        }

    }
    string return_text = ciphertext;
    return return_text;
}
