/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:36:08 by tdelauna          #+#    #+#             */
/*   Updated: 2022/01/21 18:36:25 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findminus(t_list	*lst)
{
	int		min;

	min = lst->content[0];
	while (lst->next)
	{
		lst = lst->next;
		if (min > lst->content[0])
			min = lst->content[0];
	}
	return (min);
}

int	ft_find_place(t_list *lst, int nb)
{
	while (lst->next)
	{
		if (lst->f_place == nb)
			return (1);
		lst = lst->next;
	}
	if (lst->f_place == nb)
		return (1);
	return (0);
}

int	ft_find_sup(t_list *lst, int nb)
{
	while (lst)
	{
		if (lst->f_place >= nb)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	ft_find_inter(t_list *lst, int min, int max)
{
	while (lst)
	{
		if (lst->f_place >= min && lst->f_place <= max)
			return (1);
		lst = lst->next;
	}
	return (0);
}
