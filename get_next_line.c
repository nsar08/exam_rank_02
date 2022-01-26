/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:36:35 by nsar              #+#    #+#             */
/*   Updated: 2022/01/25 17:46:32 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2048
#endif

size_t ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return(i);
}


char *ft_strjoin(char *save, char *buff)
{
	char *str;
	size_t i;
	size_t j;

	if (!save)
	{
		save = (char *)malloc(1 * sizeof(char));
		save[0] = '\0';
	}
	if (!save || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(save) + ft_strlen(buff) + 1)));
			if (str == NULL)
			return (NULL);
			i = -1;
			j = 0;
			if (save)
			while (save[++i] != '\0')
			str[i] = save[i];
			while (buff[j] != '\0')
				str[i++] = buff[j++];
				str[ft_strlen(save) + ft_strlen(buff)] = '\0';
				free(save);
				return(str);
	}


char	*ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return(0);
	if (c == '\0')
		return ((char *) &s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		   return ((char *)&s[i]);	
		i++;
	}
	return(0);
}

char *ft_select(char *save)
{
	int i;
	char *str;

	i = 0;
	if (!save[i])
		return(NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = (char*)malloc(sizeof(char) * (i + 2));
	if (!str)
		return(NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_select2 (char *save)
{
	int i;
	int j;
	char *str;
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return(NULL);
	i++;
	j = 0;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}


char *ft_read_and_save(int fd, char *save)
{
	char *buff;
	int ret;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return(NULL);
	ret = 1;
	while (!ft_strchr(save, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return(NULL);
		}
		buff[ret] = '\0';
			save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}
char  *get_next_line(int fd)
{
	char *line;	
	static char *save;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(0);
	save = ft_read_and_save(fd, save);
	if(!save)
		return(NULL);

	line = ft_select(save);
	save = ft_select2(save);
	return (line);
}

int main(void)
{
	char *line;
	int fd;
	int i;

	fd = open("coucou.txt", O_RDONLY);
	i = 1;
	while(i < 7)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return(0);
}
