from cs50 import get_string

text = get_string("Text: ")
letter_sum = 0
word_sum = 0
sentences_sum = 0
i = 0
for char in range(0,len(text)):

    if (ord(text[char]) > 64 and ord(text[char]) < 91) or (ord(text[char]) > 96 and ord(text[char]) < 123):
        letter_sum += 1
    elif ord(text[char]) == 32:
        word_sum += 1

    elif ((ord(text[char]) == 46 or ord(text[char]) == 63 or ord(text[char]) == 33) and (char == len(text) - 1)):
        word_sum += 1
        sentences_sum += 1

    elif ord(text[char]) == 46 or ord(text[char]) == 63 or ord(text[char]) == 33:
        sentences_sum += 1

average_number_of_letters = 100 * (letter_sum / word_sum);
average_number_of_sentences = 100 * (sentences_sum / word_sum);
index = 0.0588 * average_number_of_letters - 0.296 * average_number_of_sentences - 15.8;

print(f"Grade {int(index)}")
