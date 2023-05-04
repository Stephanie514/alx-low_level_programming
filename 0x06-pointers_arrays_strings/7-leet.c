#include "main.h"

/**
 * leet - function that encodes a string into 1337.
 * Letters a and A should be replaced by 4
 * Letters e and E should be replaced by 3
 * Letters o and O should be replaced by 0
 * Letters t and T should be replaced by 7
 * Letters l and L should be replaced by 1
 * @z: pointer to string
 *
 * Return: pointer z
 */

char *leet(char *z)
{
int stringLength, tally_leet;
char l_letters[] = "aAeEoOtTlL";
char num_leet[] = "4433007711";
stringLength = 0;
while (z[stringLength] != '\0')
{
tally_leet = 0;
while (tally_leet < 10)
{
if (l_letters[tally_leet] == z[stringLength])
{
z[stringLength] = num_leet[tally_leet];
}
tally_leet++;
}
stringLength++;
}
return (z);
}
