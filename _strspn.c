#include "shell.h"
size_t _strspn(const char *s, const char *accept)
{
    size_t i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (_strchr(accept, s[i]) == NULL)
            break;
    }
    return i;
}
