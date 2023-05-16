#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 30
#define READ_SIZE 1024
extern char **environ;
char *_getline(void);
void _print_env(void);
char *get_path(void);
void execute_command(char *cmd_path, char **argv);
char *get_cmd_path(char *path_copy, char **argv);
void write_str(int fd, const char *str);
size_t _strlen(const char *str);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);
char *_strchr(const char *s, int c);
size_t _strspn(const char *s, const char *accept);
char *_strpbrk(const char *s, const char *accept);
char *_strtok(char *str, const char *delim);
char *_strcat(char *dest, const char *src);


#endif
