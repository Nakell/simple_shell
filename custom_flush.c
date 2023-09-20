#include "myshell.h"

/**
 * custom_flush - clears memory
 *
 */
void custom_flush(void)
{
	if (write(fileno(stdout), NULL, 0) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
}
