/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:08:53 by bwebb             #+#    #+#             */
/*   Updated: 2019/08/13 13:27:14 by bwebb            ###   ########.fr       */
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
    int offset; //offset to change bracket size of pal
    int strsize;//size of string
    int count;//counter bouncing between 0 and offset
    
    if (ac != 2 || av[1][0] == '\0')//test args and empty string
    {
        write(1, "\n", 1);
        return (0);
    }
    if (av[1][1] == '\0')//test 1 letter
        write(1, av[1], 1);
    offset = 0;
    strsize = 0;
    while (av[1][strsize + 1])
        strsize++;
    while (offset < strsize)//ensures the bracket size will always be at least 2
    {
        count = -1;//count goes between 0 and offset to move the checking size(strsize - offset) from the end to the beginning
        while (++count <= offset)//finds the largest pallindrone starting from the back
            if (ispal(av[1], offset - count, strsize - count))//tests if it is a pallindrome. offset - count is the start of our bracket, strsize - count is the end
            {
                write(1, av[1] + offset - count, strsize - offset + 1);
                write(1, "\n", 1);
                return (0);   //was too lazy to write a better way to exit the loop
            }
        offset++;
    }
    write(1, "\n", 1);
    return (0);
}