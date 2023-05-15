#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 30

extern char **environ;

void write_str(int fd, const char *str)
{
write(fd, str, strlen(str));
}

int main(void)
{
char *line = NULL;
size_t line_size = 0;
char *args[MAX_ARGS];
int arg_count;
char *path = NULL;
char *path_copy;
char *dir;
char cmd_path[1024];

while (1)
{
write_str(STDOUT_FILENO, ":) ");

if (getline(&line, &line_size, stdin) == -1)
{
write_str(STDOUT_FILENO, "\n");
exit(0);
}

arg_count = 0;
args[arg_count] = strtok(line, " \n");

while (args[arg_count] != NULL && arg_count < MAX_ARGS - 1)
{
arg_count++;
args[arg_count] = strtok(NULL, " \n");
}

if (args[0] == NULL)
{
continue;
}

if (strcmp(args[0], "exit") == 0)
{
    exit(0);
}

if (strcmp(args[0], "env") == 0)
{
    for (int i = 0; environ[i] != NULL; i++)
    {
        write_str(STDOUT_FILENO, environ[i]);
        write_str(STDOUT_FILENO, "\n");
    }
    continue;
}

if (args[0][0] == '/')
{

if (access(args[0], X_OK) == 0)
{
strcpy(cmd_path, args[0]);
}
else
{
write_str(STDERR_FILENO, args[0]);
write_str(STDERR_FILENO, ": command not found\n");
continue;
}
}
else
{
//remplece getenv
for (int i = 0; environ[i] != NULL; i++)
{
    if (strncmp(environ[i], "PATH=", 5) == 0)
    {
        path = environ[i] + 5;
        break;
    }
}
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
strcat(cmd_path, args[0]);
if (access(cmd_path, X_OK) == 0)
{
break;
}
dir = strtok(NULL, ":");
}
free(path_copy);
if (dir == NULL)
{
write_str(STDERR_FILENO, args[0]);
write_str(STDERR_FILENO, ": command not found\n");
continue;
}
}
if (fork() == 0)
{
execve(cmd_path, args, NULL);
perror(args[0]);
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

