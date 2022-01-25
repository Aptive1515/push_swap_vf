/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:22:25 by aptive            #+#    #+#             */
/*   Updated: 2022/01/21 18:44:29 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list *lst)
{
	t_list	*lst_tmp;
	int		*tmp;
	int		tmp_f_place;

	if (lst)
	{
		lst_tmp = lst;
		lst = lst->next;
		tmp = lst->content;
		tmp_f_place = lst->f_place;
		lst->content = lst_tmp->content;
		lst->f_place = lst_tmp->f_place;
		lst = lst_tmp;
		lst->content = tmp;
		lst->f_place = tmp_f_place;
		return (1);
	}
	return (0);
}

int	ft_swap_a(t_list *lst)
{
	if (ft_swap(lst))
	{
		write(1, "sa\n", 3);
		return (1);
	}
	return (0);
}

int	ft_swap_b(t_list *lst)
{
	if (ft_swap(lst))
	{
		write(1, "sb\n", 3);
		return (1);
	}
	return (0);
}

int	ft_swap_ss(t_list *lst_a, t_list *lst_b)
{
	if (ft_swap_a(lst_a) && ft_swap_b(lst_b))
	{
		write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}
