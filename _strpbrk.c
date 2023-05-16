#include "shell.h"
/**
 * *_strpbrk - search a string for any of a set of bytes
 * @s: string passed
 * @accept: const char passed
 * Return: void
 */
char *_strpbrk(const char *s, const char *accept)
{
for (; *s != '\0'; s++)
{
if (_strchr(accept, *s) != NULL)
return ((char *)s);
}
return (NULL);
}
