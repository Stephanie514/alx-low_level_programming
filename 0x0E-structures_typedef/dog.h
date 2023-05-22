#ifndef DOG_H
#define DOG_H
#include <stdio.h>

/**
 * struct dog - struct of new type describing a dog
 * @name: The dog name
 * @age: age of dog
 * @owner: owner of dog
 */

struct dog
{
char *name;
float age;
char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
