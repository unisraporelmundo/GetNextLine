/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iizquier <iizquier@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:30:02 by iizquier          #+#    #+#             */
/*   Updated: 2024/07/04 13:16:01 by iizquier         ###   ########.fr       */
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
    char	*str;
    int		i;
    int		j;

    if (!str1 || !str2)
        return (NULL);
    str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
    if (!str)
        return (NULL);    
    i = 0;
    j = 0;
    while (str1[i])
    {
        str[i] = str1[i];
        i++;
    }
    while (str2[j])
    {
        str[i] = str2[j];
        i++;
        j++;
    }
    str[i] = 0;
    return (str);
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