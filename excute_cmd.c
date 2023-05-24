#include "shell.h"
/**
 * execute_command - function that fork and execute command
 * @cmd_path: command path
 * @argv : line of cmd
 * Return: void
 */
void execute_command(char *cmd_path, char **argv)
{
if (_strcmp(argv[0], "exit") != 0
&& _strcmp(argv[0], "setenv") != 0
&& _strcmp(argv[0], "unsetenv") != 0 && _strcmp(argv[0], "cd") != 0)
{
if (access(cmd_path, X_OK) == 0)
{
if (fork() == 0)
{
if (execve(cmd_path, argv, NULL) == -1)
perror(argv[0]);
free(cmd_path);
exit(0);
}
else
{
free(cmd_path);
wait(NULL);
}}
else
perror(argv[0]);
}
}
