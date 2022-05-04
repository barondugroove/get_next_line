/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:12:20 by bchabot           #+#    #+#             */
/*   Updated: 2022/05/04 16:32:30 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdio.h>
#include<unistd.h>
#include"get_next_line.h"

int ft_has_backslash_n(char *s, int param)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '\0' || s[i] == '\n') && param)
			return (i + 1);
		if (s[i] == '\n' && !param)
			return (i + 1);
		i++;
	}
	return (0);
}

char *ft_read(char *str, int fd)
{
	char *buff;
	int i;

	i = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	*buff = 0;
	if (read(fd, buff, 0) == -1 || fd < 0 || BUFFER_SIZE < 1)
		return (free(buff), free(str), NULL);
	while (!ft_has_backslash_n(str, 0) && i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char *get_next_line(int fd)
{
	static char *save;
	char *str;
	char *line;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = 0;
	if (!save)
	{
		save = malloc(sizeof(char));
		*save = 0;
	}
	str = ft_strjoin(str, save);
	free(save);
	str = ft_read(str, fd);
	save = ft_substr(str, ft_has_backslash_n(str, 0), ft_strlen(str) - ft_has_backslash_n(str, 0));
	line = ft_substr(str, 0, ft_has_backslash_n(str, 0));
	free(str);
	return (line);
}
