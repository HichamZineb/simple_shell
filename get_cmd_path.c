#include "shell.h"
/**
 * *get_cmd_path - function that get path of a cmd
 * @path_copy: copy of path
 * @argv : line of cmd
 * Return: char
 **/
char *get_cmd_path(char *path_copy, char **argv)
{
char *dir, cmd_path[1024];
dir = _strtok(path_copy, ":");
while (dir != NULL)
{
_strcpy(cmd_path, dir);
_strcat(cmd_path, "/");
_strcat(cmd_path, argv[0]);
if (access(cmd_path, X_OK) == 0)
break;
dir = _strtok(NULL, ":");
}
free(path_copy);
if (dir == NULL && _strcmp(argv[0], "exit") != 0
&& _strcmp(argv[0], "setenv") != 0
&& _strcmp(argv[0], "unsetenv") != 0 && _strcmp(argv[0], "cd") != 0)
return (NULL);
else
return (_strdup(cmd_path));
}
