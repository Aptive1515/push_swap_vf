/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:12:13 by tdelauna          #+#    #+#             */
/*   Updated: 2022/01/11 18:14:16 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*tmp;
	t_list	*first;

	tmp = new;
	first = *alst;
	if (!alst || !new)
		return ;
	tmp->next = *alst;
	*alst = tmp;
	first->prev = tmp;
}
