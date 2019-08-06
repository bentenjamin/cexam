/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:18:58 by bwebb             #+#    #+#             */
/*   Updated: 2019/08/06 13:55:38 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    char abc[25];
    int i;
    int j;

    i = 1;
    j = 0;
    while (j < 26)
        abc[j++] = '0';
    while (av[i])
    {
        j = 0;
        if (av[i][0] == '-')
            while (av[i][++j])
            {
                if (av[i][j] >= 'a' && av[i][j] <= 'z')
                    abc[av[i][j] - 'a'] = '1';
                else
                {
                    write(1, "Invalid Option\n", 15);
                    return (0);
                }
            }
        i++;    
    }
    if (ac < 2 || (abc['h' - 'a'] == '1'))
    {
        write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
        return (1);
    }
    write(1, "000000", 6);
    i = 26;
    while (i)
    {
        if (i % 8 == 0)
            write(1, " ", 1);
        write(1, &abc[i - 1], 1);
        i--;
    }
    write(1, "\n", 1);
    return (0);
}