/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:50:16 by aptive            #+#    #+#             */
/*   Updated: 2022/01/21 18:43:46 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap_reverse(t_list *lst)
{
	t_list	*lst_tmp;
	int		*tmp;
	int		tmp_f_place;

	if (lst)
	{
		lst_tmp = lst;
		lst = lst->prev;
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

int	ft_rotate_reverse(t_list *lst)
{
	if (lst)
	{
		lst = ft_lstlast(lst);
		while (lst->prev)
		{
			ft_swap_reverse(lst);
			lst = lst->prev;
		}
		return (1);
	}
	return (0);
}

int	ft_rotate_reverse_a(t_list *lst)
{
	if (ft_rotate_reverse(lst))
	{
		write (1, "rra\n", 4);
		return (1);
	}
	return (0);
}

int	ft_rotate_reverse_b(t_list *lst)
{
	if (ft_rotate_reverse(lst))
	{
		write(1, "rrb\n", 4);
		return (1);
	}
	return (0);
}

int	ft_rotate_reverse_rr(t_list *lst_a, t_list *lst_b)
{
	if (ft_rotate_reverse_a(lst_a) && ft_rotate_reverse_b(lst_b))
	{
		write(1, "rrr\n", 4);
		return (1);
	}
	return (0);
}
