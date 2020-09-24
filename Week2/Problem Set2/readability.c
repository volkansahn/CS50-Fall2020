#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text, int text_length);
int count_words(string text, int text_length);
int count_sentences(string text, int text_length);
int calculate_grade(int number_of_letters, int number_of_words, int number_of_sentences);
int rounding(float index);

int main(void)
{
    string user_text = get_string("Text : ");
    int text_length = strlen(user_text);
    int number_of_letters = count_letters(user_text, text_length);
    int number_of_words = count_words(user_text, text_length);
    int number_of_sentences = count_sentences(user_text, text_length);
    int grade = calculate_grade(number_of_letters, number_of_words, number_of_sentences);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }


}
// Count Letters
int count_letters(string text, int text_length)
{
    int total_letter_number = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            total_letter_number = total_letter_number + 1;
        }
    }
    return total_letter_number;
}
// Count Words
int count_words(string text, int text_length)
{
    int total_word_number = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == 32 || ((text[i] == 46 || text[i] == 33 || text[i] == 63) && text[i + 1] == 0))
        {
            total_word_number = total_word_number + 1;
        }
    }
    return total_word_number;
}
// Count sentences
int count_sentences(string text, int text_length)
{
    int total_sentences_number = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            total_sentences_number = total_sentences_number + 1;
        }
    }
    return total_sentences_number;
}
// Calculate Grade with The Coleman-Liau index Formula
int calculate_grade(int number_of_letters, int number_of_words, int number_of_sentences)
{
    float average_number_of_letters = 100 * (number_of_letters / (float) number_of_words);
    float average_number_of_sentences = 100 * (number_of_sentences / (float) number_of_words);
    float index = 0.0588 * average_number_of_letters - 0.296 * average_number_of_sentences - 15.8;
    int grade = rounding(index);
    return grade;
}
// Round nearest number
int rounding(float index)
{
    float temp_index = index * 10;
    int remaining = (int)temp_index % 10;
    if (remaining >= 5)
    {
        return (int)index + 1;
    }
    else
    {
        return (int)index;
    }
}
