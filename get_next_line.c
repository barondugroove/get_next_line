/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:12:20 by bchabot           #+#    #+#             */
/*   Updated: 2022/05/03 12:55:47 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdio.h>
#include<unistd.h>
#include"get_next_line.h"

int ft_has_backslash_n(char *s);
char *ft_read(char *str, int fd);

char *get_next_line(int fd)
{
	static char *save;
	char *str;
	char *line;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = 0;
	if (save)
		str = ft_strjoin(save, str);
	str = ft_read(str, fd);
	if (!str)
		return (free(str), NULL);
	save = ft_substr(str, ft_has_backslash_n(str), ft_strlen(str) - ft_has_backslash_n(str));
	line = ft_substr(str, 0, ft_has_backslash_n(str));
	free(str);
	return (line);
}

int ft_has_backslash_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
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
	*buff = 0;
	if (!buff || read(fd, buff, 0) == -1 || fd < 0 || BUFFER_SIZE < 1)
		return (free(buff), free(str), NULL);
	while (!ft_has_backslash_n(buff) && i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		str = ft_strjoin(str, buff);
		if (i <= 0)
			return (free(buff), NULL);
	}
	free(buff);
	return (str);
}
