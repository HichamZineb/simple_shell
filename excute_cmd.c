#include "shell.h"
/**
 * execute_command - function that fork and execute command
 * @cmd_path: command path
 * @argv : line of cmd
 * Return: void
 */
void execute_command(char *cmd_path, char **argv)
{
if (fork() == 0)
{
execve(cmd_path, argv, NULL);
exit(0);
}
else
wait(NULL);
}
