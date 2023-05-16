#include "shell.h"
/**
 * *_strchr - cherch for a char in string
 * @s: String to duplicate
 * @c: String to duplicate
 * Return: char
 */
char *_strchr(const char *s, int c)
{
while (*s != '\0')
{
if (*s == c)
return ((char *)s);
s++;
}
if (c == '\0')
return ((char *)s);
return (NULL);
}
