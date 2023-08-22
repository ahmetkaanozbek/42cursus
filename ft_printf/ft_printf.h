/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozbek <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:32:33 by aozbek            #+#    #+#             */
/*   Updated: 2023/08/01 15:45:14 by aozbek           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_string(char *str);
int	ft_print_nbr(int num);
int	ft_print_ptr(void *ptr);
int	ft_print_hex(unsigned int num, char format);
int	ft_print_unbr(unsigned int num);
int	ft_print_perc(void);

#endif
