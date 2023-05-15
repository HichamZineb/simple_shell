#include "shell.h"
void execute_command(char *cmd_path, char **argv)
{
    if(fork() == 0)
    {
        execve(cmd_path, argv, NULL);
        perror(argv[0]);
        exit(0);
    }
    else
    {
        wait(NULL);
    }
}
