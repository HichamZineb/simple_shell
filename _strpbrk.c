#include "shell.h"
char *_strpbrk(const char *s, const char *accept)
{
    for (; *s != '\0'; s++)
    {
        if (_strchr(accept, *s) != NULL)
            return (char *)s;
    }
    return NULL;
}
