#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* main - function that generates passwords for crackme
* @argc: Number of arguments supplied
* @argv: Array of pointers
*
* Return: 0
*/

int main(int __attribute__((__unused__)) argc, char *argv[])
{
char pswd[7], *mscript;
int l = strlen(argv[1]), a, var;

mscript = "A-CHRDw871NS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
var = (l ^ 59) & 63;
pswd[0] = mscript[var];

var = 0;
for (a = 0; a < l; a++)
var += argv[1][a];
pswd[1] = mscript[(var ^ 79) & 63];

var = 1;
for (a = 0; a < l; a++)
var *= argv[1][a];
pswd[2] = mscript[(var ^ 85) & 63];

var = 0;
for (a = 0; a < l; a++)
{
if (argv[1][a] > var)
var = argv[1][a];
}
srand(var ^ 14);
pswd[3] = mscript[rand() & 63];

var = 0;
for (a = 0; a < l; a++)
var += (argv[1][a] * argv[1][a]);
pswd[4] = mscript[(var ^ 239) & 63];

for (a = 0; a < argv[1][0]; a++)
var = rand();
pswd[5] = mscript[(var ^ 229) & 63];

pswd[6] = '\0';

printf("%s", pswd);
return (0);
}
