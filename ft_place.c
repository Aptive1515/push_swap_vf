/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:29:40 by tdelauna          #+#    #+#             */
/*   Updated: 2022/01/21 18:37:23 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_f_place(t_list *lst, int nb)
{
	int	place;

	place = ft_nb_place(lst);
	while (lst->prev)
		lst = lst->prev;
	while (lst->content[0] != nb && lst->next)
		lst = lst->next;
	lst->f_place = place;
	return (1);
}

int	ft_findminus_place(t_list *lst)
{
	int		min;

	min = 0;
	while (lst->next)
	{
		if (lst->f_place == 0)
			min = lst->content[0];
		lst = lst->next;
	}
	if (lst->f_place == 0)
		min = lst->content[0];
	while (lst->prev)
		lst = lst->prev;
	while (lst)
	{
		if (min > lst->content[0] && lst->f_place == 0)
			min = lst->content[0];
		lst = lst->next;
	}
	return (min);
}

int	ft_sort_place(t_list *lst)
{
	t_list	*tmp;

	while (lst->next)
	{
		tmp = lst;
		lst = lst->next;
		if (tmp->f_place > lst->f_place)
			return (0);
	}
	return (1);
}

void	ft_putplace(t_list *lst)
{
	int	minus;
	int	i;

	i = 0;
	while (i < ft_lstsize(lst))
	{
		minus = ft_findminus_place(lst);
		ft_f_place(lst, minus);
		i++;
	}
}

int	ft_nb_place(t_list *lst)
{
	int	place;

	place = 1;
	while (lst)
	{
		if (lst->f_place != 0)
			place++;
		lst = lst->next;
	}
	return (place);
}
