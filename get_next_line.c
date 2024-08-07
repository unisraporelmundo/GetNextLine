/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iizquier <iizquier@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:31:00 by iizquier          #+#    #+#             */
/*   Updated: 2024/07/11 13:34:34 by iizquier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stack)
{
	char	*line;
	int		i;

	if (!stack || !*stack)
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
	char	*tmp;
	char	*ptr;
	int		i;

	ptr = ft_strchr(stack, '\n');
	if (!ptr)
	{
		free(stack);
		stack = NULL;
		return (NULL);
	}
	ptr++;
	tmp = malloc(sizeof(char) * (ft_strlen(ptr) + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (*ptr != '\0')
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
	char	*aux;

	if (!stack)
	{
		stack = malloc(1);
		if (!stack)
			return (NULL);
		stack[0] = '\0';
	}
	if (!stack)
		return (NULL);
	aux = ft_strjoin(stack, tmp);
	free(stack);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	char		tmp[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = 1;
	while (!ft_strchr(stack, '\n') && readbytes > 0)
	{
		readbytes = read(fd, tmp, BUFFER_SIZE);
		if (readbytes < 0)
			return (free(stack), stack = NULL, NULL);
		tmp[readbytes] = '\0';
		stack = joinfree(stack, tmp);
		if (!stack)
			return (NULL);
	}
	line = extract_line(stack);
	stack = up_stack(stack);
	return (line);
}
/* int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */