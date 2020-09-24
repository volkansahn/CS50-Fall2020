#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string cipher_text(string plaintext, string key);
bool is_valid(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.");
            return 1;
        }
        else
        {
            string key = argv[1];
            bool isValidKey = is_valid(key);
            if (isValidKey)
            {
                string plaintext = get_string("plaintext: ");
                printf("ciphertext: %s\n", cipher_text(plaintext, key));
                return 0;
            }
            else
            {
                printf("Invalid Key");
                return 1;
            }

        }
    }
    else
    {
        printf("Usage: ./substitution key");
        return 1;
    }
}
// Check If Key is Valid
bool is_valid(string key)
{
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(key[i]))
        {
            int equal = 0;
            for (int j = 0; j < length; j++)
            {
                if (key[i] == key[j])
                {
                    equal = equal + 1;
                }
            }
            if (equal > 1)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

// Get ciphertext with usign Key
string cipher_text(string plaintext, string key)
{
    int length = strlen(plaintext);
    char temp_cipher[length];
    printf("%s\n",plaintext);
    for (int i = 0; i < length; i++)
    {
        if isalpha(plaintext[i])
        {
            int temp_text = (int)plaintext[i];
            if (temp_text < 91)
            {
                temp_cipher[i] = toupper(key[temp_text - 65]);
            }
            else
            {
                temp_cipher[i] = tolower(key[temp_text - 97]);
            }
        }
        else
        {
            temp_cipher[i] = plaintext[i];
        }
    }
    string ciphertext = temp_cipher;
    return ciphertext;
}
