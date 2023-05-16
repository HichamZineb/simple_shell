#include "shell.h"
/**
 * _strspn -  function calculates the length (in bytes) of
 * the initial segment of s which consists entirely  of  bytes
 * in accept
 * @s: String to duplicate
 * @accept: String to duplicate
 * Return:the number of bytes in the
 * initial segment of s
 **/
size_t _strspn(const char *s, const char *accept)
{
size_t i;
for (i = 0; s[i] != '\0'; i++)
{
if (_strchr(accept, s[i]) == NULL)
break;
}
return (i);
}
