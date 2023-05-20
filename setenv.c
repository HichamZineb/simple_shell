#include "shell.h"
/**
* _setenv - function that set env VAR
* @name: name of var
* @value: value of var
* Return: int
**/
int _setenv(char *name, char *value)
{
int index = 0;
char *new_env;
size_t len_name = _strlen(name);
if (name == NULL || value == NULL || name[0] == '\0'
|| _strchr(name, '=') != NULL)
{write_str(STDERR_FILENO, "Error: invalid arguments\n");
return (-1); }
while (environ[index] != NULL)
{
if (_strncmp(environ[index], name, len_name) == 0
&& environ[index][len_name] == '=')
{ new_env = malloc(len_name + _strlen(value) + 2);
if (new_env == NULL)
{write_str(STDERR_FILENO, "Error: memory allocation failed\n");
return (-1); }
_strcpy(new_env, name);
_strcat(new_env, "=");
_strcat(new_env, value);
environ[index] = new_env;
return (0); }
index++; }
new_env = malloc(len_name + _strlen(value) + 2);
if (new_env == NULL)
{write_str(STDERR_FILENO, "Error: memory allocation failed\n");
return (-1); }
_strcpy(new_env, name);
_strcat(new_env, "=");
_strcat(new_env, value);
environ[index] = new_env;
environ[index + 1] = NULL;
return (0); }

