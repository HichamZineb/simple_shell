#include "shell.h"
/**
 * exit_shell - function that exit the programme
 * @line : line of cmd
 * @argv : args of cmd
 * Return: int
 */
int exit_shell(char **argv, char *line)
{
int status = 0;
char *arg;
if (!isatty(STDIN_FILENO))
status = 2;
if (argv[1] != NULL)
{
arg = argv[1];
while (*arg)
{
if (*arg >= '0' && *arg <= '9')
status = status * 10 + (*arg - '0');
else
{
write_str(STDERR_FILENO, "exit: Illegal number: ");
write_str(STDERR_FILENO, argv[1]);
write_str(STDERR_FILENO, "\n");
status = 2;
}
arg++;
}
}
free(line);
exit(status);
}
