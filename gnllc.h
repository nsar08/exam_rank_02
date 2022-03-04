/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnltest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:05:29 by nsar              #+#    #+#             */
/*   Updated: 2022/03/04 12:30:32 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNLLC_H
#define GNLLC_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
typedef struct s_read
{
	int fd;
	int max;
	int pos;
	char data[BUFFER_SIZE];
}	t_read;

int init_check(int fd, t_read *info);
char read_check(t_read *info);
char *gnl(int fd);
int ft_strlen(char *str);
char *join(char *str, char c);
#endif
