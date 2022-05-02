/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchabot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:11:38 by bchabot           #+#    #+#             */
/*   Updated: 2022/05/02 19:43:50 by bchabot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h> 
#include <stdlib.h> 

char *get_next_line(int fd);
int ft_strlen(char *s);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_strjoin(char *s1, char *s2);
int ft_strlcat(char *dst, char *src, size_t size);
int ft_strlcpy(char *dst, char *src, size_t size);

#endif