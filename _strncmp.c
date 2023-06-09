#include "shell.h"
/**
 * _strncmp - function compares the two strings s1 and s2
 * @s1: String to duplicate
 * @s2: String to duplicate
 * @n: size
 * Return: int
 **/
int _strncmp(char *s1, char *s2, size_t n)
{
size_t i;
for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
}
if (i == n)
return (0);
else
return (s1[i] - s2[i]);
}
