#include "shell.h"
/**
 *main - simple shell
 *Return: Always 0.
 **/
int main(void)
{char *line = NULL, *arv[MAX_ARGS], *path_copy, *path = NULL, *cmd_path;
int argc;
while (1)
{
if (isatty(STDIN_FILENO))
write_str(STDOUT_FILENO, "$ ");
line = _getline();
if (line == NULL)
exit(EXIT_SUCCESS);
argc = 0;
arv[argc] = _strtok(line, " \n");
while (arv[argc] != NULL && argc < MAX_ARGS - 1)
{argc++;
arv[argc] = _strtok(NULL, " \n"); }
if (arv[0] == NULL)
{free(line);
continue; }
handle_commands(arv, line, argc);
if (arv[0][0] == '/' || arv[0][0] == '.')
{
cmd_path = malloc(sizeof(arv[0]));
_strcpy(cmd_path, arv[0]); }
else
{path = _getenv("PATH=");
path_copy = _strdup(path);
cmd_path = get_cmd_path(path_copy, arv); }
execute_command(cmd_path, arv);
free(line); }
return (0); }
