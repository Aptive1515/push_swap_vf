/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:29:03 by tdelauna          #+#    #+#             */
/*   Updated: 2022/01/21 19:30:33 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lestrotate(t_list *lst, int nb)
{
	int	nb_rotate;
	int	nb_rev;

	nb_rotate = 0;
	nb_rev = 0;
	while (nb != lst->content[0])
	{
		nb_rotate++;
		lst = lst->next;
	}
	lst = ft_lstlast(lst);
	while (nb != lst->content[0])
	{
		nb_rev++;
		lst = lst->prev;
	}
	nb_rev++;
	if (nb_rotate <= nb_rev)
		return (nb_rotate);
	else
		return (-nb_rev);
}

int	ft_lestrotate_place(t_list *lst, int nb)
{
	int	nb_rotate;
	int	nb_rev;

	nb_rotate = 0;
	nb_rev = 0;
	while (nb != lst->f_place)
	{
		nb_rotate++;
		lst = lst->next;
	}
	lst = ft_lstlast(lst);
	while (nb != lst->f_place)
	{
		nb_rev++;
		lst = lst->prev;
	}
	nb_rev++;
	if (nb_rotate <= nb_rev)
		return (nb_rotate);
	else
		return (-nb_rev);
}

int	ft_placepush(t_list *lst, int nb)
{
	int	move;
	int	rotation;

	move = 0;
	rotation = ft_lestrotate_place(lst, nb);
	if (rotation > 0)
	{
		while (rotation > 0)
		{
			move += ft_rotate_a(lst);
			rotation--;
		}
	}
	else
	{
		while (rotation < 0)
		{
			move += ft_rotate_reverse_a(lst);
			rotation++;
		}
	}
	return (move);
}

int	ft_placepush_b(t_list *lst, int nb)
{
	int	move;
	int	rotation;

	move = 0;
	rotation = ft_lestrotate_place(lst, nb);
	if (rotation > 0)
	{
		while (rotation > 0)
		{
			move += ft_rotate_b(lst);
			rotation--;
		}
	}
	else
	{
		while (rotation < 0)
		{
			move += ft_rotate_reverse_b(lst);
			rotation++;
		}
	}
	return (move);
}

int	ft_minuspush(t_list *lst)
{
	int	move;
	int	rotation;

	move = 0;
	rotation = ft_lestrotate(lst, ft_findminus(lst));
	if (rotation > 0)
	{
		while (rotation > 0)
		{
			move += ft_rotate_a(lst);
			rotation--;
		}
	}
	else
	{
		while (rotation < 0)
		{
			move += ft_rotate_reverse_a(lst);
			rotation++;
		}
	}
	return (move);
}
