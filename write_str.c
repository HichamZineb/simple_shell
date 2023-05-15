#include "shell.h"
void write_str(int fd, const char *str)
{
write(fd, str, strlen(str));
}
