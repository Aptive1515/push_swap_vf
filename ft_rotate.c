/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:10:00 by aptive            #+#    #+#             */
/*   Updated: 2022/01/21 18:42:34 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			ft_swap(lst);
			lst = lst->next;
		}
		return (1);
	}
	return (0);
}

int	ft_rotate_a(t_list *lst)
{
	if (ft_rotate(lst))
	{
		write(1, "ra\n", 3);
		return (1);
	}
	return (0);
}

int	ft_rotate_b(t_list *lst)
{
	if (ft_rotate(lst))
	{
		write(1, "rb\n", 3);
		return (1);
	}
	return (0);
}

int	ft_rotate_rr(t_list *lst_a, t_list *lst_b)
{
	if (ft_rotate_a(lst_a) && ft_rotate_b(lst_b))
	{
		write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}
