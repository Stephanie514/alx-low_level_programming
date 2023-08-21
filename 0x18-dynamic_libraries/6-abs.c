#include "main.h"

/**
 * _abs - function that computes the absolute value of an integer.
 * @r: Number to be computed
 * Return:Zero or absolute value of number
 */

int _abs(int r)

{
if (r < 0)
{
int abs_val;
abs_val = r * -1;
return (abs_val);
}
return (r);
}
