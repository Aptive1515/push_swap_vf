/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:46:30 by tdelauna          #+#    #+#             */
/*   Updated: 2022/01/23 19:58:43 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorthundred_two(t_list *(*tab_lst))
{
	int		j;
	int		k;
	t_algo	algo;

	j = 1;
	k = 0;
	ft_putplace(tab_lst[0]);
	ft_algo_init(&algo, tab_lst[0]);
	while (algo.pivot >= 0)
	{
		k = 0;
		while ((algo.pivot + k) != algo.pivot_prev)
		{
			ft_push_front(&algo, tab_lst);
			k++;
		}
		ft_push_max(tab_lst, algo.len_lst);
		ft_push_back(&algo, tab_lst, k);
		j++;
		algo.pivot = algo.len_lst - (algo.len_lst / algo.pourcent * j);
		algo.pivot_prev = algo.pivot + algo.len_lst / algo.pourcent;
	}
}

void	ft_push_max(t_list *(*tab_lst), int len_lst)
{
	if (ft_find_sup(tab_lst[1], len_lst))
	{
		ft_placepush_b(tab_lst[1], len_lst);
		ft_push_b(tab_lst);
	}
}

void	ft_algo_init(t_algo *algo, t_list *lst)
{
	algo->len_lst = ft_lstsize(lst);
	if (algo->len_lst > 120)
		algo->pourcent = 10;
	else
		algo->pourcent = 5;
	algo->pivot = algo->len_lst - (algo->len_lst / algo->pourcent);
	algo->pivot_prev = algo->len_lst;
}

void	ft_push_front(t_algo *algo, t_list *(*tab_lst))
{
	while (ft_find_inter(tab_lst[0], algo->pivot, algo->pivot_prev - 1))
	{
		if (tab_lst[0]->f_place >= algo->pivot
			&& tab_lst[0]->f_place < algo->pivot_prev)
			ft_push_a(tab_lst);
		else if (tab_lst[0]->f_place == algo->len_lst
			&& algo->pivot_prev == algo->len_lst)
			ft_push_a(tab_lst);
		else if (algo->pivot <= algo->len_lst)
			ft_rotate_reverse_a(tab_lst[0]);
		else
			ft_rotate_a(tab_lst[0]);
	}
}

void	ft_push_back(t_algo *algo, t_list *(*tab_lst), int k)
{
	if ((algo->pivot + k) == algo->pivot_prev)
	{
		while (k != 0 && algo->pivot + k != 0 && tab_lst[1])
		{
			ft_placepush(tab_lst[0], algo->pivot + k);
			k--;
			if (algo->pivot + k != 0 && tab_lst[1]->content)
			{
				ft_placepush_b(tab_lst[1], algo->pivot + k);
				ft_push_b(tab_lst);
			}
		}
	}
}
