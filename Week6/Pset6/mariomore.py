from cs50 import get_int

height = get_int("Height: ")

while height > 8 or height <= 0:
    height = get_int("Height: ")

for i in range(height):
    print(" " * (height - 1 - i) + "#" * (i+1) + "  " + "#" * (i+1))
