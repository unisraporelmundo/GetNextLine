/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iizquier <iizquier@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:30:02 by iizquier          #+#    #+#             */
/*   Updated: 2024/07/03 19:14:38 by iizquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
        while (str[i])
        {
                i++;
        }
        return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
}

char	*ft_strchr(const char *str, int c)
{
    while (*str != (char)c)
	{
		if (*str == 0)
		{
			return (NULL);
		}
		str++;
	}
	return ((char *)str);
}