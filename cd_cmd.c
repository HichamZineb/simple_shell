#include "shell.h"
/**
* cd_command - function that set env VAR
* @argv: argv
* @argc: argc
* Return: void
**/
void cd_command(char **argv, int argc)
{
char *home = _getenv("HOME=");
char *oldpwd = _getenv("OLDPWD=");
char cwd[1024];
getcwd(cwd, sizeof(cwd));
if (argc == 1)
{
chdir(home);
}
else if (argc == 2)
{
if (_strcmp(argv[1], "-") == 0)
{
_setenv("OLDPWD", cwd);
write_str(STDERR_FILENO, oldpwd);
write_str(STDERR_FILENO, "\n");
chdir(oldpwd); }
else if (chdir(argv[1]) == -1)
perror(argv[1]);
}
else if (argc == 3)
{
write_str(STDERR_FILENO, "cd: too many arguments");
write_str(STDERR_FILENO, "\n");
}
else
_setenv("PWD", cwd);
_setenv("OLDPWD", cwd);
}

