/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:52:50 by bwebb             #+#    #+#             */
/*   Updated: 2019/08/07 13:27:38 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define hstr "0123456789abcdef"
#include <unistd.h>

void ft_puthex(int i)
{
    if (i > 16)
        ft_puthex(i / 16);
    write(1, &(hstr[i % 16]), 1);
}

void	print_memory(const void *addr, size_t size)
{
    size_t i;
    const unsigned char *p;
    int g;
    int printed;

    p = addr;
    i = 0;
    while (i < size)
    {
        
    }
}

int main()
{
    int	tab[10] = {0, 23, 150, 255,
	              12, 16,  42, 103};

	print_memory(tab, sizeof(tab));
	return (0);
}
