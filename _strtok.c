#include "shell.h"
char *_strtok(char *str, const char *delim)
{
    static char *next_token;
    char *token;
    if (str == NULL)
        str = next_token;
    if (str == NULL)
        return NULL;
    str += _strspn(str, delim);
    if (*str == '\0')
        return NULL;
   token = str;
    str = _strpbrk(token, delim);
    if (str == NULL)
        next_token = NULL;
    else
    {
        *str = '\0';
        next_token = str + 1;
    }
    return token;
}
