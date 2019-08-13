/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwebb <bwebb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:26:11 by bwebb             #+#    #+#             */
/*   Updated: 2019/08/13 13:27:07 by bwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int        cycle_detector(const t_list *list)
{
    const t_list *slow;//const to match input
    const t_list *fast;

    if (!list)//if no input return
        return (0);
    slow = list;//both start at beginning of list
    fast = list;
    while (fast && fast->next)//if it hits the end, need next cause fast jumps twice
    {
        slow = slow->next;//increment by one
        fast = fast->next->next;//increment by 2
        if (slow == fast)//if it loops fast will run into slow 
            return (1);
    }
    return (0);
}