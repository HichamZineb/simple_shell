#include "shell.h"
/**
* _unsetenv - function that unset enb VAR
* @name: name of var
* Return: int
**/
int _unsetenv(char *name)
{
int index = 0;
size_t len_name;
if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
{
write_str(STDERR_FILENO, "Error: invalid arguments\n");
return (-1);
}
len_name = _strlen(name);
while (environ[index] != NULL)
{
if (_strncmp(environ[index], name, len_name) == 0
&& environ[index][len_name] == '=')
{
while (environ[index] != NULL)
{
environ[index] = environ[index + 1];
index++; }
return (0); }
index++; }
return (0); }
