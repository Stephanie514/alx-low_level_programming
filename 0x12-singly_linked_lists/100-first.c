#include <stdio.h>

void execute_before(void) __attribute__((constructor));

/**
 * execute_before - Function that prints a message before
 * the main function is executed.
 */
void execute_before(void)
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
