#include "shell.h"
/**
 * write_str - that writes a string to a file descriptor
 * @fd: file descriptor
 * @str : string to print
 * Return: void
 */
void write_str(int fd, const char *str)
{
write(fd, str, strlen(str));
}
