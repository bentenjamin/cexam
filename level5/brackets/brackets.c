/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 11:44:44 by bwebb             #+#    #+#             */
/*   Updated: 2019/08/13 12:47:23 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int brack(char *s, char c)
{
    while (s && !((s[0] == '{') || (s[0] == '[') || (s[0] == '(') || (s[0] == '}') || (s[0] == ']') || (s[0] == ')')))
        s++;
    if ((s[0] == '{') || (s[0] == '[') || (s[0] == '('))
        return (brack(s + 1, s[0]));
    if (((c == '{') && (s[0] == '}')) || ((c == '[') && (s[0] == ']')) || ((c == '(') && (s[0] == ')')))
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
        (brack(av[i++], 'x')) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);//if our bracket string is true print ye else print nah
    if (ac == 1)
        write (1, "\n", 1);
    return (0);
}