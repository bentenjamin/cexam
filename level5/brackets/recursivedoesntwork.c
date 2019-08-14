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
    int i;

    i = 0;
    while (s[i] && !((s[i] == '{') || (s[i] == '[') || (s[i] == '(') || (s[i] == '}') || (s[i] == ']') || (s[i] == ')')))
        i++;
    if (((s[i] == '{') || (s[i] == '[') || (s[i] == '(')))
        return (brack(s + i + 1, s[i]));
    if (((c == 'x') && !(s[i])) || ((c == '{') && (s[i] == '}')) || ((c == '[') && (s[i] == ']')) || ((c == '(') && (s[i] == ')')))
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