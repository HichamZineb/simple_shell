#include "shell.h"
/**
 * *_getenv - Function that get the
 * path from environ var
 * @name : name of the VAR
 * Return: path
 **/
char *_getenv(char *name)
{
int j;
char *path = NULL;
size_t len = _strlen(name);
for (j = 0; environ[j] != NULL; j++)
{
if (_strncmp(environ[j], name, len) == 0)
{
path = environ[j] + len;
break;
}
}
return (path);
}
