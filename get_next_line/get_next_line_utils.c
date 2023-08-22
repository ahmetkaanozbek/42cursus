/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozbek <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:35:16 by aozbek            #+#    #+#             */
/*   Updated: 2023/08/11 12:35:18 by aozbek           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    int length;
    
    length = 0;
    while (s[length] != '\0')
        length++;
    return (length);
}

char *ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
    if (!s)
    {
        return NULL;
    }
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *res;
    int i;
    int j;

    i = 0;
    j = 0;
    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char));
        s1[0] = '\0';
    }
    if (!s1)
        return (NULL);
    res = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
    if (!res)
        return (NULL);
    while (s1[i] != '\0')
    {
        res[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        res[i + j] = s2[j];
        j++;
    }
    res[i + j] = '\0';
    free(s1);
    return (res);
}
