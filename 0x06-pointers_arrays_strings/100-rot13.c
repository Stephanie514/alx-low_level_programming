#include "main.h"

/**
 * rot13 - function that encodes a string using rot13.
 * @q: string
 *
 * Return: encoded string
 */

char *rot13(char *q)
{
int r, s;
char *alph1 = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
char *alph2 = {"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"};
for (r = 0; q[r] != '\0'; r++)
{
for (s = 0; s < 52; s++)
{
if (q[r] == alph1[s])
{
q[r] = alph2[s];
break;
}
}
}
return (q);
}
