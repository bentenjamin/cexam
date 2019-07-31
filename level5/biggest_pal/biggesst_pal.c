/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggesst_pal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:08:53 by bwebb             #+#    #+#             */
/*   Updated: 2019/07/31 14:31:16 by bwebb            ###   ########.fr       */
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
    int k;
    int len;
    char *p;
    
    if (ac != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    len = 0;
    while (av[1][i + 1])
    {
        k = i;
        while (av[1][++k])
            if (ispal(av[1], i, k) && (k - i >= len))
                {
                    len = k - i + 1;
                    p = av[1] + i;
                }
        i++;
    }
    if (len)
        write(1, p, len);
    write(1, "\n", 1);
    return (0);
}