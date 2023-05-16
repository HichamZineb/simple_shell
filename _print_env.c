#include "shell.h"
/**
 * _print_env - Function that print env
 * Return: void
 **/
void _print_env(void)
{
int i;
for (i = 0; environ[i] != NULL; i++)
{
write_str(STDOUT_FILENO, environ[i]);
write_str(STDOUT_FILENO, "\n");
}
}
