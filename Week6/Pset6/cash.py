from cs50 import get_float

number = get_float("Change owed: ")

while number < 0:
    number = get_float("Change owed: ")

number = number * 100
counter = 0
remainder = 0

if number / 25 > 1:
    counter = counter + int(number / 25)
    remainder = number % 25

if remainder / 10 > 1:
    counter = counter + int(remainder / 10)
    remainder = remainder % 10

if remainder / 5 > 1:
    counter = counter + int(remainder / 5)
    remainder = remainder % 5

counter = counter + remainder
print(int(counter))
