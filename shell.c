#include "shell.h"
/**
 *main - simple shell
 *Return: Always 0.
 **/
int main(void)
{char *line = NULL, *argv[MAX_ARGS], *path_copy, *path = NULL, *cmd_path;
int argc;
while (1)
{write_str(STDOUT_FILENO, "$ ");
line = _getline();
if (line == NULL)
{write_str(STDOUT_FILENO, "\n");
free(line);
exit(0); }
argc = 0;
argv[argc] = _strtok(line, " \n");
while (argv[argc] != NULL && argc < MAX_ARGS - 1)
{argc++;
argv[argc] = _strtok(NULL, " \n"); }
if (argv[0] == NULL)
continue;
if (_strcmp(argv[0], "exit") == 0)
exit_shell(argv, line);
if (_strcmp(argv[0], "env") == 0)
_print_env();
if (argv[0][0] == '/')
{
if (access(argv[0], X_OK) == 0)
{cmd_path = malloc(sizeof(argv[0]));
_strcpy(cmd_path, argv[0]); }
else
{perror(argv[0]);
free(cmd_path);
continue; }}
else
{path = get_path();
if (path == NULL)
{write_str(STDERR_FILENO, "PATH environment not set\n");
continue; }
path_copy = _strdup(path);
cmd_path = get_cmd_path(path_copy, argv); }
execute_command(cmd_path, argv);
free(line); }
return (0); }
