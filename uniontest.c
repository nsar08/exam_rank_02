/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniontest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:25:33 by nsar              #+#    #+#             */
/*   Updated: 2022/02/24 11:31:21 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void ft_union(char *s1, char *s2)
{
	int ascii[128];
	int i;

	i = 0;
	while(i<128)
	{
		ascii[i]=0;
		i++;
	}
	while(*s1 && s1[i] != '\0')
	{
		if(ascii[(int)s1[i]] == 0)
		{
			write(1, &s1[i], 1);
			ascii[(int)s1[i]] = 1;
			i++;
		}
	}
	while(*s2 && s2[i] != '\0')
	{
		if(ascii[(int)s1[i]] == 0)
		{
		write(1, &s2[i], 1);
		ascii[(int)s1[i]] = 1;
		i++;
		}
	}
}


int main(int argc, char **argv)
{
	if(argc == 3)
	{
		ft_union(argv[1], argv[2]);
		write(1, "\n", 1);
	}
	else 
		write(1, "\n", 1);
	return(0);
}


