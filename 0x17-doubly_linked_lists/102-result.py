#!/usr/bin/python3

def is_palindrome(n):
    return str(n) == str(n)[::-1]

largest_palindrome = 0

for a in range(100, 1000):
    for b in range(100, 1000):
        product = a * b
        if is_palindrome(product) and product > largest_palindrome:
            largest_palindrome = product

with open("102-result", "w") as file:
    file.write(str(largest_palindrome))
