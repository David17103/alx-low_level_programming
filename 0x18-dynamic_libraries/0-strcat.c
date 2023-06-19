#include "main.h"
/**
* *_strcat - concatenates the 2 strings
* @dest: target string
* @src: what is goind to be added
* Return: the dest is returned
*/
char *_strcat(char *dest, char *src)
{
	int x, y;

	for (x = 0; dest[x] != '\0'; x++)
		;
	for (y = 0; src[y] != '\0'; y++)
	{
		dest[x + y] = src[y];
	}
	dest[x + y] = '\0';
	return (dest);
}
