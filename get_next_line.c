/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iizquier <iizquier@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:31:00 by iizquier          #+#    #+#             */
/*   Updated: 2024/07/09 16:22:00 by iizquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stack)
{
	char	*line;
	int 	i;
	
	if(!stack || !*stack)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		line[i++] = '\n';
	}
	line[i] = '\0';
	return (line);
}

char	*up_stack(char *stack)
{
	char *tmp;
	char *ptr;
	int i;
	
	ptr = ft_strchr(stack, '\n');
	if (!ptr)
	{
		free(stack);
		return (NULL);
	}
	ptr++;
	tmp = malloc(sizeof(char) * (ft_strlen(ptr) + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (ptr != '\0')
	{
		tmp[i] = *ptr;
		i++;
		ptr++;
	}
	tmp[i] = '\0';
	free(stack);
	return (tmp);
}

char	*joinfree(char *stack, char *tmp)
{
}

char	*get_next_line(int fd)
{
}