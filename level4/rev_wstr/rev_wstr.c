/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:26:58 by bwebb             #+#    #+#             */
/*   Updated: 2019/08/13 13:27:02 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int	i;
	int	len;
	int	k;

	if ((argc != 2) || (argv[1] == NULL) || (argv[1][0] == '\0'))
	{
		write(1, "\n", 1);
		return (1);
	}
	len = 0;
	while (argv[1][len])
		len++;
	while (len > -1)
	{
		i = 0;
		k = 0;
		if ((argv[1][len] == '\t') || (len == 0) || (argv[1][len] == ' '))
		{
			i = (len == 0) ? len : len + 1;
			while (!((argv[1][i] == '\t') || (argv[1][i] == ' ')) && argv[1][i])
				write(1, &argv[1][i++], 1);
			if (len != 0)
				write(1, " ", 1);
		}
		len--;
	}
	write(1, "\n", 1);
	return (1);
}
