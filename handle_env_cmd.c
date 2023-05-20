#include "shell.h"
/**
* handle_env_commands - function that handle env cmd
* @argv: args
* Return: void
**/
void handle_env_commands(char **argv)
{
if (_strcmp(argv[0], "setenv") == 0)
{
if (argv[1] != NULL && argv[2] != NULL)
_setenv(argv[1], argv[2]);
else
write_str(STDERR_FILENO, "Error: setenv requires two arguments\n");
}
else if (_strcmp(argv[0], "unsetenv") == 0)
{
if (argv[1] != NULL)
_unsetenv(argv[1]);
else
write_str(STDERR_FILENO, "Error: unsetenv requires one argument\n");
}
}
