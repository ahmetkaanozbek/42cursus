/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozbek <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:59:28 by aozbek            #+#    #+#             */
/*   Updated: 2023/08/10 18:59:34 by aozbek           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *move_line(char *r_line)
{
    int i;
    int j;
    char *new_line;

    i = 0;
    j = 0;
    while (r_line[i] != '\0' && r_line[i] != '\n')
        i++;
    if (r_line[i] == '\0')
    {
        free(r_line);
        return (NULL);
    }
    if (r_line[i] == '\n')
        i++;
    new_line = (char *)malloc((ft_strlen(r_line) - i + 1) * sizeof(char));
    if (!new_line)
        return (NULL);
    while (r_line[i + j] != '\0')
    {
        new_line[j] = r_line[i + j];
        j++;
    }
    new_line[j] = '\0';
    free(r_line);
    return (new_line);
}


char *read_line(char *r_line)
{
    int i;
    int j;
    char *a_line;

    i = 0;
    j = 0;
    if (!r_line || !r_line[0])
		return (NULL);
    while (r_line[i] != '\0' && r_line[i] != '\n')
        i++;
    if (r_line[i] == '\n')
        i++;
    a_line = (char *)malloc((1 + i) * sizeof(char));
    if (!a_line)
        return (NULL);
    while (r_line[j] != '\0' && r_line[j] != '\n')
    {
        a_line[j] = r_line[j];
        j++;
    }
    if (r_line[j] == '\n')
    {
        a_line[j] = '\n';
        j++;
    }
    a_line[j] = '\0';
    return (a_line);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *tmp;
    char *line;
    int bytes;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    tmp = (char *)malloc((1 + BUFFER_SIZE) * sizeof(char));
    if (!tmp)
        return (NULL);
    bytes = 1;
    while(!(ft_strchr(buffer, '\n')) && (bytes != 0))
    {
        bytes = read(fd, tmp, BUFFER_SIZE);
        if (bytes == -1)
        {
            free(tmp);
            return (NULL);
        }
        tmp[bytes] = '\0';
        buffer = ft_strjoin(buffer, tmp);
    }
    free(tmp);
    line = read_line(buffer);
    buffer = move_line(buffer);
    return (line);
}
