#include "get_next_line.h"

char *ft_verify(char *tmp, char *buff, ssize_t bytes_read)
{
    char *new_tmp;

    if (bytes_read == 0)
        return (tmp);
    buff[bytes_read] = '\0';
    if (!tmp)
        return (ft_strdup(buff));
    new_tmp = ft_strjoin(tmp, buff);
    free(tmp);
    return (new_tmp);
}

void ft_extract(char **ptr_tmp)
{
    char *keep_tmp;
    char *newline_pos;

    newline_pos = ft_strchr(*ptr_tmp, '\n');
    if (!newline_pos || *(newline_pos + 1) == '\0')
    {
        free(*ptr_tmp);
        *ptr_tmp = NULL;
        return;
    }
    keep_tmp = ft_strdup(newline_pos + 1);
    free(*ptr_tmp);
    *ptr_tmp = keep_tmp;
}

char *ft_free(char **ptr_tmp, char **ptr_buf, ssize_t b)
{
    char *line;
    char *newline_pos;

    (void)ptr_buf;
    line = NULL;
    if (!*ptr_tmp)
        return (NULL);
    if (b == 0 && **ptr_tmp)
    {
        line = ft_strdup(*ptr_tmp);
        free(*ptr_tmp);
        *ptr_tmp = NULL;
        return (line);
    }
    newline_pos = ft_strchr(*ptr_tmp, '\n');
    if (newline_pos != NULL)
    {
        line = ft_substr(*ptr_tmp, 0, (newline_pos - *ptr_tmp) + 1);
        ft_extract(ptr_tmp);
        return (line);
    }
    return (NULL);
}

char *get_next_line(int fd)
{
    static char *tmp;
    char *buff;
    ssize_t bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0)
    {
        if (tmp && ft_strchr(tmp, '\n') != NULL)
            return (ft_free(&tmp, &buff, 1));
        buff = (char *)malloc(BUFFER_SIZE + 1);
        if (!buff)
            return (NULL);
        bytes_read = read(fd, buff, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(buff);
            free(tmp);
            tmp = NULL;
            return (NULL);
        }
        tmp = ft_verify(tmp, buff, bytes_read);
        free(buff);
    }
    return (ft_free(&tmp, &buff, bytes_read));
}