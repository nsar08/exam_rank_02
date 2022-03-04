/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnltest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:28:26 by nsar              #+#    #+#             */
/*   Updated: 2022/03/04 12:30:16 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "gnllc.h"
int ft_strlen(char *str)
{
	int i;

	i = 0;
	if(str == 0)
		return(0);
	while(str[i])
		i++;
	return(i);
}

char *join(char *str, char c)
{
	char *mem;
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	mem = malloc(len + 2);
	if (mem == 0)
		return(0);
	while(i < len)
	{
		mem[i] = str[i];
		i++;
	}
	mem[i] = c;
	mem[i + 1] = 0;
	if(str)
		free(str);
	return(mem);
}
int init_check(int fd, t_read *info)
{
	info->pos = 0;
	info->fd = fd;
	info->max = read(info->fd, info->data, BUFFER_SIZE);
	if (info->max < 0)
		return(0);
	else
		return(1);
}

char read_check(t_read *info)
{
	char result;

	if (info->pos >= info->max)
	{
		info->max = read(info->fd, info->data, BUFFER_SIZE);
		info->pos = 0;
		if (info->max <= 0)
			return(0);
	}
	result = info->data[info->pos];
	info->pos++;
	return(result);
}

char *gnl(int fd)
{
	static t_read	info = {.fd = -1};
	char c;
	char *str;

	str = 0;
	if(info.fd != fd)
		if(!init_check(fd, &info))
			return(0);
	c = read_check(&info);
	while(c)
	{
		str = join(str, c);
		if(c == '\n')
			return(str);
		c = read_check(&info);
	}
	return(str);
}
/*int main(void)
{
	char *str;
	int fd;
	int i;

	fd = open("coucou.txt", O_RDONLY);
	i = 1;
	while(i < 7)
	{
		str = gnl(fd);
		printf("line [%02d]: %s", i, str);
		free(str);
		i++;
	}
	close(fd);
	return(0);
}*/

