#include "shell.h"

/**
 * _strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: First string - Second string
 */
int _strcmp(char *s1, char *s2)

{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
