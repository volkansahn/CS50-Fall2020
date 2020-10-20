from cs50 import get_float

number = get_float("Change owed: ")

while number < 0:
    number = get_float("Change owed: ")

number = number * 100
counter = 0
remainder = 0

if number / 25 >= 1:
    counter = counter + int(number / 25)
    remainder_25 = number % 25
else:
    remainder_25 = number

if remainder_25 / 10 >= 1:
    counter = counter + int(remainder_25 / 10)
    remainder_10 = remainder_25 % 10
else:
    remainder_10 = remainder_25

if remainder_10 / 5 >= 1:
    counter = counter + int(remainder_10 / 5)
    remainder_5 = remainder_10 % 5
else:
    remainder_5 = remainder_10

counter = counter + remainder_5
print(int(counter))
