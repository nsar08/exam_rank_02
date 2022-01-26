/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:20:13 by nsar              #+#    #+#             */
/*   Updated: 2022/01/25 17:02:45 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_inter(char *s1, char *s2)
{
	int ascii[128];
	int i = 0;
	int j;
	while (i < 128)
	{
		ascii[i] = 0;
		i++;
	}
	i = 0;
	while (s1[i] != '\0')
	{
		if (ascii[s1[i]] == 0)
		{
			j = 0;
			while(s2[j] != '\0')
				{
					if (s1[i] == s2[j] && ascii[s1[i]] == 0)
					{
						write(1, &s1[i], 1);
						ascii[s1[i]] = 1;
					}
					j++;
				}
		}
		i++;
	}
}
int main (int argc, char **argv)
{
	if (argc == 3)
	{
		ft_inter(argv[1], argv[2]);
		write(1,"\n", 1);
	}
	else
		write(1, "\n", 1);
	return(0);
}
