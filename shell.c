#include "shell.h"
/**
 *main - simple shell
 *Return: Always 0.
 **/
int main(void)
{char *line = NULL, *argv[MAX_ARGS], *path_copy, *path = NULL, *cmd_path;
int argc;
chdir(_getenv("HOME="));
while (1)
{write_str(STDOUT_FILENO, "$ ");
line = _getline();
if (line == NULL)
{write_str(STDOUT_FILENO, "\n");
exit(0); }
argc = 0;
argv[argc] = _strtok(line, " \n");
while (argv[argc] != NULL && argc < MAX_ARGS - 1)
{argc++;
argv[argc] = _strtok(NULL, " \n"); }
if (argv[0] == NULL)
{free(line);
continue; }
handle_commands(argv, line, argc);
if (argv[0][0] == '/')
{
if (access(argv[0], X_OK) == 0)
{cmd_path = malloc(sizeof(argv[0]));
_strcpy(cmd_path, argv[0]); }
else
{perror(argv[0]);
continue; }}
else
{path = _getenv("PATH=");
if (path == NULL)
{write_str(STDERR_FILENO, "PATH environment not set\n");
continue; }
path_copy = _strdup(path);
cmd_path = get_cmd_path(path_copy, argv); }
execute_command(cmd_path, argv);
free(line); }
return (0); }
