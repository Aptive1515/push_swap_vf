/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:52:51 by tdelauna          #+#    #+#             */
/*   Updated: 2022/01/24 15:10:24 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sortinlist(t_list *lst)
{
	t_list	*tmp;

	while (lst->next)
	{
		tmp = lst;
		lst = lst->next;
		if (tmp->content[0] > lst->content[0])
			return (0);
	}
	return (1);
}

int	ft_doubletablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_sortin2(t_list *lst, char c)
{
	t_list	*tmp;

	if (c == 'l')
		tmp = ft_lstlast(lst);
	if (c == 's')
		tmp = lst->next;
	if (lst->content[0] > tmp->content[0])
		return (0);
	return (1);
}
