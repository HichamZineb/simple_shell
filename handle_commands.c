#include "shell.h"
/**
* handle_commands - function that handle some cmd
* @line : line of cmd
* @argv : args of cmd
* @argc : argc of cmd
* Return: void
*/

void handle_commands(char **argv, char *line, int argc)
{
if (_strcmp(argv[0], "setenv") == 0 || _strcmp(argv[0], "unsetenv") == 0)
handle_env_commands(argv);
else if (_strcmp(argv[0], "exit") == 0)
exit_shell(argv, line);
else if (_strcmp(argv[0], "env") == 0)
{
if (argv[1] == NULL)
_print_env();
}
else if (_strcmp(argv[0], "cd") == 0)
cd_command(argv, argc);
}

