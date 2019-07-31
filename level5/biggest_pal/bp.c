/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:08:53 by bwebb             #+#    #+#             */
/*   Updated: 2019/07/31 16:13:02 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ispal(char *s, int a, int z)
{
    while (a < z)
        if (s[a++] != s[z--])
            return (0);
    return (1);
}

int main(int ac, char **av)
{
    int i;
    int j;
    int k;
    
    if (ac != 2 || av[1][0] == '\0')
    {
        write(1, "\n", 1);
        return (0);
    }
    if (av[1][1] == '\0')
        write(1, av[1], 1);
    i = 0;
    j = 0;
    while (av[1][j + 1])
        j++;
    while (i < j)
    {
        k = -1;
        while (++k <= i)
            if (ispal(av[1], i - k, j - k))
            {
                write(1, av[i] + i - k, j - k + 1);
                write(1, "\n", 1);
                return (0);   
            }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}