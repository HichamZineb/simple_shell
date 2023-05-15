#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 30

int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
size_t _strlen(const char *str);
char *_strcat(char *dest, const char *src);
void write_str(int fd, const char *str);

#endif
