#include "shell.h"
char *get_path(void)
{
    int j;
    char *path = NULL;
    for(j = 0; environ[j] != NULL; j++)
    {
        if(_strncmp(environ[j], "PATH=", 5) == 0)
        {
            path = environ[j] + 5;
            break;
        }
    }
    return path;
}
