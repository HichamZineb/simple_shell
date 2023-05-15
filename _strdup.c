char *_strdup(char *str)
{
    int len = strlen(str);
    char *new_str = malloc(len + 1);
    if (new_str == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        new_str[i] = str[i];
    new_str[len] = '\0';
    return new_str;
}