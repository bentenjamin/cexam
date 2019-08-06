/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:18:58 by bwebb             #+#    #+#             */
/*   Updated: 2019/08/06 14:15:15 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    char abc[25];//array to store boolean of the corresponding letter=index
    int i;
    int j;//counters

    i = 1;//skip out prog name
    j = 0;
    while (j < 26)
        abc[j++] = '0';//initialise the array
    while (av[i])//check all arguements. doesnt loop if there arent any
    {
        j = 0;
        if (av[i][0] == '-')//check if its a flag arguement else ignore and keep looping
            while (av[i][++j])//loop through arg string
            {
                if (av[i][j] >= 'a' && av[i][j] <= 'z')//check if its a letter
                    abc[av[i][j] - 'a'] = '1';//set representative char in array to 1
                else
                {
                    write(1, "Invalid Option\n", 15);//error exit if its not a letter
                    return (0);
                }
            }
        i++;    
    }
    if (ac < 2 || (abc['h' - 'a'] == '1'))//check if there are args or if the -h for "help" was used
    {
        write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
        return (1);
    }
    write(1, "000000", 6);//write out the useless placeholder digits cause thats what the question wants
    i = 26;//if you dont know theres 26 letters yet i dont htink you have a primanry school diploma
    while (i)
    {
        if (i % 8 == 0)//print a space every 8 digits
            write(1, " ", 1);
        write(1, &abc[i - 1], 1);//write out the array backwards cause thats what the question wants idk. i - 1 to print the correct array vals as we started at 26 not 25
        i--;
    }
    write(1, "\n", 1);
    return (0);
}