/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:00:02 by tdelauna          #+#    #+#             */
/*   Updated: 2022/01/21 19:30:19 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort(t_list *(*tab_lst))
{
	int	lst_size;

	lst_size = ft_lstsize(tab_lst[0]);
	if (lst_size == 2)
		ft_sorttwo(tab_lst[0]);
	else if (lst_size == 3)
		ft_sortthree(tab_lst);
	else if (lst_size == 4)
		ft_sortfour(tab_lst);
	else if (lst_size == 5)
		ft_sortfive(tab_lst);
	else
		ft_sorthundred_two(tab_lst);
	return (1);
}

void	ft_sorttwo(t_list *lst)
{
	if (!ft_sortinlist(lst))
		ft_swap_a(lst);
}

void	ft_sortthree(t_list *(*tab_lst))
{
	while (!ft_sortinlist(tab_lst[0]))
	{
		if (!ft_sortin2(tab_lst[0], 'l') && !ft_sortin2(tab_lst[0], 's'))
			ft_rotate_a(tab_lst[0]);
		else if (!ft_sortin2(tab_lst[0], 'l') && ft_sortin2(tab_lst[0], 's'))
			ft_rotate_reverse_a(tab_lst[0]);
		else if (!ft_sortin2(tab_lst[0], 's'))
			ft_swap_a(tab_lst[0]);
		else
			ft_rotate_reverse_a(tab_lst[0]);
	}
}

void	ft_sortfour(t_list *(*tab_lst))
{
	ft_minuspush(tab_lst[0]);
	if (!ft_sortinlist(tab_lst[0]))
	{
		ft_push_a(tab_lst);
		ft_sortthree(tab_lst);
		ft_push_b(tab_lst);
	}
}

void	ft_sortfive(t_list *(*tab_lst))
{
	ft_minuspush(tab_lst[0]);
	ft_push_a(tab_lst);
	ft_minuspush(tab_lst[0]);
	ft_push_a(tab_lst);
	ft_sortthree(tab_lst);
	ft_push_b(tab_lst);
	ft_push_b(tab_lst);
}
