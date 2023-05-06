#include "main.h"

/**
 * clear_bit - sets the value of the bit to 0
 * @n: pointer to the number that will change
 * @index: index of the bit that will be cleared
 *
 * Return: 1 for pass, -1 for fail
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

