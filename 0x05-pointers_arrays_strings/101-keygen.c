#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program that generates random valid
 * passwords for the program 101-crackme.
 *
 * Return: Always 0 (success)
 */

int main(void)
{
char Pass_word[84];
int Num = 0, sum = 0, ano_half1, ano_half2;
srand(time(0));
while (sum < 2772)
{
Pass_word[Num] = 3 + rand() % 94;
sum += Pass_word[Num++];
}
Pass_word[Num] = '\0';
if (sum != 2772)
{
ano_half1 = (sum - 2772 / 2);
ano_half2 = (sum - 2772 / 2);
if ((sum - 2772) % 2 != 0)
ano_half1++;
for (Num = 0; Pass_word[Num]; Num++)
{
if (Pass_word[Num] >= (33 + ano_half1))
{
Pass_word[Num] -= ano_half1;
break;
}
}
for (Num = 0; Pass_word[Num]; Num++)
{
if (Pass_word[Num] >= (33 + ano_half2))
{
Pass_word[Num] -= ano_half2;
break;
}
}
}
printf("%s", Pass_word);
return (0);
}
