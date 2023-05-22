#include "dog.h"
#include <stdlib.h>

int _string_L(char *stri);
char *_string_copy(char *dest, char *src);
dog_t *new_dog(char *name, float age, char *owner);

/**
 * _string_L -finds the length os string
 * @stri: string to be measured
 *
 * Return: length of string
 */

int _string_L(char *stri)
{
int length = 0;
while (*stri++)
length++;
return (length);
}

/**
 * _string_copy - this copies a string of char pointed by src
 * including null byte, to a buffer pointed by dest
 * @dest: stores string copy, buffer
 * @src: source string
 *
 * Return: pointer to dest
 */

char *_string_copy(char *dest, char *src)
{
int pos = 0;
for (pos = 0; src[pos]; pos++)
dest[pos] = src[pos];
dest[pos] = '\0';
return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of dog
 *
 * Return: new struct of dog
 */

dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *d;
if (name == NULL || age < 0 || owner == NULL)
return (NULL);
d = malloc(sizeof(dog_t));
if (d == NULL)
return (NULL);
d->name = malloc(sizeof(char) * (_string_L(name) + 1));
if (d->name == NULL)
{
free(d);
return (NULL);
}
d->owner = malloc(sizeof(char) * (_string_L(owner) + 1));
if (d->owner == NULL)
{
free(d->name);
free(d);
return (NULL);
}
d->name = _string_copy(d->name, name);
d->age = age;
d->owner = _string_copy(d->owner, owner);
return (d);
}
