#include "shell.h"

int main(void)
{
	char *line = NULL, *argv[MAX_ARGS], *path, *path_copy, *dir;
	size_t line_size = 0;
	int argc;
	char cmd_path[1024];

	while (1)
	{
		write_str(STDOUT_FILENO, "[ALX] ");
		if (getline(&line, &line_size, stdin) == -1)
		{
			write_str(STDOUT_FILENO, "\n");
			exit(0); }
		argc = 0;
		argv[argc] = strtok(line, " \n");
		while (argv[argc] != NULL && argc < MAX_ARGS - 1)
		{
			argc++;
			argv[argc] = strtok(NULL, " \n"); }
		if (argv[0] == NULL)
			continue;
		if (_strcmp(argv[0], "exit") == 0)
			exit(0);
		if (argv[0][0] == '/')
		{
			if (access(argv[0], X_OK) == 0)
				_strcpy(cmd_path, argv[0]);
			else
			{
				write_str(STDERR_FILENO, argv[0]);
				write_str(STDERR_FILENO, ": command not found\n");
				continue; }}
		else
		{
			path = getenv("PATH");
			if (path == NULL)
		{
			write_str(STDERR_FILENO, "PATH environment not set\n");
			continue; }
		path_copy = _strdup(path);
		dir = strtok(path_copy, ":");
		while (dir != NULL)
		{
			_strcpy(cmd_path, dir);
			_strcat(cmd_path, "/");
			_strcat(cmd_path, argv[0]);
			if (access(cmd_path, X_OK) == 0)
				break;
			dir = strtok(NULL, ":"); }
		free(path_copy);
		if (dir == NULL)
		{
			write_str(STDERR_FILENO, argv[0]);
			write_str(STDERR_FILENO, ": command not found\n");
			continue; }}
		if (fork() == 0)
		{
			execve(cmd_path, argv, NULL);
			perror(argv[0]);
			exit(0); }
		wait(NULL); }
	free(line);
	return (0); }
