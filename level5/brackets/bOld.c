/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bOld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:26:48 by bwebb             #+#    #+#             */
/*   Updated: 2019/08/13 13:27:05 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int mtch(char c, char x)
{
    if (c == '(' && x == ')')
        return (1);
    if (c == '{' && x == '}')
        return (1);
    if (c == '[' && x == ']')
        return (1);
    return (0);//im not gonna explain what this does
}

int brack(char *s)
{
    int stk[100];//our stack for pushing and popping
    int i;//counter

    i = -1;//-1 since s[++i]
    stk[0] = 0;//init stk[0] as the counter as the stack. therefore stk[stk[0]] is stack top
    while (s[++i])//run till end of string (duh)
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stk[++stk[0]] = s[i];//if bracket is valid increase stk and slap it on there
        else if (mtch(stk[stk[0]], s[i]))
            stk[0]--;//if char is valid closing bracket and it matches our stk top, push off stack
        else if ((s[i] == ')' || s[i] == ']' || s[i] == '}') && !stk[0])//not really happy how i did this cause i test if it is a valid closing bracket twice but it looks good and im too lazy to find a good alternative
            return (0);//if we have a closing bracket to an empty stk or wrong top its invalid
    if (stk[0])//if theres something in the stack then its invalid
        return (0);
    return (1);//stack is empty
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
        (brack(av[i++])) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);//if our bracket string is true print ye else print nah
    if (ac == 1)
        write (1, "\n", 1);
    return (0);
}