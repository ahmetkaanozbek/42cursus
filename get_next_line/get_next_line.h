/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozbek <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:34:51 by aozbek            #+#    #+#             */
/*   Updated: 2023/08/11 12:34:54 by aozbek           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
char *read_line(char *r_line);
char *move_line(char *r_line);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char *s1, char *s2);

#endif
