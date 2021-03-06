/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:20:13 by nsar              #+#    #+#             */
/*   Updated: 2022/03/02 11:51:16 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_inter(char *s1, char *s2)
{
	int i = 0;
	int j;
	int ascii[128];

	while(i<128)
	{
		ascii[i] =  0;
		i++;
	}
	i = 0;
	while(s1[i] != '\0')
	{
		if(ascii[(int)s1[i]] == 0)
		{
			j=0;
			while(s2[j] != '\0')
			{
				if(s1[i] == s2[j] && ascii[(int)s1[i]] == 0)
				{
					write(1, &s1[i], 1);
					ascii[(int)s1[i]] = 1;
				}
				j++;
			}
		}
		i++;
	}
}
int main(int argc, char **argv)
{
	if(argc == 3)
	{
		ft_inter(argv[1], argv[2]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n",1);
	return(0);
}
