#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - the sum of two numbers returned.
 * @a: First number.
 * @b: Second number.
 *
 * Return: Sum of a and b.
 */

int op_add(int a, int b)
{
return (a + b);
}

/**
 * op_sub - difference of two numbers is returned.
 * @a: First number.
 * @b: Second number.
 *
 * Return: Difference of a and b.
 */

int op_sub(int a, int b)
{
return (a - b);
}

/**
 * op_mul - product of two numbers is returned.
 * @a: First number.
 * @b: Second number.
 *
 * Return: product of a and b.
 */

int op_mul(int a, int b)
{
return (a * b);
}

/**
 * op_div - division of two numbers.
 * @a: First number.
 * @b: Second number.
 *
 * Return: Quotient of a and b.
 */

int op_div(int a, int b)
{
return (a / b);
}

/**
 * op_mod - remainder of the division of two numbers is returned.
 * @a: First number.
 * @b: Second number.
 *
 * Return: remainder of the division of a by b.
 */

int op_mod(int a, int b)
{
return (a % b);
}
