#include "shell.h"
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
    if (dir == NULL)
    {
        write_str(STDERR_FILENO, argv[0]);
        write_str(STDERR_FILENO, ": command not found\n");
        return NULL;
    }
    return _strdup(cmd_path);
}
