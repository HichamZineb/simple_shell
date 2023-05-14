#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 30

void write_str(int fd, const char *str)
{
write(fd, str, strlen(str));
}

int main(void)
{
char *line = NULL;
size_t line_size = 0;
char *argv[MAX_ARGS];
int argc;
char *path;
char *path_copy;
char *dir;
char cmd_path[1024];

while (1)
{
write_str(STDOUT_FILENO, ":) ");

if(getline(&line, &line_size, stdin) == -1)
{
write_str(STDOUT_FILENO, "\n");
exit(0);
}

argc = 0;
argv[argc] = strtok(line, " \n");

while (argv[argc] != NULL && argc < MAX_ARGS - 1)
{
argc++;
argv[argc] = strtok(NULL, " \n");
}

if (argv[0] == NULL)
{
continue;
}

if(strcmp(argv[0], "exit") == 0)
{
    exit(0);
}

if (argv[0][0] == '/')
{

if(access(argv[0], X_OK) == 0)
{
strcpy(cmd_path, argv[0]);
}

else
{
write_str(STDERR_FILENO, argv[0]);
write_str(STDERR_FILENO, ": command not found\n");
continue;
}
}
else
{
path = getenv("PATH");
if (path == NULL)
{
write_str(STDERR_FILENO, "PATH environment not set\n");
continue;
}

path_copy = strdup(path);
dir = strtok(path_copy, ":");
while (dir != NULL)
{
strcpy(cmd_path, dir);
strcat(cmd_path, "/");
strcat(cmd_path, argv[0]);
if(access(cmd_path, X_OK) == 0)
{
break;
}
dir = strtok(NULL, ":");
}
free(path_copy);
if (dir == NULL)
{
write_str(STDERR_FILENO, argv[0]);
write_str(STDERR_FILENO, ": command not found\n");
continue;
}
}
if (fork() == 0)
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
free(line);
return 0;
}

