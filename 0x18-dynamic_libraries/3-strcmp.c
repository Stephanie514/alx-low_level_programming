#include "main.h"

/**
 * _strcmp -  function that compares two strings.
 * @s1: pointer to first string
 * @s2: pointer to second string
 * Return: a value greater than 0 if string is greater
 * than the other, value less than 0 if string is
 * lesser than the other and 0 if strings equal
 */

int _strcmp(char *s1, char *s2)
{
int check_val, tally;
tally = 0;
while (s1[tally] == s2[tally] && s1[tally] != '\0')
{
tally++;
}
check_val = s1[tally] - s2[tally];
return (check_val);
}
