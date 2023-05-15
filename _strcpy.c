#include "shell.h"

/**
 * _strcpy - Copies from source to destination
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Temp
 */
char *_strcpy(char *dest, char *src)

{
	char *temp = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (temp);
}
