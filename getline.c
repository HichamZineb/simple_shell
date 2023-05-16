#include "shell.h"
/**
* _getline - reads line from standard input
* Return: a null-terminated string that does not include the newline character
*/
char *_getline(void)
{
static char buffer[READ_SIZE];
static int i;
static int size;
char *line = NULL;
int line_size = 0;

while (1)
{
if (i >= size)
{
size = read(STDIN_FILENO, buffer, READ_SIZE);
if (size == -1)
return (NULL);
i = 0;
}
if (size == 0)
break;
line = realloc(line, line_size + 2);
if (line == NULL)
return (NULL);
line[line_size] = buffer[i];
line_size++;
i++;
if (line[line_size - 1] == '\n')
break;
}
if (line != NULL)
line[line_size - 1] = '\0';
return (line);
}

