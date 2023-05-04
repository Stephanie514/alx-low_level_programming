#include "main.h"

/**
 * cap_string - function that capitalizes all words of a string.
 * @q: pointer to string
 *
 * Return: pointer to q
 */

char *cap_string(char *q)
{
int total_string = 0;

while (q[total_string] != '\0')
{
if (q[0] >= 97 && q[0] <= 122)
{
q[0] = q[0] - 32;
}
if (q[total_string] == ' ' || q[total_string] == '\t'
|| q[total_string] == '\n'
|| q[total_string] == ',' || q[total_string] == ';' || q[total_string] == '.'
|| q[total_string] == '.' || q[total_string] == '!' || q[total_string] == '?'
|| q[total_string] == '"' || q[total_string] == '(' || q[total_string] == ')'
|| q[total_string] == '{' || q[total_string] == '}')
{
if (q[total_string + 1] >= 97 && q[total_string + 1] <= 122)
{
q[total_string + 1] = q[total_string + 1] - 32;
}
total_string++;
}
else
{
total_string++;
}
}
return (q);
}

