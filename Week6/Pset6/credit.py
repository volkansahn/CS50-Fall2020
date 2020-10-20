from cs50 import get_int

number = get_int("Number: ")

digits = [int(x) for x in str(number)]

if len(digits) != 13 and len(digits) != 15 and len(digits) != 16:
    print("INVALID")

total = 0

for i in range(len(digits) - 1, 0, 2):
    total = total + sum(int(x) for x in str(digits[i] * 2))

for j in range(len(digits) - 2, 0, 2):
    total = total + digits[j]

if total % 10 == 0:
    if digits[0] == 3 and (digits[1] == 4 or digits[1] == 7):
        print("AMEX")
    elif digits[0] == 5 and (digits[1] == 1 or digits[1] == 2 or digits[1] == 3 or digits[1] == 4 or digits[1] == 5):
        print("MASTERCARD")
    elif digits[0] == 4:
        print("VISA")
else:
    print("INVALID")
