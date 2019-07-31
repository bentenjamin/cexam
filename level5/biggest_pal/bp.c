/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:08:53 by bwebb             #+#    #+#             */
/*   Updated: 2019/07/31 16:38:27 by bwebb            ###   ########.fr       */
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
    int i; //offset to change bracket size of pal
    int j;//size of string
    int k;//counter bouncing between 0 and i
    
    if (ac != 2 || av[1][0] == '\0')//test args and empty string
    {
        write(1, "\n", 1);
        return (0);
    }
    if (av[1][1] == '\0')//test 1 letter
        write(1, av[1], 1);
    i = 0;
    j = 0;
    while (av[1][j + 1])
        j++;
    while (i < j)
    {
        k = -1;//k goes between 0 and i to move the checking size(j - i) from the end to the beginning
        while (++k <= i)//finds the largest pallindrone starting from the back
            if (ispal(av[1], i - k, j - k))//tests if it is a pallindrome. i - k is the start of our bracket, j - k is the end
            {
                write(1, av[1] + i - k, j - i + 1);
                write(1, "\n", 1);
                return (0);   //was too lazy to write a better way to exit the loop
            }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}