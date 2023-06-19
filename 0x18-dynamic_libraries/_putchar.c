#include <unistd.h>

/**
 * _putchar - writes character c to stdout
 * @c: The character to be printed
 *
 * Return: On pass 1.
 * On error, -1 returned, and errno set appropriately.
 */
int _putchar(char c)
{
		return (write(1, &c, 1));
}
