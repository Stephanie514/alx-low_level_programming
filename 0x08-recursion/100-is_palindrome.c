#include "main.h"

int palindrome_test(char *s, int g, int length);
int string_length_recursion(char *s);

/**
 * is_palindrome - function that returns 1 if a
 * string is a palindrome and 0 if not.
 * @s: the string to reverse
 * Return: 1 if a string is a palindrome and 0 if not.
 */

int is_palindrome(char *s)
{
if (*s == 0)
return (1);
return (palindrome_test(s, 0, string_length_recursion(s)));
}

/**
 * string_length_recursion - length of the string
 * @s: length of string to be calculated
 *
 * Return: string length
 */

int string_length_recursion(char *s)
{
if (*s == '\0')
return (0);
return (1 + string_length_recursion(s + 1));
}

/**
 * palindrome_test - checks characters for palindrome recursively
 * @s: the string to check
 * @g: iterator
 * @length: string length
 *
 * Return: 1 if palindrome, 0 if not
 */

int palindrome_test(char *s, int g, int length)
{
if (*(s + g) != *(s + length - 1))
return (0);
if (g >= length)
return (1);
return (palindrome_test(s, g + 1, length - 1));
}
