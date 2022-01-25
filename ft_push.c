/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 12:59:05 by tdelauna          #+#    #+#             */
/*   Updated: 2022/01/24 15:12:58 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list *(*tab_lst))
{
	t_list	*lst_tmp;

	if (!tab_lst[1])
	{
		tab_lst[1] = tab_lst[0];
		tab_lst[0] = tab_lst[0]->next;
		tab_lst[0]->prev = NULL;
		tab_lst[1]->next = NULL;
	}
	else if (tab_lst[1] && ft_lstsize(tab_lst[0]) > 1)
	{
		lst_tmp = tab_lst[0]->next;
		tab_lst[1]->prev = tab_lst[0];
		tab_lst[0]->next = tab_lst[1];
		tab_lst[1] = tab_lst[1]->prev;
		tab_lst[0] = lst_tmp;
		tab_lst[0]->prev = NULL;
	}
	else if (tab_lst[1] && ft_lstsize(tab_lst[0]) == 1)
	{
		tab_lst[1]->prev = tab_lst[0];
		tab_lst[0]->next = tab_lst[1];
		tab_lst[1] = tab_lst[0];
		tab_lst[0] = NULL;
	}
}

int	ft_push_a(t_list *(*tab_lst))
{
	ft_push(tab_lst);
	write(1, "pb\n", 3);
	return (1);
}

int	ft_push_b(t_list *(*tab_lst))
{
	ft_invers_lsttab(tab_lst);
	ft_push(tab_lst);
	write(1, "pa\n", 3);
	ft_invers_lsttab(tab_lst);
	return (1);
}

void	ft_invers_lsttab(t_list *(*tab_lst))
{
	t_list	*tmp;

	tmp = tab_lst[0];
	tab_lst[0] = tab_lst[1];
	tab_lst[1] = tmp;
}

void	ft_delfirst(t_list *lst)
{
	if (lst)
	{
		ft_rotate(lst);
		lst = ft_lstlast(lst);
		lst->content = NULL;
		lst = lst->prev;
		if (lst)
			lst->next = NULL;
	}
}
